#ifndef SUMMARY_WORK_SETTINGS_H
#define SUMMARY_WORK_SETTINGS_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Settings
{
public:
	Settings& operator=(Settings *rhs) = delete;
	Settings( const Settings& rhs );
	explicit Settings(const std::string& rules_file);

	void init_settings(const std::string& file_name);

	int get_count_header(std::string& header);
	std::map<std::string, int>::iterator find_header(const std::string& header);
	std::map<std::string, int>::iterator get_begin_header();
	std::map<std::string, int>::iterator get_end_header();

private:
	std::string rules_file;
	json json_rules;
	std::map<std::string, int> headers;

	json read_json(const std::string& file_name);
	void init_headers_rule();
};


#endif //SUMMARY_WORK_SETTINGS_H
