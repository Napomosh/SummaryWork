#ifndef SUMMARY_WORK_RESULT_H
#define SUMMARY_WORK_RESULT_H

#include <string>
#include <list>

class Result
{
public:
	Result();

	void add_head_message(const std::string& msg);
	void add_style_message(const std::string& msg);
	void add_tableofcontent_result(const std::string& msg);
	void add_test_message(const std::string& msg);
	void add_title_message(const std::string& msg);
	void add_files_message(const std::string& msg);

	void print_head_result();
//	void print_head_result();
	void print_style_result();
	void print_tableofcontent_result();
	void print_title_result();

	std::list<std::string> get_head_messages();
	std::list<std::string> get_style_messages();
	std::list<std::string> get_test_messages();

	void save_tests_count(int value);
	void inc_tests_value(int value);
	void print_tests_count();

	void print_results();
	void write_result_in_file(const std::string& file);
private:
	std::list<std::string> head_message_list;
	std::list<std::string> style_message_list;
	std::list<std::string> tableofcontent_list;
	std::list<std::string> test_message_list;
	std::list<std::string> title_list;
	std::list<std::string> files_list;
	int tests;

	void write_headers_in_file(std::ofstream& out);
	void write_files_in_file(std::ofstream& out);
	void write_style_in_file(std::ofstream& out);
	void write_tableofcontent_in_file(std::ofstream& out);
	void write_title_in_file(std::ofstream& out);
	void write_test_in_file(std::ofstream& out);
};

#endif //SUMMARY_WORK_RESULT_H
