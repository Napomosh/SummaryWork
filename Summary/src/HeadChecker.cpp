#include "HeadChecker.h"

#include <iostream>

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/TextExtractor.h>

using namespace pdftron;
using namespace PDF;

HeadChecker::HeadChecker() : is_prev_head(false)
{

}

void HeadChecker::check_headers(const std::string& head, TextExtractor::Line& line, Settings& set)
{
	auto cur_header = set.find_header(head);
	auto line_style = line.GetStyle();

	if (cur_header->second == 0)
	{
		cur_header->second++;
		std::cout << "Найден заголовок: " << cur_header->first << std::endl;
		// checker.add_head_message("Найден заголовок: " + cur_header->first );
		
		if (cur_header->first.substr(0, 20) == "Тестирован")
		{
			// checker.inc_tests_value(1);
			// std::cout << "Нашли тестирование, здесь нужно посчитать тесты" << std::endl;

		}
	}
	else
	{
		std::cout << "Заголовок встречается несколько раз" << std::endl;
	}

	if(line_style.GetFontName().ConvertToUtf8() != set.font_setting.name_font)
	{
		std::cout << "Строка номер: " << line.GetCurrentNum() << " Шрифт заголовка отличается от заданного" << std::endl;
	}
	else if(line_style.GetFontSize() > (set.font_setting.value_font_header + 0.5) || line_style.GetFontSize() < (set.font_setting.value_font_header - 0.5))
	{
		std::cout << "Строка номер: " << line.GetCurrentNum() << " Размер шрифта заголовка отличается от заданного" << std::endl;
	}
}

void HeadChecker::parse_headers(TextExtractor::Line& line, TextExtractor::Style& line_style, Settings& set)
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
			std::cout << "Два заголовка идут подряд. Строка номер: " << line.GetCurrentNum() << std::endl;
		}
		is_prev_head = true;
		check_headers(head, line, set);
	}
	else
	{
		std::cout << "Неизвестный заголовок или текст написан шрифтом заголовка. Строка номер: " << line.GetCurrentNum() << std::endl;
	}
}

void HeadChecker::set_prev_flag(bool value)
{
	is_prev_head = value;
}

void HeadChecker::check_rule(Page& page, Settings& set)
{
	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;
	TextExtractor::Style line_style;
	for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
	{
		line_style = line.GetStyle();
		if (line_style.GetFontSize() > (set.font_setting.value_font_header - 0.5) && line_style.GetFontSize() < (set.font_setting.value_font_header + 0.5)) {
			
			parse_headers(line, line_style, set);
		}
		
		else
		{
			set_prev_flag(false);
		}
	}
}

void HeadChecker::get_result(Settings& set)
{
	for (auto it = set.get_begin_header(); it != set.get_end_header(); ++it)
	{
		if (it->second == 0)
		{
				std::cout << "Не найден заголовок: " << it->first << std::endl;
			// checker.add_head_message("Не найден заголовок: " + it->first);
		}
	}
}