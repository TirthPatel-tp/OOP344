#ifndef SDDS_AUTOSHOP_H 
#define SDDS_AUTOSHOP_H

#include "Vehicle.h"

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> n_vehicles;
	public:
		Autoshop() {};
		Autoshop& operator+=(Vehicle* v);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			std::for_each(n_vehicles.begin(), n_vehicles.end(), [&](const auto& vehicle) {
				if (test(vehicle)) {
					vehicles.push_back(vehicle);
				}
				});
		}
		~Autoshop();
	};
}
#endif 