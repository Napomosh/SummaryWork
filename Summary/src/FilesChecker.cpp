#include "FilesChecker.h"

#include <fstream>
#include <filesystem>
#include <iostream>

FilesChecker::FilesChecker()
{

}

void FilesChecker::check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker)
{
	std::string file = "/home/alex/CLionProjects/SummaryWork/Summary/src/Parser.cpp";
	check_function_style(file);
	check_files();
}

void FilesChecker::check_function_style(const std::string& file)
{
	std::ifstream istream;
	istream.open(file);
	std::string str;

	if(istream.is_open())
	{
		for(istream >> str; !istream.eof(); istream >> str)
		{
			if (str == "{")
			{
				open_brackets++;
			}
			else if (str == "}")
			{
				close_brackets++;
			}
			else if (str == ";")
			{
				num_command++;
			}
			if (open_brackets == close_brackets && open_brackets > 0 && close_brackets > 0)
			{
				open_brackets = 0;
				close_brackets = 0;
				functions_num++;
			}
		}
	}
	istream.close();
}

void FilesChecker::check_files()
{
	for (const auto& item : std::filesystem::directory_iterator("../../src"))
	{
		files_num++;
	}
}

int FilesChecker::get_num_command() const
{
	return num_command;
}

int FilesChecker::get_functions_num() const
{
	return functions_num;
}


