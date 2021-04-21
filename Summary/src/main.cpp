#include <iostream>
#include <string>
#include <../libs/pdftron/PDF/PDFNet.h>

#include "parser/Parser.h"

using namespace pdftron;
using namespace PDF;

int main(int argc, char* argv[])
{
	PDFNet::Initialize();
	if (argc > 1)
	{
		Parser parser;
	    for(int i = 1; i < argc; ++i)
	    {
	    	parser.set_file(argv[i]);
		    parser.parse();
		    std::cout << std::endl;
	    }
	}
	else
	{
		std::string input_path { "../resources/lab7.pdf" };
		Parser parser(input_path);
		parser.parse();
	}
	PDFNet::Terminate();
	return 0;
}

// g++ main.cpp -I../libs -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp