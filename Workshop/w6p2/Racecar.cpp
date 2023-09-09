#include <string>
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string strCar;
		std::getline(in, strCar, ',');
		n_booster = std::stod(Car::trim(strCar));
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + n_booster);
	}

}