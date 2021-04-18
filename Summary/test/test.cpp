#include "gtest/gtest.h"
#include "../src/parser/Parser.h"

#include <string>
#include <list>

TEST( TestHeaders, Test_parse )
{
	std::list<std::string> expected {"Найден заголовок: Задание", "Найден заголовок: Тестирование", "Не найден заголовок: Инструкция пользователя"};
	std::string input_path { "../resources/lab18.pdf" };
	Parser parser(input_path);
	parser.parse();
	auto info = parser.get_checker_info().get_head_messages();
	auto it1 = expected.begin();
	for(auto it = info.begin(); it != info.end() && it1 != expected.end(); ++it)
	{
		ASSERT_EQ(*it, *it1);
		++it1;
	}
}


int main( int argc, char **argv )
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}