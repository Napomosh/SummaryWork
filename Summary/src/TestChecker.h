#ifndef SUMMARY_WORK_TESTCHECKER_H
#define SUMMARY_WORK_TESTCHECKER_H

#include <pdftron/PDF/TextExtractor.h>
#include <pdftron/PDF/PDFDoc.h>

#include "Rule.h"
#include "Settings.h"
#include "Result.h"

class TestChecker : Rule
{
public:
	TestChecker();
	void check_result(Settings& set, Result& checker);
	void check_rule(pdftron::PDF::Page& page, Settings& set, Result& checker) override;

private:
	int LevenshteinDistance(const std::string& source, const std::string& target);

	bool is_test{false};

	int cur_test {0};
	int test_num {0};
	int repeats {0};
	std::vector<std::list<std::string>> test_tokens;
	void compare_tests(pdftron::PDF::TextExtractor::Line& line, Result& checker);

	void compare_tokens(Result& checker);
};

#endif //SUMMARY_WORK_TESTCHECKER_H