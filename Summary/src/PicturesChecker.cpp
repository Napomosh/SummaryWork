#include <iostream>
#include "PicturesChecker.h"

using namespace pdftron;
using namespace PDF;

void PicturesChecker::check_rule(Page &page, Settings &set, Result &checker)
{
	ElementReader page_reader;
	page_reader.Begin(page);

	Element element;
	while ((element = page_reader.Next()) != 0)
	{
		if(element.GetType() == Element::e_group_begin)
		{
			count_picture_caption(page_reader);
		}
		else if (element.GetType() == Element::e_image)
		{
			expected_images++;
		}
	}
	page_reader.End();
}

void PicturesChecker::count_picture_caption(ElementReader& page_reader)
{
	std::string result_str;
	for (auto element = page_reader.Next(); element.GetType() != Element::e_group_end; element = page_reader.Next())
	{
		if (element.GetType() == Element::e_text)
		{
			result_str += element.GetTextString().ConvertToUtf8();
		}
	}
	if (result_str.substr(0, 14) == "Рисунок")
	{
		actual_images++;
	}
}

bool PicturesChecker::check()
{
	std::cout << "Результат сверки картинок: " << (expected_images == actual_images) << std::endl;
	return expected_images == actual_images;
}
