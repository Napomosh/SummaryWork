#ifndef SUMMARY_WORK_HEADCHECKER_H
#define SUMMARY_WORK_HEADCHECKER_H

#include <pdftron/PDF/TextExtractor.h>
#include <pdftron/PDF/PDFDoc.h>

#include "Rule.h"
#include "Settings.h"

class HeadChecker : Rule
{
public:
	HeadChecker();
	
	void check_headers(const std::string& head, pdftron::PDF::TextExtractor::Line& line, Settings& set);
	void parse_headers(pdftron::PDF::TextExtractor::Line& line, pdftron::PDF::	TextExtractor::Style& line_style, Settings& set);
	void set_prev_flag(bool value);
	void get_result(Settings& set); // пока void, но что-то она должна возвращать
	
	virtual void check_rule(pdftron::PDF::Page& page, Settings& set) override;
private:
	bool is_prev_head;
};

#endif //SUMMARY_WORK_HEADCHECKER_H