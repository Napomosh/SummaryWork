#include "FilesChecker.h"

#include <fstream>
#include <filesystem>
#include <iostream>

FilesChecker::FilesChecker(const std::string& dir_path)
{
	this->dir_path = dir_path;
}

void FilesChecker::check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker)
{
	for (const auto& item : std::filesystem::directory_iterator(dir_path))
	{
		files_num++;
		std::string file = item.path().string();
		if(file.substr(file.size() - 4, 4) == ".cpp")
		{
			sources_file++;
			check_function_style(file, set, checker);
		}
		else if(file.substr(file.size() - 2, 2) == ".h")
		{
			head_file++;
		}
		else
		{
			checker.add_files_message("В директории с работой присутствуют файлы не относящиеся к исходному коду: " + file);
		}
	}
	if(set.additional_options.compare_headers_source)
	{
		if(sources_file - 1 != head_file)
		{
			checker.add_files_message("Несоответствие заголовочных файлов и файлов с исходным кодом");
		}
	}
}

void FilesChecker::check_function_style(const std::string& file, Settings& set, Result &checker)
{
	std::ifstream istream;
	istream.open(file);
	std::string str;

	if(istream.is_open())
	{
		for(istream >> str; !istream.eof(); str = istream.get())
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
			else if (str == "\n")
			{
				num_lines++;
			}
			if (open_brackets == close_brackets && open_brackets > 0 && close_brackets > 0)
			{
				open_brackets = 0;
				close_brackets = 0;
				functions_num++;
				if(set.additional_options.lines_in_fun > 0 && num_lines != set.additional_options.lines_in_fun)
				{
					num_incorrect_fun++;
				}
				num_lines = 0;
			}

		}
	}
//	std::cout << file << "      " << functions_num << std::endl;
	istream.close();
	if(set.additional_options.fun_in_file != functions_num && set.additional_options.fun_in_file > 0)
	{
		checker.add_files_message("В файле " + file + " неверное количество функций");
	}
	if(num_incorrect_fun > 0)
	{
		checker.add_files_message("В файле " + file + " есть " + std::to_string(num_incorrect_fun) + " функции с неверным количесвто строк");
	}
	functions_num = 0;
	num_incorrect_fun = 0;
	num_lines = 0;
	open_brackets = 0;
	close_brackets = 0;
}

int FilesChecker::get_num_command() const
{
	return num_command;
}

int FilesChecker::get_functions_num() const
{
	return functions_num;
}


