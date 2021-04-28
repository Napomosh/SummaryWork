#ifndef SUMMARY_WORK_TESTCHECKER_H
#define SUMMARY_WORK_TESTCHECKER_H

#include <pdftron/PDF/TextExtractor.h>
#include <pdftron/PDF/PDFDoc.h>

#include "Rule.h"
#include "Settings.h"
#include "Checker.h"

class TestChecker : Rule
{
public:
	TestChecker();
	
	virtual void check_rule(pdftron::PDF::Page& page, Settings& set, Checker& checker) override;
};

#endif //SUMMARY_WORK_TESTCHECKER_H