#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {
	class Reservation {
		std::string n_reservationID{};
		std::string n_reservationName{};
		std::string n_email{};
		int n_personNum{};
		int n_day{};
		int n_hour{};



	public:
		Reservation();
		Reservation(const std::string& res);



		bool operator==(const Reservation& res) const;
		void update(int day, int time);


		~Reservation() {  }
		std::ostream& display(std::ostream& os) const;


	};


	std::ostream& operator<<(std::ostream& os, const Reservation& res);
	std::string& trim(std::string& string, int len);
}
#endif