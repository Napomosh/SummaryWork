#ifndef SUMMARY_WORK_PICTURESCHECKER_H
#define SUMMARY_WORK_PICTURESCHECKER_H

#include "Rule.h"

#include <pdftron/PDF/ElementReader.h>

class PicturesChecker : Rule
{
public:
	void check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker) override;
	bool check () const;
private:
	int images = { 0 };
	int capture_image = {0 };
	int prev_pict_number = { 0 };
	void count_picture_caption(pdftron::PDF::ElementReader& page_reader);
};


#endif //SUMMARY_WORK_PICTURESCHECKER_H
