#include "Parser.h"
#include "Settings.h"
#include "HeadChecker.h"
#include "StyleChecker.h"
#include "TestChecker.h"
#include "TableOfContentChecker.h"
#include "PicturesChecker.h"
#include "TitleChecker.h"

#include <iostream>
#include <string>

#include <pdftron/PDF/PDFDoc.h>
#include <pdftron/PDF/TextExtractor.h>

using namespace pdftron;
using namespace PDF;

Parser::Parser(const std::string& input_path, const std::string& rule_path) : set(Settings(rule_path)), tests(0)
{
	lab_name = input_path;
}
Parser::Parser() : set(Settings()), tests(0)
{
	lab_name = "none";
}

int Parser::parse()
{
	if (lab_name == "none")
	{
		return LAB_FILE_NOT_DEFINEDED;
	}
	PDFDoc doc(lab_name);
	doc.InitSecurityHandler();
	Page page;
	HeadChecker header_checker;
	StyleChecker style_checker;
	TestChecker test_checker;
	TableOfContentChecker table_of_content_checker;
	PicturesChecker pict_checker;
	TitleChecker title_checker;

	for (int i = 1; (page = doc.GetPage(i)) != 0; i++)
	{
		if (!page)
		{
			std::cout << "Page not found." << std::endl;
			continue;
		}
		if (i == 1)
		{
			title_checker.check_rule(page, set, checker);
			continue;
		}

		if (i == 2 && set.additional_options.table_of_contents)
		{
			table_of_content_checker.check_rule(page, set, checker);
		}

		header_checker.check_rule(page, set, checker);
		style_checker.check_rule(page, set, checker);

		if (set.additional_options.pictures_check)
		{
			pict_checker.check_rule(page, set, checker);
		}
		if(set.get_is_test_found())
		{
			test_checker.check_rule(page, set, checker);
		}
	}
	header_checker.get_result(set, checker);
	pict_checker.check();
	auto result = get_checker_info();
	
	return SUCCESS;
}

void Parser::set_file(const std::string& new_file)
{
	lab_name = new_file;
	tests = 0;
}

void Parser::set_rule_file(const std::string& new_file)
{
	set = Settings(new_file);
}

Result Parser::get_checker_info()
{
	return checker;
}
