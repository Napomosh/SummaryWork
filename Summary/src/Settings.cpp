#include <fstream>
#include <iostream>

#include "Settings.h"

Settings::Settings(const std::string& file_with_rules)
{
	rules_file = file_with_rules;
	json_rules = read_json(rules_file);
	init_settings(file_with_rules);
}
void Settings::init_settings(const std::string& file_name)
{
	init_headers_rule();
	init_font_rule();
}
void Settings::init_headers_rule()
{
//	Settings::headers = json_rules["Заголовки"];
	std::map<std::string, int> headers1 = json_rules["Заголовки"];
	headers = headers1;
}
void Settings::init_font_rule()
{
	std::map<std::string, std::string> font = json_rules["Настройки шрифта"];
	font_setting.name_font = json_rules["Настройки шрифта"]["Название"];
	font_setting.value_font = std::stoi(std::string(json_rules["Настройки шрифта"]["Размер основного текста"]));
	font_setting.value_font_header = std::stoi(std::string(json_rules["Настройки шрифта"]["Размер заголовка"]));
}
int Settings::get_count_header(std::string& header)
{
	return headers.count(header);
}
std::map<std::string, int>::iterator Settings::find_header(const std::string& header)
{
	return headers.find(header);
}
std::map<std::string, int>::iterator Settings::get_begin_header()
{
	return headers.begin();
}
std::map<std::string, int>::iterator Settings::get_end_header()
{
	return headers.end();
}

json Settings::read_json(const std::string& file_name)
{
	std::ifstream json_file(file_name);
	json j;
	j = json::parse(json_file);
//		json_file >> s;
	json_file.close();
	return j;
}