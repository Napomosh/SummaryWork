#include <iostream>
#include <map>
#include <string>

#include <../libs/pdftron/PDF/PDFNet.h>
#include <../libs/pdftron/PDF/PDFDoc.h>
#include <../libs/pdftron/PDF/TextExtractor.h>
#include <nlohmann/json.hpp>
#include <fstream>

#include "settings/Settings.h"
#include "../headers/example.h"

using json = nlohmann::json;

json read_json(const std::string& file_name)
{
    std::ifstream json_file(file_name);
    json j;
	j = json::parse(json_file);
    //json_file >> j;
    json_file.close();

    return j;
}

void run_all(const string& input_path, int& ret)
{
	Settings set ("../resources/json_file.json");
//	const std::string json_path { "../resources/json_file.json" };
//	json j = read_json(json_path);
//	map<string, int> headers = j["Заголовки"];
//	int tests_count = j["Количество тестов"];

	map<string, int>::iterator it;
	try
	{
		PDFDoc doc(input_path);
		doc.InitSecurityHandler();

		Page page ;
		int test_count = 2;
		for (int i = test_count; (page = doc.GetPage(i)) != NULL; i++)
		{
			//Page page = doc.GetPage(2);
			if (!page)
			{
				cout << "Page not found." << endl;
				ret = 1;
				return;
			}

			TextExtractor txt;
			txt.Begin(page);

			UString uni_str;
			string head;
			TextExtractor::Line line;
			TextExtractor::Word word;
			TextExtractor::Style line_style;

			// For each line on the page...
			for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
			{
				line_style = line.GetStyle();
				//cout << endl << line_style.GetFontSize() << " " << line_style.GetFontName().ConvertToUtf8() << endl;


				if (line.GetNumWords() == 0)
				{
					continue;
				}

				if (line_style.GetFontSize() == 20.04) {

					// For each word in the line...
					if (!head.empty())
					{
						head.clear();
					}

					for (word = line.GetFirstWord(); word.IsValid(); word = word.GetNextWord())
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
							cout << "Заголовок написан разными стилями" << endl;
						}

						uni_str.Assign(word.GetString(), sz);
						if (!head.empty())
						{
							head += ' ';
						}
						head += uni_str.ConvertToUtf8();
					}

					if (set.get_count_header(head) > 0)
					{
						auto cur_header = set.find_header(head);
						if (cur_header->second == 0)
						{
							cur_header->second++;
							cout << "Найден заголовок: " << cur_header->first << endl;
							if (cur_header->first.substr(0, 8) == "Тест")
							{
								std::cout << "Нашли тестирование, здесь нужно посчитать тесты" << std::endl;
							}
						}
						else
						{
							cout << "Заголовок встречается несколько раз" << endl;
						}
					}

					// if (cur_para_id != line.GetParagraphID())
					// {
					// 	cur_para_id = line.GetParagraphID();
					// }

				}
			}
		}
		for (auto it1 = set.get_begin_header(); it1 != set.get_end_header(); ++it1)
		{
			if (it1->second == 0)
			{
				cout << "Не найден заголовок: " << it1->first << endl;
			}
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		ret = 1;
	}
	catch (...)
	{
		cout << "Unknown Exception" << endl;
		ret = 1;
	}
}