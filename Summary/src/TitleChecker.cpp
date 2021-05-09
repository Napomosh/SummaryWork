#include "TitleChecker.h"

#include <pdftron/PDF/PDFNet.h>
#include <pdftron/PDF/TextExtractor.h>

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

}
