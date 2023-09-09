/* Tirth Patel
  Id: 172244212
  Email: tpatel103@myseneca.ca */
#ifndef _SDDS_STATION_H
#define _SDDS_STATION_H

#include"Utilities.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<limits>

namespace sdds
{
	class Station
	{
		int n_stationID{};
		std::string n_itemName{};
		std::string n_stationDesc{};
		unsigned int sNumber{};
		unsigned int inStock{};
		static unsigned n_widthField;
		static unsigned id_genereator;

	public:
		Station(const std::string& record);
		
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

		const std::string& getItemName() const;
		std::size_t getNextSerialNumber();
		std::size_t getQuantity() const;
	};

}
#endif//SDDS_STATION_H