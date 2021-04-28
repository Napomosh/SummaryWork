#include <iostream>
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
		// Define the command line object.
		CmdLine cmd("Command description message", ' ', "1.0");

		// Define a value argument and add it to the command line.
		ValueArg<std::string> lab_name("l","lab","Name of lab file",true,"homer","string");
		cmd.add( lab_name );

		// Define a switch and add it to the command line.
		ValueArg<std::string> rules_name("r","rule","Name of rule file",true,"homer","string");
		cmd.add( rules_name );

		// Parse the args.
		cmd.parse( argc, argv );

		// Get the value parsed by each arg. 
		std::string input_path = lab_name.getValue();
		std::string rule_path = rules_name.getValue();
		parser = Parser(input_path, rule_path);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		ret = 1;
	}
	
	// if (argc > 1)
	// {
	//     for(int i = 1; i < argc; ++i)
	//     {
	//     	parser.set_file(argv[i]);
	//     }
	// }
	// else
	// {
	// 	std::string input_path { "../resources/lab7.pdf" };
	// 	parser =  Parser(input_path);
	// }
	try
	{
		PDFNet::Initialize();
    	parser.parse();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		ret = 1;
	}
	catch (...)
	{
		std::cout << "Unknown Exception" << std::endl;
		ret = 2;
	}
	PDFNet::Terminate();
	return ret;
}

// g++ main.cpp -I../libs -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp