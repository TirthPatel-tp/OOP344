#ifndef SDDS_CAR_H 
#define SDDS_CAR_H

#include <iostream>
#include <string>

#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		std::string n_maker;
		std::string n_condition;
		double n_topSpeed;

	public:
		Car()
		{
			n_maker = "";
			n_condition = "";
			n_topSpeed = 0.0;
		}
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string trim(std::string&);
	};
}

#endif 