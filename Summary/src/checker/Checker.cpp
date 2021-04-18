#include <iostream>
#include "Checker.h"

Checker::Checker()
{

}

void Checker::add_head_message(const std::string& msg)
{
	head_message_list.push_back(msg);
}
void Checker::print_head_result()
{
	for(auto it = head_message_list.begin(); it != head_message_list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

std::list<std::string> Checker::get_head_messages()
{
	return head_message_list;
}
