#include "Autoshop.h"

#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		n_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (auto i = n_vehicles.begin(); i != n_vehicles.end(); i++) {
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}

	Autoshop::~Autoshop() {
		while (!n_vehicles.empty()) {
			delete n_vehicles.back();
			n_vehicles.pop_back();
		}
	}
}