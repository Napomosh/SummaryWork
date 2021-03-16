#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

#include </home/alex/CLionProjects/SummaryWork/Summary/libs/pdftron/PDF/TextExtractor.h>
#include <string>

#include <nlohmann/json.hpp>

using namespace pdftron;
using namespace PDF;
using namespace std;

using json = nlohmann::json;


json read_json(const string& file_name);

#endif //  _EXAMPLE_H_