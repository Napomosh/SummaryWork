#ifndef SUMMARY_WORK_SPELLCHECKER_H
#define SUMMARY_WORK_SPELLCHECKER_H
#include "aspell.h"

class SpellChecker
{
public:
	SpellChecker();

private:
	AspellConfig* spell_config;
};


#endif //SUMMARY_WORK_SPELLCHECKER_H
