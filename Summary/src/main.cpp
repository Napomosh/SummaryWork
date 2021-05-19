#include <string>
#include <../libs/pdftron/PDF/PDFNet.h>

#include "../libs/tclap/CmdLine.h"

#include "Parser.h"

using namespace pdftron;
using namespace TCLAP;

int main(int argc, char* argv[])
{
	CmdLine cmd("Command description message", ' ', "1.0");
	ValueArg<std::string> lab_name("l", "lab", "Name of lab file", true, "homer", "string");
	cmd.add(lab_name);
	ValueArg<std::string> rules_name("r", "rule", "Name of rule file", true, "homer", "string");
	cmd.add(rules_name);
	ValueArg<std::string> sources_name("s", "source", "Name of source code file", true, "homer", "string");
	cmd.add(sources_name);

	cmd.parse(argc, argv);

	std::string input_path = lab_name.getValue();
	std::string rule_path = rules_name.getValue();
	std::string sources_path = sources_name.getValue();
	std::string cppcheck_command = "clang-format --dry-run " + sources_path + " >result.txt 2>&1";
	system(cppcheck_command.c_str());

	Parser parser;
	parser = Parser(input_path, rule_path);
	PDFNet::Initialize();
	parser.parse();
	PDFNet::Terminate();

	return 0;
}