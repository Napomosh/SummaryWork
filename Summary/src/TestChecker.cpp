#include "TestChecker.h"

#include <iostream>
#include <string>
#include <vector>

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/TextExtractor.h>

using namespace pdftron;
using namespace PDF;

int TestChecker::LevenshteinDistance(const std::string& source, const std::string& target)
{
	if (source.size() > target.size()) {
		return LevenshteinDistance(target, source);
	}

	const int min_size = source.size(), max_size = target.size();
	std::vector<int> lev_dist(min_size + 1);

	for (int i = 0; i <= min_size; ++i) {
		lev_dist[i] = i;
	}

	for (int j = 1; j <= max_size; ++j) {
		int previous_diagonal = lev_dist[0], previous_diagonal_save;
		++lev_dist[0];

		for (int i = 1; i <= min_size; ++i) {
			previous_diagonal_save = lev_dist[i];
			if (source[i - 1] == target[j - 1]) {
				lev_dist[i] = previous_diagonal;
			} else {
				lev_dist[i] = std::min(std::min(lev_dist[i - 1], lev_dist[i]), previous_diagonal) + 1;
			}
			previous_diagonal = previous_diagonal_save;
		}
	}

	return lev_dist[min_size];
}

TestChecker::TestChecker()
{

}

void TestChecker::check_rule(Page& page, Settings& set, Result& checker)
{
	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;
	std::string test;
	int test_num = 0;
	for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
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
			test = uni_str.ConvertToUtf8();

			// std::cout << test << std::endl;
			if (test == "Тест")
			{
				is_test = true;
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
			if (is_test)
			{

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