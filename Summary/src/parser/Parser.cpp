#include "Parser.h"
#include "../settings/Settings.h"

#include <iostream>
#include <map>
#include <string>

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/PDFDoc.h>
#include <pdftron/PDF/TextExtractor.h>

Parser::Parser(const std::string& input_path) : set(Settings("/home/alex/CLionProjects/SummaryWork/Summary/resources/json_file.json"))
{
	lab_name = input_path;
}

void Parser::check_headers(const std::string& head)
{
	auto cur_header = set.find_header(head);
	if (cur_header->second == 0)
	{
		cur_header->second++;
//		std::cout << "Найден заголовок: " << cur_header->first << std::endl;
		checker.add_head_message("Найден заголовок: " + cur_header->first );
		if (cur_header->first.substr(0, sizeof ("Тест")) == "Тест")
		{
			std::cout << "Нашли тестирование, здесь нужно посчитать тесты" << std::endl;
		}
	}
	else
	{
		std::cout << "Заголовок встречается несколько раз" << std::endl;
	}
}

std::string Parser::parse_headers(TextExtractor::Line& line, TextExtractor::Style& line_style)
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

		// If the word style is different from the parent style, output the new style.
		TextExtractor::Style s = word.GetStyle();
		if (s != line_style)
		{
			std::cout << "Заголовок написан разными стилями" << std::endl;
		}

		UString uni_str;
		uni_str.Assign(word.GetString(), sz);
		if (!head.empty())
		{
			head += ' ';
		}
		head += uni_str.ConvertToUtf8();
	}
	return head;
}

int Parser::parse()
{
	int ret = 0;
	std::map<std::string, int>::iterator it;
	try
	{
		PDFDoc doc(lab_name);
		doc.InitSecurityHandler();
		Page page ;
		int test_count = 2;
		for (int i = test_count; (page = doc.GetPage(i)) != NULL; i++)
		{
			if (!page)
			{
				std::cout << "Page not found." << std::endl;
				ret = 1;
				return ret;
			}
			TextExtractor txt;
			txt.Begin(page);
			UString uni_str;
			std::string head;
			TextExtractor::Line line;
			TextExtractor::Style line_style;
			// For each line on the page...
			for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
			{
				line_style = line.GetStyle();
				if(line_style.GetFontName().ConvertToUtf8() != set.font_setting.name_font)
				{
					std::cout << "Строка номер: " << line.GetCurrentNum() << " Шрифт отличается от заданного" << std::endl;
					continue;
				}
				else if(line_style.GetFontSize() > (set.font_setting.value_font + 0.5) || line_style.GetFontSize() < (set.font_setting.value_font - 0.5))
				{
					std::cout << "Строка номер: " << line.GetCurrentNum() << " Размер шрифта отличается от заданного" << std::endl;
					continue;
				}
				//cout << endl << line_style.GetFontSize() << " " << line_style.GetFontName().ConvertToUtf8() << endl;
				if (line.GetNumWords() == 0)
				{
					continue;
				}
				if (line_style.GetFontSize() > (set.font_setting.value_font_header - 0.5) && line_style.GetFontSize() < (set.font_setting.value_font_header + 0.5)) {
					head = parse_headers(line, line_style);
					if (set.get_count_header(head) > 0)
					{
						check_headers(head);
					}
				}
			}
		}
		for (auto it1 = set.get_begin_header(); it1 != set.get_end_header(); ++it1)
		{
			if (it1->second == 0)
			{
//				std::cout << "Не найден заголовок: " << it1->first << std::endl;
				checker.add_head_message("Не найден заголовок: " + it1->first);
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		ret = 1;
	}
	catch (...)
	{
		std::cout << "Unknown Exception" << std::endl;
		ret = 1;
	}
	checker.print_head_result();
}

Checker Parser::get_checker_info()
{
	return checker;
}
