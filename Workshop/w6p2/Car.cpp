#include <iomanip>
#include "Car.h"
using namespace std;
namespace sdds {

	Car::Car(std::istream& str) {
		std::string tag;
		if (!std::getline(str, tag, ','))
			throw std::runtime_error("Invalid record!");

		n_maker = trim(tag);

		if (!std::getline(str, tag, ','))
			throw "Invalid record!";
		trim(tag);

		if (tag == "n" || tag == "")
			n_condition = "new";
		else if (tag == "u")
			n_condition = "used";
		else if (tag == "b")
			n_condition = "broken";
		else
			throw "Invalid record!";

		if (!std::getline(str, tag, ','))
			throw "Invalid record!";

		try {
			n_topSpeed = std::stoi(trim(tag));
		}
		catch (const std::exception&) {
			throw "Invalid record!";
		}
	}

	void Car::display(ostream& out) const {
		out << "| " << setw(10) << right << n_maker << " | " << setw(6) << left << n_condition << " | " << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
	};

	string Car::condition() const {
		return n_condition;
	};

	double Car::topSpeed() const {
		return n_topSpeed;
	};

	std::string Car::trim(std::string& str)
	{
		size_t startPos = str.find_first_not_of(' ');
		size_t endPos = str.find_last_not_of(' ');
		if (startPos != std::string::npos && endPos != std::string::npos) {
			str = str.substr(startPos, endPos - startPos + 1);
		}
		else {
			str.clear();
		}

		return str;
	}

}