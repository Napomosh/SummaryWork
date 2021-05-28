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
			if(result_str == "Рис")
			{
				element = page_reader.Next();
				element = page_reader.Next();
			}
		}
		else if (element.GetType() == Element::e_image)
		{
			images++;
		}
	}


	if (result_str.substr(0, 6) == "Рис")
	{
		try
		{
			if (std::stoi(result_str.substr(6, result_str.find('-', 6))) == prev_pict_number + 1)
			{
				capture_image++;
//				std::cout << "Картинки идут подряд" << std::endl;
				prev_pict_number++;
			}
			else
			{
//				std::cout << "Картинки идут не подряд" << std::endl;
			}
		}
		catch  (std::exception& e)
		{
//			std::cout << "Некорректное имя рисунков" << std::endl;
		}
	}
}

bool PicturesChecker::check() const
{
//	std::cout << "Результат сверки картинок: " << (images == capture_image) << "          " << images << "          " << capture_image << std::endl;
	return images == capture_image;
}
