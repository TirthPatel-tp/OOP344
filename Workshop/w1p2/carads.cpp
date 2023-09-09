/******************************************************************
Module: carads.cpp
Name: Jai Sharma
Email: jsharma72@myseneca.ca
Student Id: 172522211
Date: May 18, 2022
******************************************************************/
#include <iomanip>
#include <string.h>
#include "carads.h"

using namespace std;

double g_taxrate = 0;
double g_discount = 0;

namespace sdds
{
	int listArgs(int argc, char* argv[])
	{
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;
		for (int i = 0; i < argc; i++)
		{
			cout << setw(3) << right << i + 1 << ": " << left << argv[i] << endl;
		}
		cout << "--------------------------\n"
			<< endl;
		return 0;
	}

	Cars::Cars()
	{
		car_Brand = nullptr;
		car_model[0] = '\0';
		car_year = 0;
		car_price = 0;
		car_status = 'N';
		car_promotion = false;
	}

	Cars::Cars(Cars& ogCar)
	{
		*this = ogCar;
	}

	Cars::~Cars()
	{
		delete[] car_Brand;
		car_Brand = nullptr;
	}

	Cars& Cars::operator=(Cars& ogCar)
	{
		if (car_model != nullptr)
		{
			delete[] car_Brand;
			car_Brand = nullptr;
		}
		car_price = ogCar.car_price;
		car_year = ogCar.car_year;
		car_promotion = ogCar.car_promotion;
		car_status = ogCar.car_status;
		strcpy(car_model, ogCar.car_model);
		car_Brand = new char[strlen(ogCar.car_Brand) + 1];
		strcpy(car_Brand, ogCar.car_Brand);
		return *this;
	}

	istream& Cars::read(istream& is)
	{
		if (is.good())
		{
			is >> car_status;
			is.ignore();
			char temp_Brand[2000];
			is.get(temp_Brand, 1999, ',');

			if (car_Brand != nullptr)
			{
				delete[] car_Brand;
				car_Brand = nullptr;
			}
			car_Brand = new char[strlen(temp_Brand) + 1];
			strcpy(car_Brand, temp_Brand);

			is.ignore();
			is.get(car_model, 14, ',');
			is.ignore();
			is >> car_year;
			is.ignore();
			is >> car_price;
			is.ignore(1, ',');
			char temp_promo;
			is >> temp_promo;
			if (is.good())
			{
				if (temp_promo == 'Y')
				{
					car_promotion = true;
				}
				else
				{
					car_promotion = false;
				}
			}
		}
		return is;
	}

	void Cars::display(bool reset)
	{
		static int counter = 0;
		if (reset)
		{
			counter = 0;
		}
		if ((car_Brand == nullptr || car_model[0] == '\0') && counter == 0)
		{
			cout << "COUNTER. No Car" << endl; // if there is no car
		}
		else if ((car_Brand == nullptr || car_model[0] == '\0'))
		{
			;
		}
		else
		{
			counter++;
			cout << setw(2) << left << counter << ". " << setw(10) << left << car_Brand << "| " << left << setw(15) << car_model << "| " << car_year << " |" << fixed << right << setw(12) << setprecision(2) << taxedval(car_price) << "|";

			if (car_promotion)
			{
				cout << fixed << right << setw(12) << setprecision(2) << taxedval(car_price - car_price * g_discount);
			}
			cout << endl;
		}
	}

	char Cars::getStatus() const
	{
		return car_status;
	}

	Cars::operator bool() const
	{
		if (getStatus() == 'N')
		{
			return true;
		}
		return false;
	}

	double taxedval(double val)
	{
		return (val + val * g_taxrate);
	}

	istream& operator>>(istream& is, Cars& car)
	{
		return car.read(is);
	}

	void operator>>(Cars& car1, Cars& car2)
	{
		car2 = car1;
	}
}