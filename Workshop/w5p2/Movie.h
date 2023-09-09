#ifndef _SDDS_MOVIE_H
#define _SDDS_MOVIE_H

#include <iostream>

#include "SpellChecker.h"

using namespace std;

namespace sdds
{
	class Movie
	{
		string n_title;
		int n_year;
		string n_desc;

	public:
		Movie();
		const string& title() const;
		Movie(const string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(n_title);
			spellChecker(n_desc);
		}
		friend ostream& operator<<(ostream& os, const Movie& src);
	};
}
#endif 