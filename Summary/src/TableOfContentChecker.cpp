//
// Created by alex on 5/4/21.
//

#include <iostream>
#include "TableOfContentChecker.h"

using namespace pdftron;
using namespace PDF;

void TableOfContentChecker::check_rule(Page &page, Settings &set, Checker &checker)
{
	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;
	TextExtractor::Style line_style;
	for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
	{
		line_style = line.GetStyle();
		parse_headers(line, line_style, set, checker);
	}
}

void TableOfContentChecker::parse_headers(pdftron::PDF::Line line, pdftron::PDF::Style style, Settings &settings,
                                          Checker &checker)
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
		if(!word.GetNextWord().IsValid())
		{
			break;
		}
	}

	if(settings.get_count_table_of_content(head) > 0)
	{
		auto cur_header = settings.find_header_in_table_of_content(head);
		if(cur_header->second == 0)
		{
			cur_header->second++;
			std::cout << "Найден заголовок в оглавлении: " << cur_header->first << std::endl;
		}
		else
		{
			std::cout << "Заголовок в оглавлении встречается несколько раз: " << cur_header->first << std::endl;
		}
	}
}
