#ifndef _SDDS_SPELLCHECKER_H
#define _SDDS_SPELLCHECKER_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
	class SpellChecker
	{
		string n_badWords[6];
		string n_goodWords[6];
	public:
		SpellChecker(const char* filename);
		void operator()(string& string) const;
		void showStatistics(ostream& out) const;
	};
}

#endif 