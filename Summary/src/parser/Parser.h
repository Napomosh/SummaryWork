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
	Parser();

	int parse();
	void set_file(const std::string& new_file);
	Checker get_checker_info();

private:
	int tests;
	std::string lab_name;
	Settings set;
	Checker checker;
	void check_headers(const std::string& head, TextExtractor::Line& line);
	std::string parse_headers(TextExtractor::Line& line, TextExtractor::Style& line_style);
};

#endif //SUMMARY_WORK_PARSER_H
