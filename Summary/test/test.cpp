#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Parser.h"

#include <../libs/pdftron/PDF/PDFNet.h>

using namespace pdftron;

TEST_CASE("Check header rules 1") {
	PDFNet::Initialize();
	std::string input_path { "../../resources/lab7.pdf" };
	Parser parser =  Parser(input_path, "../../resources/json_file.json");
	Checker checker = parser.parse();
	PDFNet::Terminate();

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
}

TEST_CASE("Check style rules 1") {
	PDFNet::Initialize();
	std::string input_path { "../../resources/lab7.pdf" };
	Parser parser =  Parser(input_path, "../../resources/json_file.json");
	Checker checker = parser.parse();
	PDFNet::Terminate();

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
}