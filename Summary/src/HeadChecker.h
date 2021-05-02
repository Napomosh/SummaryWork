#ifndef SUMMARY_WORK_HEADCHECKER_H
#define SUMMARY_WORK_HEADCHECKER_H

#include <pdftron/PDF/TextExtractor.h>
#include <pdftron/PDF/PDFDoc.h>

#include "Rule.h"
#include "Settings.h"
#include "Checker.h"

class HeadChecker : Rule
{
public:
	HeadChecker();
	
	void get_result(Settings& set, Checker& checker); // пока void, но что-то она должна возвращать
	void check_rule(pdftron::PDF::Page& page, Settings& set, Checker& checker) override;
private:
	bool is_prev_head;

	void check_headers(const std::string& head, pdftron::PDF::TextExtractor::Line& line, Settings& set, Checker& checker);
	void parse_headers(pdftron::PDF::TextExtractor::Line& line, pdftron::PDF::	TextExtractor::Style& line_style, Settings& set, Checker& checker);
	void set_prev_flag(bool value);
};

#endif //SUMMARY_WORK_HEADCHECKER_H