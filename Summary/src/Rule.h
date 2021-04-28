#ifndef SUMMARY_WORK_RULE_H
#define SUMMARY_WORK_RULE_H

#include <pdftron/PDF/TextExtractor.h>
#include <pdftron/PDF/PDFDoc.h>

#include "Settings.h"
#include "Checker.h"

class Rule
{
public:
	Rule() {}

	virtual void check_rule(pdftron::PDF::Page& page, Settings& set, Checker& checker) = 0;
};

#endif //SUMMARY_WORK_RULE_H