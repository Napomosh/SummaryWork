#ifndef SUMMARY_WORK_CHECKER_H
#define SUMMARY_WORK_CHECKER_H

#include <string>
#include <list>

class Checker
{
public:
	Checker();
	void add_head_message(const std::string& msg);
	void print_head_result();
	std::list<std::string> get_head_messages();
private:
	std::list<std::string> head_message_list;
};

#endif //SUMMARY_WORK_CHECKER_H
