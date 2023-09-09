#include "Movie.h"

namespace sdds
{
	Movie::Movie()
	{
		n_title = "";
		n_year = 0;
		n_desc = "";
	}

	const string& Movie::title() const
	{
		return n_title;
	}

	Movie::Movie(const string& string)
	{
		std::string a = string;
		auto n = a.find(',');

		n_title = a.substr(0, n);
		a.erase(0, n + 1);
		n = a.find(',');

		n_year = stoi(a.substr(0, n));
		a.erase(0, n + 1);

		n_desc = a;
		auto pos1 = n_desc.find_first_not_of(' ');
		auto pos2 = n_desc.find_last_not_of(' ');
		n_desc = n_desc.substr(pos1, (pos2 - pos1) + 1);

		pos1 = n_title.find_first_not_of(' ');
		pos2 = n_title.find_last_not_of(' ');
		n_title = n_title.substr(pos1, (pos2 - pos1) + 1);
	}

	ostream& operator<<(ostream& os, const Movie& m)
	{
		os << setw(40) << right << setfill(' ') << m.n_title << " | " << setw(4) << m.n_year << " | " << left << m.n_desc << endl;
		return os;
	}
}