


#include <string.h>
#include <iomanip>

#include "Reservation.h"

using namespace std;

namespace sdds {
	Reservation::Reservation() {
		n_reservationID = "";
		n_reservationName = "";
		n_email = "";
		n_personNum = 0;


		n_day = 0;
		n_hour = 0;
	}
	void Reservation::update(int day, int time) {
		n_day = day;
		n_hour = time;
	}

	Reservation::Reservation(const std::string& reservation) {
		std::string::size_type resString;

		string resID = reservation;
		resString = resID.find(':');

		n_reservationID = resID.substr(0, resString + 1);
		n_reservationID = trim(n_reservationID, (int)n_reservationID.length() - 1);

		string resName = resID.substr(resString + 1);
		resString = resName.find(',');

		n_reservationName = resName.substr(0, resString);
		n_reservationName = trim(n_reservationName, (int)n_reservationName.length());

		string email = resName.substr(resString + 1);
		resString = email.find(',');

		n_email = email.substr(0, resString);
		n_email = trim(n_email, (int)n_email.length());

		string people = email.substr(resString + 1);
		resString = people.find(',');

		n_personNum = stoi(people.substr(0, resString));

		string d = people.substr(resString + 1);
		resString = d.find(',');

		n_day = stoi(d.substr(0, resString));

		string h = d.substr(resString + 1);
		resString = h.find('\n');

		n_hour = stoi(h.substr(0, resString));
	}




	bool Reservation::operator==(const Reservation& res) const {
		return (n_reservationID == res.n_reservationID &&
			n_reservationName == res.n_reservationName
			&& n_email == res.n_email &&
			n_personNum == res.n_personNum &&
			n_day == res.n_day && n_hour == res.n_hour);
	}

	std::ostream& Reservation::display(std::ostream& os) const {
		string email = "  <" + n_email + ">";
		os.setf(ios::right);
		os << "Reservation ";
		os.width(10);
		os << n_reservationID << ":";
		os.width(21);
		os << n_reservationName;
		os.unsetf(ios::right);
		os.setf(ios::left);
		os.width(26);
		os << email;
		if (n_hour >= 6 && n_hour <= 9) os << "Breakfast on day ";
		else if (n_hour >= 11 && n_hour <= 15) os << "Lunch on day ";
		else if (n_hour >= 17 && n_hour <= 21) os << "Dinner on day ";
		else os << "Drinks on day ";
		os << n_day << " @ " << n_hour << ":00 for " << n_personNum << (n_personNum == 1 ? " person." : " people.") << endl;
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
		return reservation.display(os);
	}

	std::string& trim(std::string& string, int len) {
		int a = 0, b = 0;
		for (int i = 0; i < len; i++) {


			if (string[i] != ' ') {
				b = i;
				break;


			}
		}
		for (int i = len - 1; i >= 0; i--) {
			if (string[i] != ' ') {
				a = i;
				break;


			}
		}
		a = a - b + 1;
		string = string.substr(b, a);
		return string;
	}
}