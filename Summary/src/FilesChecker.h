#ifndef SUMMARY_WORK_FILESCHECKER_H
#define SUMMARY_WORK_FILESCHECKER_H

#include "Rule.h"

class FilesChecker : Rule
{
public:
	FilesChecker();
	void check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker) override;
	int get_functions_num() const;
	int get_num_command() const;

private:
	int open_brackets {0};
	int close_brackets {0};
	int functions_num {0};
	int num_command {0};
	int files_num {0};

	void check_function_style(const std::string& file);
	void check_files();
};


#endif //SUMMARY_WORK_FILESCHECKER_H
