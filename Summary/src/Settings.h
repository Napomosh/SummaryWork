#ifndef SUMMARY_WORK_SETTINGS_H
#define SUMMARY_WORK_SETTINGS_H

#include <nlohmann/json.hpp>

class Settings
{
public:
	Settings& operator=(Settings *rhs) = delete;
	Settings( const Settings& rhs ) = default;
	Settings() = default;
	explicit Settings(const std::string& rules_file);

	struct FontSetting
	{
		std::string name_font = "-1";
		int value_font { -1 };
		int value_font_header { -1 };
	} font_setting;

	struct AdditionalOptions
	{
		bool table_of_contents { false };
		bool pictures_check { false };
		bool compare_headers_source { false };
		int lines_in_fun { 0 };
		int fun_in_file { 0 };
		int test_compare { 0 };
	} additional_options;


	int get_count_header(std::string& header);
	int get_count_table_of_content(std::string& header);
	bool get_is_test_found() const;
	int get_test_count() const;
	void set_is_test_found(bool value);
	std::map<std::string, int>::iterator find_header(const std::string& header);
	std::map<std::string, int>::iterator find_header_in_table_of_content(const std::string& header);
	std::map<std::string, int>::iterator get_begin_header();
	std::map<std::string, int>::iterator get_end_header();

	std::map<std::string, int>::iterator find_key_word(const std::string& word);
	int get_count_word(std::string& word);

private:
	std::string rules_file;
	nlohmann::json json_rules = nullptr;
	std::map<std::string, int> headers;
	std::map<std::string, int> table_of_content;
	std::map<std::string, int> title_key_words;
	int test_count{ 0 };
	bool is_test_found = false;

	nlohmann::json read_json(const std::string& file_name);

	void init_settings(const std::string& file_name);
	void init_headers_rule();
	void init_font_rule();
	void init_test_rule();
	void init_additionals();
	void init_title_key_words();
};


#endif //SUMMARY_WORK_SETTINGS_H
