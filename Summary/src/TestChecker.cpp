#include "TestChecker.h"

#include <iostream>
#include <string>

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/TextExtractor.h>

using namespace pdftron;
using namespace PDF;

TestChecker::TestChecker()
{

}

void TestChecker::check_rule(Page& page, Settings& set, Result& checker)
{
	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;
	TextExtractor::Style line_style;
	std::string test;
	int test_num = 0;
	for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
	{
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
			test = uni_str.ConvertToUtf8();

			// std::cout << test << std::endl;
			if (test == "Тест")
			{
				test_num++; 
				word = word.GetNextWord();
				if(!word.IsValid())
				{
					break;
				}
				int sz = word.GetStringLen();
				UString tmp;
				tmp.Assign(word.GetString(), sz);
				if(tmp == std::to_string(test_num))
				{
					std::cout << "Тест номер: " << tmp << " найден." << std::endl;
					checker.add_test_message("Тест номер: " + tmp.ConvertToAscii() + " найден.");
				}
			}
		}
	}
	if(test_num < set.get_test_count())
	{
		std::cout << "Не найдено " << set.get_test_count() - test_num << " тестов." << std::endl;
		checker.add_test_message("Не найдено " + std::to_string(set.get_test_count() - test_num) + " тестов.");
	}
	else if(test_num > set.get_test_count())
	{
		std::cout << "Найдено " <<  test_num - set.get_test_count() << " лишних тестов." << std::endl;
		checker.add_test_message("Найдено " +  std::to_string (test_num - set.get_test_count()) + " лишних тестов.");

	}
	else
	{
		set.set_is_test_found(false);
	}
}