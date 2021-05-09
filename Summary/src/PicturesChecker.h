#ifndef SUMMARY_WORK_PICTURESCHECKER_H
#define SUMMARY_WORK_PICTURESCHECKER_H

#include "Rule.h"

#include <pdftron/PDF/ElementReader.h>

class PicturesChecker : Rule
{
public:
	void check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker) override;
	bool check ();
private:
	int expected_images = { 0 };
	int actual_images = { 0 };
	void count_picture_caption(pdftron::PDF::ElementReader& page_reader);
};


#endif //SUMMARY_WORK_PICTURESCHECKER_H
