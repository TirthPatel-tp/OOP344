#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"


namespace sdds {

	class Restaurant {
		int n_numOfReservations{ 0 };
		Reservation** reservation{};


	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& restaurant);
		Restaurant(Restaurant&& restaurant);

		Restaurant& operator=(const Restaurant& restaurant);
		Restaurant& operator=(Restaurant&& restaurant);
		size_t size();

		~Restaurant();

		std::ostream& display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Restaurant& res);
}
#endif