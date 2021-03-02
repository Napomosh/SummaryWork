//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <PDF/PDFNet.h>
#include <PDF/PDFDoc.h>
#include <PDF/ElementReader.h>
#include <PDF/Element.h>
#include <PDF/Font.h>
#include <Filters/FilterReader.h>
#include <PDF/Image/Image2RGB.h>
#include <PDF/TextExtractor.h>

// This sample illustrates the basic text extraction capabilities of PDFNet.

#include <iostream>

using namespace std;

using namespace pdftron;
using namespace PDF;
using namespace SDF;
using namespace Common;
using namespace Filters;

void PrintStyle(TextExtractor::Style& s)
{
	UInt8 rgb[3];
	char rgb_hex[24];

	s.GetColor(rgb);
	sprintf(rgb_hex, "%02X%02X%02X;", rgb[0], rgb[1], rgb[2]);
	cout << " style=\"font-family:" << s.GetFontName() << "; " << "font-size:" << s.GetFontSize() << ";"
		<< (s.IsSerif() ? " sans-serif; " : " ") << "color:#" << rgb_hex << "\"";
}

int main(int argc, char* argv[])
{
	int ret = 0;
	PDFNet::Initialize();
	// Relative path to the folder containing test files.
	string input_path = "/home/alex/Summary/Summary/Resources/lab7.pdf";
	// string output_path = "../../TestFiles/Output/";

	const char* filein = argc > 1 ? argv[1] : input_path.c_str();

	bool example1_basic = false;
	bool example3_wordlist = false;
	bool example4_advanced = true;

	// Sample code showing how to use high-level text extraction APIs.
	try
	{
		PDFDoc doc(filein);
		doc.InitSecurityHandler();

		Page page = doc.GetPage(2);
		if (!page) {
			cout << "Page not found." << endl;
			return 1;
		}

		TextExtractor txt;
		txt.Begin(page); // Read the page.


		// Example 1. Get all text on the page in a single string.
		// Words will be separated with space or new line characters.
		if (example1_basic)
		{
			// Get the word count.
			cout << "Word Count: " << txt.GetWordCount() << endl;

			UString text;
			txt.GetAsText(text);
			cout << "\n\n- GetAsText --------------------------\n" << text.ConvertToUtf8() << endl;
			cout << "-----------------------------------------------------------" << endl;
		}

		// Example 3. Extract words one by one.
		if (example3_wordlist)
		{
			UString text;
			TextExtractor::Line line = txt.GetFirstLine();
			TextExtractor::Word word;
			for (; line.IsValid(); line = line.GetNextLine()) {
				for (word = line.GetFirstWord(); word.IsValid(); word = word.GetNextWord()) {
					text.Assign(word.GetString(), word.GetStringLen());

					cout << text.ConvertToUtf8() << '\n';
				}
			}
			cout << "-----------------------------------------------------------" << endl;
		}

		// Example 4. A more advanced text extraction example. 
		// The output is XML structure containing paragraphs, lines, words, 
		// as well as style and positioning information.
		if (example4_advanced)
		{
			double q[8];
			int cur_flow_id = -1, cur_para_id = -1;

			UString uni_str;
			TextExtractor::Line line;
			TextExtractor::Word word;
			TextExtractor::Style s, line_style;

			// For each line on the page...
			for (line = txt.GetFirstLine(); line.IsValid(); line = line.GetNextLine())
			{
				line_style = line.GetStyle();
				cout << endl << line_style.GetFontSize() << " " << line_style.GetFontName().ConvertToUtf8() << endl;
				

				if (line.GetNumWords() == 0) {
					continue;
				}

				if (cur_para_id != line.GetParagraphID()) {
					cur_para_id = line.GetParagraphID();
				}

				// For each word in the line...
				for (word = line.GetFirstWord(); word.IsValid(); word = word.GetNextWord())
				{
					// Output the bounding box for the word.
					int sz = word.GetStringLen();
					if (sz == 0) {
						continue;
					}

					// If the word style is different from the parent style, output the new style.
					s = word.GetStyle();
					if (s != line_style) {
						//cout << s.GetFontSize() << " " << s.GetFontName().ConvertToUtf8() << " ";
					}

					uni_str.Assign(word.GetString(), sz);
					cout << uni_str.ConvertToUtf8() << " ";
				}
				cout << endl;

			}

		}
	}
	catch (Exception& e)
	{
		cout << e << endl;
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

// g++ main.cpp -I../Headers -L../Lib -lPDFNetC -lstdc++ -lpthread -lm -lc -Wl,-rpath,../Lib -Wl,-rpath$ORIGIN -o myApp