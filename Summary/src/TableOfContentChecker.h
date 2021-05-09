#ifndef SUMMARY_WORK_TABLEOFCONTENTCHECKER_H
#define SUMMARY_WORK_TABLEOFCONTENTCHECKER_H

#include "Rule.h"

class TableOfContentChecker : Rule
{
public:
	void check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker) override;
private:
	void parse_headers(pdftron::PDF::Line line, pdftron::PDF::Style style, Settings &settings, Result &checker);
};


#endif //SUMMARY_WORK_TABLEOFCONTENTCHECKER_H
