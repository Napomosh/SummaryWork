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
	init_test_rule();
	init_additionals();
	init_title_key_words();
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
void Settings::init_test_rule()
{
	test_count = json_rules["Количество тестов"];
}
void Settings::init_additionals()
{
	additional_options.pictures_check = json_rules["Дополнительные опции"]["Подписи к картинкам"];
	additional_options.table_of_contents = json_rules["Дополнительные опции"]["Оглавление"];
	std::map<std::string, int> headers1 = json_rules["Заголовки"];
	table_of_content = headers1;
}
void Settings::init_title_key_words()
{
	std::map<std::string, int> title_key_words1 = json_rules["Набор ключевых слов для титульного листа"];
	title_key_words = title_key_words1;
}

int Settings::get_count_header(std::string& header)
{
	return headers.count(header);
}
bool Settings::get_is_test_found() const
{
	return is_test_found;
}
int Settings::get_test_count() const
{
	return test_count;
}
void Settings::set_is_test_found(bool value)
{
	is_test_found = value;
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

nlohmann::json Settings::read_json(const std::string& file_name)
{
	std::ifstream json_file(file_name);
	nlohmann::json j;
	j = nlohmann::json::parse(json_file);
//		json_file >> s;
	json_file.close();
	return j;
}

int Settings::get_count_table_of_content(std::string &header)
{
	return table_of_content.count(header);
}

std::map<std::string, int>::iterator Settings::find_header_in_table_of_content(const std::string &header)
{
	return table_of_content.find(header);
}

std::map<std::string, int>::iterator Settings::find_key_word(const std::string &word)
{
	return title_key_words.find(word);
}

int Settings::get_count_word(std::string &word)
{
	return title_key_words.count(word);
}


