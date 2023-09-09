#ifndef SDDS_CRIMESTATISTICS_H_
#define SDDS_CRIMESTATISTICS_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <list>

namespace sdds {

	struct Crime {
		std::string province{};
		std::string district{};
		std::string crime{};
		int casesNum{ 0 };
		int year{ 0 };
		int m_resolved{ 0 };
	};



	class CrimeStatistics {
		std::vector<Crime> crimes;
	public:
		CrimeStatistics(const char* fileName);
		void display(std::ostream& out)const;
		void sort(const std::string& field);
		void cleanList();
		bool inCollection(const std::string& crime) const;
		std::list<Crime> getListForProvince(const std::string& province) const;
	};


	std::ostream& operator<<(std::ostream& os, const Crime& cr);
	std::string trim(const std::string& str);
}


#endif //!SDDS_CRIMESTATISTICS_H_