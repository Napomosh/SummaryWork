#include <iostream>
#include <string>
#include <../libs/pdftron/PDF/PDFNet.h>

#include "parser/Parser.h"

using namespace pdftron;
using namespace PDF;

int main(int argc, char* argv[])
{
	int ret = 0;
	Parser parser;
	PDFNet::Initialize();
	if (argc > 1)
	{
	    for(int i = 1; i < argc; ++i)
	    {
	    	parser.set_file(argv[i]);
	    }
	}
	else
	{
		std::string input_path { "../resources/lab7.pdf" };
		parser =  Parser(input_path);
	}
	try
	{
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