#ifndef SUMMARY_WORK_TABLEOFCONTENTCHECKER_H
#define SUMMARY_WORK_TABLEOFCONTENTCHECKER_H

#include "Rule.h"

class TableOfContentChecker : Rule
{
public:
	void check_rule(pdftron::PDF::Page &page, Settings &set, Checker &checker) override;
private:
	void parse_headers(pdftron::PDF::Line line, pdftron::PDF::Style style, Settings &settings, Checker &checker);
};


#endif //SUMMARY_WORK_TABLEOFCONTENTCHECKER_H
