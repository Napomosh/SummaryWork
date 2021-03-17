#include <iostream>
#include <string>

#include <../libs/pdftron/PDF/PDFNet.h>

#include "../headers/example.h"

using namespace pdftron;
using namespace PDF;


int main(int argc, char* argv[])
{
	PDFNet::Initialize();
    int ret {0};
    if (argc > 1)
    {
	    for(int i = 1; i < argc; ++i)
	    {
		    ret = 0;
		    run_all(argv[i], ret);
		    std::cout << std::endl;
	    }
    }
    else
    {
	    string input_path { "../resources/lab7.pdf" };
	    run_all(input_path, ret);
    }

	PDFNet::Terminate();
    return ret;
}

// g++ main.cpp -I../libs -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp