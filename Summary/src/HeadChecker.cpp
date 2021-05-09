#include "HeadChecker.h"

#include <iostream>

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/TextExtractor.h>

using namespace pdftron;
using namespace PDF;

HeadChecker::HeadChecker() : is_prev_head(false)
{

}

void HeadChecker::check_headers(const std::string& head, TextExtractor::Line& line, Settings& set, Result& checker)
{
	auto cur_header = set.find_header(head);
	auto line_style = line.GetStyle();

	if (cur_header->second == 0)
	{
		cur_header->second++;
//		std::cout << "Найден заголовок: " << cur_header->first << std::endl;
		checker.add_head_message("Найден заголовок: " + cur_header->first );
		
		if (cur_header->first.substr(0, 20) == "Тестирован")
		{
			set.set_is_test_found(true);
		}
	}
	else
	{
//		std::cout << "Заголовок встречается несколько раз" << std::endl;
		checker.add_head_message("Заголовок встречается несколько раз");
	}

	if(line_style.GetFontName().ConvertToUtf8() != set.font_setting.name_font)
	{
//		std::cout << "Строка номер: " << line.GetCurrentNum() << " Шрифт заголовка отличается от заданного" << std::endl;
		checker.add_head_message("Строка номер: " + std::to_string(line.GetCurrentNum()) + " Шрифт заголовка отличается от заданного");
	}
	else if(line_style.GetFontSize() > (set.font_setting.value_font_header + 0.5) || line_style.GetFontSize() < (set.font_setting.value_font_header - 0.5))
	{
//		std::cout << "Строка номер: " << line.GetCurrentNum() << " Размер шрифта заголовка отличается от заданного" << std::endl;
		checker.add_head_message("Строка номер: " + std::to_string(line.GetCurrentNum()) + " Размер шрифта заголовка отличается от заданного");
	}
}

void HeadChecker::parse_headers(TextExtractor::Line& line, TextExtractor::Style& line_style, Settings& set, Result& checker)
{
	std::string head;
	for (TextExtractor::Word word = line.GetFirstWord(); word.IsValid(); word = word.GetNextWord())
	{
		// Output the bounding box for the word.
		int sz = word.GetStringLen();
		if (sz == 0)
		{
			continue;
		}

		UString uni_str;
		uni_str.Assign(word.GetString(), sz);
		if (!head.empty())
		{
			head += ' ';
		}
		head += uni_str.ConvertToUtf8();
	}

	if (set.get_count_header(head) > 0)
	{
		if(is_prev_head)
		{
			checker.add_head_message("Два заголовка идут подряд. Строка номер: " + std::to_string(line.GetCurrentNum()));
//			std::cout << "Два заголовка идут подряд. Строка номер: " << line.GetCurrentNum() << std::endl;
		}
		is_prev_head = true;
		check_headers(head, line, set, checker);
	}
	else
	{
//		std::cout << "Неизвестный заголовок или текст написан шрифтом заголовка. Строка номер: " << line.GetCurrentNum() << std::endl;
		checker.add_head_message("Неизвестный заголовок или текст написан шрифтом заголовка. Строка номер: " + std::to_string(line.GetCurrentNum()));
	}
}

void HeadChecker::set_prev_flag(bool value)
{
	is_prev_head = value;
}

void HeadChecker::check_rule(Page& page, Settings& set, Result& checker)
{
	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;
	TextExtractor::Style line_style;
	for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
	{
//		std::cout << line.GetQuad() << std::endl;
		line_style = line.GetStyle();
		if (line_style.GetFontSize() > (set.font_setting.value_font_header - 0.5) && line_style.GetFontSize() < (set.font_setting.value_font_header + 0.5)) {
			parse_headers(line, line_style, set, checker);
		}
		else
		{
			set_prev_flag(false);
		}
	}
}

void HeadChecker::get_result(Settings& set, Result& checker)
{
	for (auto it = set.get_begin_header(); it != set.get_end_header(); ++it)
	{
		if (it->second == 0)
		{
//			std::cout << "Не найден заголовок: " << it->first << std::endl;
			checker.add_head_message("Не найден заголовок: " + it->first);
		}
	}
}