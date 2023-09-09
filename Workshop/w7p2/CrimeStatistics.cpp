#include "CrimeStatistics.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <list>

using namespace std;

namespace sdds {

	CrimeStatistics::CrimeStatistics(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw std::runtime_error("invalid file name");
		}

		std::string line;
		while (std::getline(file, line)) {
			Crime crime;
			crime.province = trim(line.substr(0, 25));
			crime.district = trim(line.substr(25, 25));
			crime.crime = trim(line.substr(50, 25));
			crime.year = std::stoi(line.substr(75, 5));
			crime.casesNum = std::stoi(line.substr(80, 5));
			crime.m_resolved = std::stoi(line.substr(85, 5));
			crimes.push_back(crime);
		}
	}

	void CrimeStatistics::sort(const string& field) {
		if (field == "Province") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& cr1, const Crime& cr2) {
				return cr1.province < cr2.province;});
		}
		else if (field == "Crime") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& cr1, const Crime& cr2) {
				return cr1.crime < cr2.crime;});
		}
		else if (field == "Cases") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& cr1, const Crime& cr2) {
				return cr1.casesNum < cr2.casesNum;});
		}
		else if (field == "Resolved") {
			std::sort(crimes.begin(), crimes.end(), [](const Crime& cr1, const Crime& cr2) {
				return cr1.m_resolved < cr2.m_resolved;
				}
			);
		}
	}

	std::string trim(const std::string& str) {
		size_t first = str.find_first_not_of(' ');
		if (first == std::string::npos) {
			return "";
		}
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, last - first + 1);
	}

	void CrimeStatistics::display(std::ostream& out) const {
		int totalCases = 0;
		int totalResolved = 0;
		for_each(crimes.begin(), crimes.end(), [&out, &totalCases, &totalResolved](const Crime& crime) {
			out << crime << '\n';
			totalCases += crime.casesNum;
			totalResolved += crime.m_resolved;
			});
		out << setw(89) << std::setfill('-') << '\n' << std::setfill(' ') << "|" << std::setw(80) << std::right << "Total Crimes:  " << totalCases << " |" << std::endl << "|" << std::setw(80) << std::right << "Total Resolved Cases:  " << totalResolved << " |" << std::endl;

	}

	

	void CrimeStatistics::cleanList() {
		std::transform(crimes.begin(), crimes.end(), crimes.begin(), [](Crime& cr) {
			if (cr.crime == "[None]") {
				cr.crime = "";
			}
			return cr;
			});
	}

	bool CrimeStatistics::inCollection(const std::string& crime) const {
		return std::any_of(crimes.begin(), crimes.end(), [&crime](const Crime& cr) {
			return cr.crime == crime;
			});
	}

	std::ostream& operator<<(std::ostream& os, const Crime& cr)
	{
		os << "| " << std::setw(21) << std::left << cr.province << " | ";
		os << std::setw(15) << std::left << cr.district << " | ";
		os << std::setw(20) << std::left << cr.crime << " | ";
		os << std::setw(6) << std::right << cr.year << " | ";
		os << std::setw(4) << std::right << cr.casesNum << " | ";
		os << std::setw(3) << std::right << cr.m_resolved << " |";
		return os;
	}

	std::list<Crime> CrimeStatistics::getListForProvince(const std::string& province) const {
		std::list<Crime> provinceCrimes;
		for (const auto& crime : crimes) {
			if (crime.province == province) {
				provinceCrimes.push_back(crime);
			}
		}
		return provinceCrimes;
	}


	
};