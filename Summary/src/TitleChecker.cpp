#include "TitleChecker.h"

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/TextExtractor.h>
#include <iostream>

using namespace pdftron;
using namespace PDF;

void TitleChecker::check_rule(pdftron::PDF::Page &page, Settings &set, Result &checker)
{
	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;

	for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
	{
		parse_words(line, set);
	}
}

void TitleChecker::parse_words(Line &line, Settings &set)
{
	for (TextExtractor::Word word = line.GetFirstWord(); word.IsValid(); word = word.GetNextWord())
	{
		int sz = word.GetStringLen();
		if (sz == 0)
		{
			continue;
		}

		UString uni_str;
		uni_str.Assign(word.GetString(), sz);
		std::string key_word = uni_str.ConvertToUtf8();
		if(set.get_count_word(key_word))
		{
			auto it = set.find_key_word(key_word);
			std::cout << "В титульном листе найдено: " << it->first << std::endl;
			it->second++;
			if(it->second > 1)
			{
				std::cout << it->first << " встречается больше одного раза в титульном листе" << std::endl;
			}
		}
	}
}
