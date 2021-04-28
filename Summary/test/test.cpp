#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Parser.h"

#include <../libs/pdftron/PDF/PDFNet.h>

using namespace pdftron;

TEST_CASE("Check lab7.pdf") {
	PDFNet::Initialize();
	std::string input_path { "../../resources/lab7.pdf" };
	Parser parser =  Parser(input_path, "../../test/json_file.json");
	Checker checker = parser.parse();

	auto messages = checker.get_head_messages();
	std::list<std::string> expected { "Найден заголовок: Задание", "Найден заголовок: Инструкция пользователя", "Найден заголовок: Тестирование" };
	auto it_expected = expected.begin();
	int exp_size = expected.size();

	CHECK(messages.size() == exp_size);	
	for(auto it = messages.begin(); it != messages.end(); ++it)
	{
		CHECK(*it == *it_expected);
		++it_expected;
	}

	messages = checker.get_style_messages();
	CHECK(messages.size() == 15);

	messages = checker.get_test_messages();
	expected = { "Тест номер: 1 найден.", "Тест номер: 2 найден.", "Тест номер: 3 найден." };
	it_expected = expected.begin();
	exp_size = expected.size();

	CHECK(messages.size() == exp_size);	
	for(auto it = messages.begin(); it != messages.end(); ++it)
	{
		CHECK(*it == *it_expected);
		++it_expected;
	}	

	PDFNet::Terminate();
}

// TEST_CASE("Check style rules 1") {
// 	std::string input_path { "../../resources/lab7.pdf" };
// 	Parser parser =  Parser(input_path, "../../test/json_file.json");
// 	Checker checker = parser.parse();

// 	auto messages = checker.get_style_messages();
// 	CHECK(messages.size() == 15);	

// 	// PDFNet::Terminate();
// }

// TEST_CASE("Check test rules 1") {
// 	std::string input_path { "../../resources/lab7.pdf" };
// 	Parser parser =  Parser(input_path, "../../test/json_file.json");
// 	Checker checker = parser.parse();

// 	auto messages = checker.get_test_messages();
// 	std::list<std::string> expected { "Тест номер: 1 найден.", "Тест номер: 2 найден.", "Тест номер: 3 найден." };
// 	auto it_expected = expected.begin();
// 	int exp_size = expected.size();

// 	CHECK(messages.size() == exp_size);	
// 	for(auto it = messages.begin(); it != messages.end(); ++it)
// 	{
// 		CHECK(*it == *it_expected);
// 		++it_expected;
// 	}	

// 	PDFNet::Terminate();
// }