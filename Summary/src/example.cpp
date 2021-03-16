#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>

#include "../headers/example.h"

using json = nlohmann::json;

json read_json(const std::string& file_name)
{
    std::ifstream json_file(file_name);
    json j;
    json_file >> j;
    json_file.close();

    return j;
}