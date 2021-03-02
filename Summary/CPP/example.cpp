#include <iostream>

#include "Project/example.h"

using namespace pdftron;
using namespace PDF;

void PrintStyle(TextExtractor::Style& s)
{
	UInt8 rgb[3];
	char rgb_hex[24];

	s.GetColor(rgb);
	sprintf(rgb_hex, "%02X%02X%02X;", rgb[0], rgb[1], rgb[2]);
	std::cout << " style=\"font-family:" << s.GetFontName() << "; " << "font-size:" << s.GetFontSize() << ";"
		<< (s.IsSerif() ? " sans-serif; " : " ") << "color:#" << rgb_hex << "\"";
}