#ifndef SUMMARY_WORK_PARSER_H
#define SUMMARY_WORK_PARSER_H

#include <string>
#include "../settings/Settings.h"
#include "../checker/Checker.h"
#include <../libs/pdftron/PDF/TextExtractor.h>

using namespace pdftron;
using namespace PDF;

class Parser
{
public:
	Parser(const std::string& input_path);

	int parse();
	Checker get_checker_info();

private:
	std::string lab_name;
	Settings set;
	Checker checker;
	void check_headers(const std::string& head);
	std::string parse_headers(TextExtractor::Line& line, TextExtractor::Style& line_style);
};

#endif //SUMMARY_WORK_PARSER_H
