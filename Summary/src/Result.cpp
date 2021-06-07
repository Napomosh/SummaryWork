#include <iostream>
#include <fstream>
#include "Result.h"

Result::Result() : tests(0)
{

}

void Result::add_head_message(const std::string& msg)
{
	head_message_list.push_back(msg);
}

void Result::add_style_message(const std::string& msg)
{
	style_message_list.push_back(msg);
}

void Result::add_test_message(const std::string& msg)
{
	test_message_list.push_back(msg);
}

void Result::print_head_result()
{
	for(auto& it : head_message_list)
	{
		std::cout << it << std::endl;
	}
}

std::list<std::string> Result::get_head_messages()
{
	return head_message_list;
}

std::list<std::string> Result::get_test_messages()
{
	return test_message_list;
}

std::list<std::string> Result::get_style_messages()
{
	return style_message_list;
}

void Result::save_tests_count(int value)
{
	tests = value;
}

void Result::inc_tests_value(int value)
{
	tests += value;
}

void Result::print_tests_count()
{
	std::cout << tests << std::endl;
}

void Result::print_results()
{
	print_head_result();
	print_style_result();
	print_tableofcontent_result();
	print_title_result();
}

void Result::print_style_result()
{
	for(auto& it : style_message_list)
	{
		std::cout << it << std::endl;
	}
}

void Result::add_tableofcontent_result(const std::string &msg)
{
	tableofcontent_list.push_back(msg);
}

void Result::print_tableofcontent_result()
{
	for(auto& it : tableofcontent_list)
	{
		std::cout << it << std::endl;
	}
}

void Result::add_title_message(const std::string &msg)
{
	title_list.push_back(msg);
}
void Result::add_files_message(const std::string &msg)
{
	files_list.push_back(msg);
}

void Result::print_title_result()
{
	for(auto& it : title_list)
	{
		std::cout << it << std::endl;
	}
}

void Result::write_result_in_file(const std::string& file)
{
	std::ofstream file_stream;
	file_stream.open(file);
	if(file_stream.is_open())
	{
		write_headers_in_file(file_stream);
		file_stream << " \n -----------------------------------------------------------------------" << "\n";
		write_style_in_file(file_stream);
		file_stream << "\n-----------------------------------------------------------------------" << "\n";
		write_test_in_file(file_stream);
		file_stream << "\n-----------------------------------------------------------------------" << "\n";
		write_tableofcontent_in_file(file_stream);
		file_stream << "\n-----------------------------------------------------------------------" << "\n";
		write_title_in_file(file_stream);
		file_stream << "\n-----------------------------------------------------------------------" << "\n";
		write_files_in_file(file_stream);
	}
	file_stream.close();
}

void Result::write_headers_in_file(std::ofstream& out)
{
	for(auto& item : head_message_list)
	{
		out << item << "\n";
	}
}

void Result::write_style_in_file(std::ofstream& out)
{
	for(auto& item : style_message_list)
	{
		out << item << "\n";
	}
}

void Result::write_tableofcontent_in_file(std::ofstream &out)
{
	for(auto& item : tableofcontent_list)
	{
		out << item << "\n";
	}
}

void Result::write_title_in_file(std::ofstream &out)
{
	for(auto& item : title_list)
	{
		out << item << "\n";
	}
}

void Result::write_files_in_file(std::ofstream &out)
{
	for(auto& item : files_list)
	{
		out << item << "\n";
	}
}

void Result::write_test_in_file(std::ofstream &out)
{
	for(auto& item : test_message_list)
	{
		out << item << "\n";
	}
}


