#include <sstream>
#include <string>

#include "Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string i;
		char type = '\0';
		char extractData = '\0';
		std::getline(in, i);
		std::stringstream str(i);
		str >> type >> extractData;
		if (str) {
			switch (type)
			{
			case 'r':
			case 'R':
				return new Racecar(str);
				break;
			case 'c':
			case 'C':
				return new Car(str);
				break;
			default:
				throw type;
				break;
			}
		}
		return nullptr;
	}
}