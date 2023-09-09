#include "Restaurant.h"

namespace sdds {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		n_numOfReservations = cnt;
		reservation = new Reservation * [cnt + 1];
		for (int i = 0; i < (int)cnt; i++)
		{
			reservation[i] = new Reservation(*reservations[i]);
		}
	}

	Restaurant::Restaurant(const Restaurant& restaurant) {
		*this = restaurant;
	}

	Restaurant::Restaurant(Restaurant&& restaurant) {
		*this = std::move(restaurant);
	}

	Restaurant::~Restaurant()
	{
		for (int i = 0; i < n_numOfReservations; i++) delete reservation[i];
		delete[] reservation;
	}

	Restaurant& Restaurant::operator=(const Restaurant& restaurant) {
		if (this != &restaurant)
		{
			for (int i = 0; i < n_numOfReservations; i++) delete reservation[i];
			delete[] reservation;

			n_numOfReservations = restaurant.n_numOfReservations;
			reservation = new Reservation * [restaurant.n_numOfReservations + 1];

			for (int i = 0; i < restaurant.n_numOfReservations; i++) {
				reservation[i] = new Reservation(*restaurant.reservation[i]);
			}
		}

		return *this;
	}

	Restaurant& Restaurant::operator=(Restaurant&& restaurant) {
		if (this != &restaurant) {
			delete[] reservation;

			n_numOfReservations = restaurant.n_numOfReservations;

			reservation = restaurant.reservation;
			restaurant.reservation = nullptr;
			restaurant.n_numOfReservations = 0;
		}

		return *this;
	}

	size_t Restaurant::size() {
		return n_numOfReservations;
	}

	std::ostream& Restaurant::display(std::ostream& os) const {
		static int callCount = 0;
		callCount++;
		os << "--------------------------\n";
		os << "Fancy Restaurant (" << callCount << ")\n";
		os << "--------------------------\n";
		if (n_numOfReservations == 0) os << "This restaurant is empty!\n";
		else for (int i = 0; i < n_numOfReservations; i++) os << *reservation[i];
		os << "--------------------------" << std::endl;

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
		return restaurant.display(os);
	}
}