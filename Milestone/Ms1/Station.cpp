

// Name: Patel Tirth kanubhai
// Seneca Student ID: 172244212
// Seneca email: tpatel103@myseneca.ca
// Date of completion: 21/07/23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"

namespace sdds
{
	unsigned Station::n_widthField = 0;
	unsigned Station::id_genereator = 0;



	Station::Station(const std::string& str)
	{
		Utilities temp;
		bool o = false;
		this->n_stationID = ++id_genereator;
		size_t start = 0;
		size_t end = str.find(Utilities::getDelimiter());
		this->n_itemName = str.substr(start, end);
		this->n_itemName = n_itemName.substr(n_itemName.find_first_not_of(" "));
		start = end + 1;
		end = str.find(Utilities::getDelimiter(), start);
		this->Number = std::stoi(temp.extractToken(str, start, o));
		start = end + 1;
		end = str.find(Utilities::getDelimiter(), start);
		this->inStock = std::stoi(temp.extractToken(str, start, o));
		start = end + 1;
		this->n_stationDesc = str.substr(start);
		this->n_stationDesc = n_stationDesc.substr(n_stationDesc.find_first_not_of(" "));

		n_widthField = (n_widthField < n_itemName.length()) ? static_cast<int>(n_itemName.length() + 1) : n_widthField;

	}


	void Station::updateQuantity()
	{
		if (inStock > 0) {
			inStock--;
		}
	}

	void Station::display(std::ostream& os, bool full) const {
		if (!full) {
			os << std::setfill('0') << std::setw(3) << std::right << n_stationID;
			os << " | ";
			os << std::setfill(' ') << std::setw(n_widthField - 1) << std::left << n_itemName;
			os << "| ";
			os << std::setfill('0') << std::setw(6) << std::right << Number;
			os << " | ";
			os << std::endl;
		}
		else {
			os << std::setfill('0') << std::setw(3) << std::right << n_stationID;
			os << " | ";
			os << std::setfill(' ') << std::setw(n_widthField - 1) << std::left << n_itemName;
			os << "| ";
			os << std::setfill('0') << std::setw(6) << std::right << Number;
			os << " | ";
			os << std::setfill(' ') << std::setw(4) << this->getQuantity();
			os << " | ";
			os << n_stationDesc;
			os << std::endl;
		}
	}

	const std::string& Station::getItemName() const
	{
		return n_itemName;
	}

	size_t Station::getNextSerialNumber()
	{
		return Number++;
	}

	size_t Station::getQuantity() const
	{
		return inStock;
	}


}
