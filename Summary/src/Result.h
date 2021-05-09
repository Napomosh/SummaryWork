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
	void add_test_message(const std::string& msg);

	void print_head_result();

	std::list<std::string> get_head_messages();
	std::list<std::string> get_style_messages();
	std::list<std::string> get_test_messages();

	void save_tests_count(int value);
	void inc_tests_value(int value);
	void print_tests_count();
private:
	std::list<std::string> head_message_list;
	std::list<std::string> style_message_list;
	std::list<std::string> test_message_list;
	int tests;
};

#endif //SUMMARY_WORK_RESULT_H
