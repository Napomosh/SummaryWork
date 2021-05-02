#include "StyleChecker.h"

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/TextExtractor.h>

#include <iostream>

using namespace pdftron;
using namespace PDF;

void StyleChecker::check_rule(Page& page, Settings& set, Checker& checker)
{
	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;
	TextExtractor::Style line_style;
	for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
	{
		line_style = line.GetStyle();
		if (line.GetNumWords() == 0)
		{
			continue;
		}
		
		else if(line_style.GetFontName().ConvertToUtf8() != set.font_setting.name_font)
		{
			std::cout << "Строка номер: " << line.GetCurrentNum() << " Шрифт отличается от заданного" << std::endl;
			checker.add_style_message("Строка номер: " + std::to_string(line.GetCurrentNum()) + " Шрифт отличается от заданного");
			continue;
		}
		else if((line_style.GetFontSize() > (set.font_setting.value_font + 0.5) || line_style.GetFontSize() < (set.font_setting.value_font - 0.5)) &&
				(line_style.GetFontSize() > (set.font_setting.value_font_header + 0.5) || line_style.GetFontSize() < (set.font_setting.value_font_header - 0.5)))
		{
			std::cout << "Строка номер: " << line.GetCurrentNum() << " Размер шрифта отличается от заданного" << std::endl;
			checker.add_style_message("Строка номер: " + std::to_string(line.GetCurrentNum()) + " Размер шрифта отличается от заданного");
			continue;
		}
	}
}