#ifndef SUMMARY_WORK_STYLECHECKER_H
#define SUMMARY_WORK_STYLECHECKER_H

#include <pdftron/PDF/TextExtractor.h>
#include <pdftron/PDF/PDFDoc.h>

#include "Rule.h"
#include "Settings.h"
#include "Checker.h"

class StyleChecker : Rule
{
public:
	StyleChecker() = default;
	
	void check_rule(pdftron::PDF::Page& page, Settings& set, Checker& checker) override;
};

#endif //SUMMARY_WORK_STYLECHECKER_H