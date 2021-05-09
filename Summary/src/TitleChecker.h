#ifndef SUMMARY_WORK_TITLECHECKER_H
#define SUMMARY_WORK_TITLECHECKER_H


#include "Rule.h"

class TitleChecker : Rule
{
public:
	void check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker) override;

private:
	void parse_words(pdftron::PDF::TextExtractor::Line& line, Settings& set);
};


#endif //SUMMARY_WORK_TITLECHECKER_H
