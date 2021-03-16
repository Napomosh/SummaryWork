#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>

#include "Project/example.h"

using namespace pdftron;
using namespace PDF;
using namespace std;

using json = nlohmann::json;

json read_json(const string& file_name)
{
    std::ifstream json_file(file_name);
    json j;
    json_file >> j;
    json_file.close();

    return j;
}