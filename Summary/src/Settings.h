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

	int get_count_header(std::string& header);
	bool get_is_test_found();
	int get_test_count();
	void set_is_test_found(bool value);
	std::map<std::string, int>::iterator find_header(const std::string& header);
	std::map<std::string, int>::iterator get_begin_header();
	std::map<std::string, int>::iterator get_end_header();

private:
	std::string rules_file;
	nlohmann::json json_rules = nullptr;
	std::map<std::string, int> headers;
	int test_count{ 0 };
	bool is_test_found = false;

	nlohmann::json read_json(const std::string& file_name);

	void init_settings(const std::string& file_name);
	void init_headers_rule();
	void init_font_rule();
	void init_test_rule();
};


#endif //SUMMARY_WORK_SETTINGS_H
