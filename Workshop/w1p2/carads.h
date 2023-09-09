/******************************************************************
Module: carads.h
Name: Jai Sharma
Email: jsharma72@myseneca.ca
Student Id: 172522211
Date: May 18, 2022
******************************************************************/

#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

#include <iostream>

extern double g_taxrate; // tax rate
extern double g_discount; //discount percent

namespace sdds
{
	int listArgs(int argc, char* argv[]);

	class Cars
	{
		double car_price{}; //car price
		int car_year{}; //year of make
		bool car_promotion{}; //true if car is on discount
		char car_status{}; // 'N' if new, 'U' if used
		char* car_Brand{}; //brand
		char car_model[15]{}; //model name

	public:
		Cars();
		Cars(Cars&);
		~Cars();
		Cars& operator=(Cars&);

		std::istream& read(std::istream& is); //reads the information from text file
		void display(bool reset); // outputs the information in specified format
		char getStatus() const; //return 'N' if new else 'U'

		operator bool() const; //return true if car is new
	};

	double taxedval(double val); //returns the amount after tax rates are applied
	std::istream& operator>>(std::istream& is, Cars& car); //performs same functions as read function
	void operator>>(Cars& car1, Cars& car2); // performs same fucntions as copy assignment operator for Cars class
}

#endif