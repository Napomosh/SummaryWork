#include <iostream>
#include <map>
#include <string>

#include "../libs/pdftron/PDF/PDFNet.h"
#include "../libs/pdftron/PDF/PDFDoc.h"
#include <../libs/pdftron/PDF/TextExtractor.h>
#include <nlohmann/json.hpp>

#include "../headers/example.h"

using namespace pdftron;
using namespace PDF;

using json = nlohmann::json;


int main(int argc, char* argv[])
{
    int ret = 0;
    PDFNet::Initialize();
    const char* input_path = "/home/alex/CLionProjects/SummaryWork/Summary/resources/lab7.pdf";
    string json_path = "/home/alex/CLionProjects/SummaryWork/Summary/resources/json_file.json";
    map<string, int> headers;
    json j = read_json(json_path);
    headers = j.get<map <string, int>>();
    map<string, int>::iterator it;

    try
    {
        PDFDoc doc(input_path);
        doc.InitSecurityHandler();

        Page page ;
        for (int i = 2; (page = doc.GetPage(i)) != NULL; i++)
        {
            //Page page = doc.GetPage(2);
            if (!page)
            {
                cout << "Page not found." << endl;
                return 1;
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

                    if (headers.count(head) > 0)
                    {
                        auto cur_header = headers.find(head);
                        if (cur_header->second == 0)
                        {
                            cur_header->second++;
                            cout << "Найден заголовок: " << cur_header->first << endl;
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
        for (auto it = headers.begin(); it != headers.end(); ++it)
        {
            if (it->second == 0)
            {
                cout << "Не найден заголовок: " << it->first << endl;
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

    PDFNet::Terminate();
    return ret;
}

// g++ main.cpp -I../libs -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp