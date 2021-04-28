#include "Parser.h"
#include "Settings.h"
#include "HeadChecker.h"
#include "StyleChecker.h"
#include "TestChecker.h"

#include <iostream>
#include <map>
#include <string>

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/PDFDoc.h>
#include <pdftron/PDF/TextExtractor.h>

using namespace pdftron;
using namespace PDF;

Parser::Parser(const std::string& input_path) : set(Settings("../resources/json_file.json")), tests(0)
{
	lab_name = input_path;
}
Parser::Parser(const std::string& input_path, const std::string& rule_path) : set(Settings(rule_path)), tests(0)
{
	lab_name = input_path;
}
Parser::Parser() : set(Settings("../resources/json_file.json")), tests(0)
{
	lab_name = "none";
}

Checker Parser::parse()
{
	if (lab_name == "none")
	{
		
	}
	PDFDoc doc(lab_name);
	doc.InitSecurityHandler();
	Page page;
	int begin_page = 2;
	HeadChecker header_checker;
	StyleChecker style_checker;
	TestChecker test_checker;

	for (int i = begin_page; (page = doc.GetPage(i)) != 0; i++)
	{
		// std::cout << page.Box.e_media << std::endl;
		if (!page)
		{
			std::cout << "Page not found." << std::endl;
			continue;
		}

		header_checker.check_rule(page, set, checker);
		style_checker.check_rule(page, set, checker);
		if(set.get_is_test_found())
		{
			test_checker.check_rule(page, set, checker);
		}
	}

	header_checker.get_result(set, checker);
	auto result = get_checker_info();
	std::cout << result.get_style_messages().size() << std::endl;
	
	// checker.print_head_result();
	// checker.print_tests_count();
	return checker;
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

Checker Parser::get_checker_info()
{
	return checker;
}
