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
	test_tokens.resize(set.get_test_count());

	TextExtractor txt;
	txt.Begin(page);
	TextExtractor::Line line;
	std::string test;
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

//			 std::cout << test << std::endl;
			if (test == "Тест")
			{
				is_test = true;
				test_num++; 
				word = word.GetNextWord();
				if(!word.IsValid())
				{
					break;
				}
				sz = word.GetStringLen();
				UString tmp;
				tmp.Assign(word.GetString(), sz);
				if(tmp == std::to_string(test_num))
				{
					std::cout << "Тест номер: " << tmp << " найден." << std::endl;
					checker.add_test_message("Тест номер: " + tmp.ConvertToAscii() + " найден.");
				}
				cur_test++;
				continue;
			}
			else if (is_test && line.IsValid())
			{
				compare_tests(line);
				break;
			}
		}
	}
	check_result(set, checker);
	if(!test_tokens.empty())
	{
		compare_tokens();
	}
}

void TestChecker::compare_tests(TextExtractor::Line& line)
{
	UString uni_str;
	for (TextExtractor::Word word = line.GetFirstWord(); word.IsValid(); word = word.GetNextWord())
	{
		uni_str.Assign(word.GetString(), word.GetStringLen());
		if(uni_str.ConvertToUtf8() == "Тест")
		{
			cur_test++;
			word = word.GetNextWord();
			int sz = word.GetStringLen();
			UString tmp;
			tmp.Assign(word.GetString(), sz);
			if(tmp.ConvertToUtf8() == std::to_string(cur_test))
			{
				std::cout << "Тест номер: " << tmp << " найден." << std::endl;
				test_num++;
//				checker.add_test_message("Тест номер: " + tmp.ConvertToAscii() + " найден.");
			}
			return;
		}
		test_tokens[cur_test - 1].push_back(uni_str.ConvertToUtf8());
	}
}

void TestChecker::compare_tokens()
{
	//  Выбираем тест, который будем проверять сейчас
	for(int test = 0; test < test_num; test++)
	{
		// Выбираем тот, с которым проверяем
		for(int compare_with_test = 0; compare_with_test < test_num; compare_with_test++)
		{
			std::list<std::string>::iterator it;
			std::list<std::string>::iterator it_compare;
			std::list<std::string>::iterator end;
			if(test_tokens[test].size() < test_tokens[compare_with_test].size())
			{
				it = test_tokens[test].begin();
				it_compare = test_tokens[compare_with_test].begin();
				end = test_tokens[test].end();
			}
			else
			{
				it = test_tokens[compare_with_test].begin();
				it_compare = test_tokens[test].begin();
				end = test_tokens[compare_with_test].end();
			}
			for(; it != end; ++it, ++it_compare)
			{
				if(*it == *it_compare)
				{
					errors++;
				}
			}
			std::cout << test << "         " << compare_with_test << "            " << errors << "             " << (errors / (float)test_tokens[test].size() * 100) << "%" << std::endl;
			errors = 0;
		}
	}
}

void TestChecker::check_result(Settings& set, Result& checker)
{
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