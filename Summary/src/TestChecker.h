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
	
	void check_rule(pdftron::PDF::Page& page, Settings& set, Result& checker) override;

private:
	int LevenshteinDistance(const std::string& source, const std::string& target);

	bool is_test;
};

#endif //SUMMARY_WORK_TESTCHECKER_H