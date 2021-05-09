#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Parser.h"

#include <../libs/pdftron/PDF/PDFNet.h>

using namespace pdftron;

TEST_CASE("Check lab7.pdf") {
	PDFNet::Initialize();
	std::string input_path { "../../resources/lab7.pdf" };
	Parser parser =  Parser(input_path, "../../test/json_file.json");
	CHECK_EQ(parser.parse(), parser.SUCCESS);
}

TEST_CASE("Check lab19.pdf")
{
	std::string input_path{"../../resources/lab19.pdf"};
	Parser parser = Parser(input_path, "../../test/json_file.json");
	CHECK_EQ(parser.parse(), parser.SUCCESS);
}

TEST_CASE("Check lab20.pdf")
{
	std::string input_path{"../../resources/lab20.pdf"};
	Parser parser = Parser(input_path, "../../test/json_file.json");
	CHECK_EQ(parser.parse(), parser.SUCCESS);
}

TEST_CASE("Check lab21.pdf")
{
	std::string input_path{"../../resources/lab21.pdf"};
	Parser parser = Parser(input_path, "../../test/json_file.json");
	CHECK_EQ(parser.parse(), parser.SUCCESS);
}

TEST_CASE("Check kurs.pdf")
{
	std::string input_path{"../../resources/e.pdf"};
	Parser parser = Parser(input_path, "../../resources/rule_for_kurs.json");
	CHECK_EQ(parser.parse(), parser.SUCCESS);
}

TEST_CASE("Check lab18.pdf") {
	std::string input_path { "../../resources/lab18.pdf" };
	Parser parser =  Parser(input_path, "../../test/json_file.json");
	CHECK_EQ(parser.parse(), parser.SUCCESS);
	PDFNet::Terminate();
}