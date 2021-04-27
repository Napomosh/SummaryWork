#ifndef SUMMARY_WORK_STYLECHECKER_H
#define SUMMARY_WORK_STYLECHECKER_H

#include <pdftron/PDF/TextExtractor.h>
#include <pdftron/PDF/PDFDoc.h>

#include "Rule.h"
#include "Settings.h"

class StyleChecker : Rule
{
public:
	StyleChecker();
	
	virtual void check_rule(pdftron::PDF::Page& page, Settings& set) override;
};

#endif //SUMMARY_WORK_STYLECHECKER_H