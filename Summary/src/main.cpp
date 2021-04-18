#include <iostream>
#include <string>
#include <../libs/pdftron/PDF/PDFNet.h>

#include "parser/Parser.h"

using namespace pdftron;
using namespace PDF;

int main(int argc, char* argv[])
{
	PDFNet::Initialize();
    int ret {0};
//    if (argc > 1)
//    {
//	    for(int i = 1; i < argc; ++i)
//	    {
//		    ret = 0;
//		    run_all(argv[i], ret);
//		    std::cout << std::endl;
//	    }
//    }
//    else
//    {
    std::string input_path { "/home/alex/CLionProjects/SummaryWork/Summary/resources/lab18.pdf" };
    Parser parser(input_path);
    parser.parse();
//    }
	PDFNet::Terminate();
	auto set = Settings("hjd");
    return ret;
}

// g++ main.cpp -I../libs -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp