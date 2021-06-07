#ifndef SUMMARY_WORK_PARSER_H
#define SUMMARY_WORK_PARSER_H

#include <string>
#include "Settings.h"
#include "Result.h"
#include <pdftron/PDF/TextExtractor.h>

class Parser
{
public:
	Parser(const std::string& input_path, const std::string& rule_path,  const std::string& dir_path);
	Parser();

	int parse();
	void set_rule_file(const std::string& new_file);
	void set_file(const std::string& new_file);
	Result get_checker_info();

	enum
	{
		SUCCESS = 0,
		LAB_FILE_NOT_DEFINEDED = 1
	};
private:
	int tests;
	std::string lab_name;
	std::string dir_path;
	Settings set;
	Result checker;
};

#endif //SUMMARY_WORK_PARSER_H
