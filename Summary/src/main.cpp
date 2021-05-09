#include <string>
#include <../libs/pdftron/PDF/PDFNet.h>

#include "../libs/tclap/CmdLine.h"

#include "Parser.h"

using namespace pdftron;
using namespace TCLAP;

int main(int argc, char* argv[])
{
	int ret = 0;
	Parser parser;
	try
	{
		CmdLine cmd("Command description message", ' ', "1.0");
		ValueArg<std::string> lab_name("l", "lab", "Name of lab file", true, "homer", "string");
		cmd.add(lab_name);
		ValueArg<std::string> rules_name("r", "rule", "Name of rule file", true, "homer", "string");
		cmd.add(rules_name);

		cmd.parse(argc, argv);

		std::string input_path = lab_name.getValue();
		std::string rule_path = rules_name.getValue();
		std::cout << rule_path << std::endl;
		parser = Parser(input_path, rule_path);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		ret = 1;
	}

	try
	{
		PDFNet::Initialize();
		parser.parse();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		ret = 1;
	}
	catch (...)
	{
		std::cout << "Unknown Exception" << std::endl;
		ret = 2;
	}
}

// g++ main.cpp -I../libs -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp