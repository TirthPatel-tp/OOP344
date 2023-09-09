#include <iomanip>

#include "Book.h"

using namespace std;

namespace sdds {

	Book::Book() {
		n_author = "";
		n_title = "";
		ncountry = "";
		n_year = 0;
		n_price = 0.0;
		n_descr = "";
	}

	const string& Book::title() const {
		return n_title;
	}

	const string& Book::country() const {
		return ncountry;
	}

	const size_t& Book::year() const {
		return n_year;
	}

	double& Book::price() {
		return n_price;
	}

	Book::Book(const std::string& string) {
		std::string a = string;
		size_t n = a.find(',');

		n_author = a.substr(0, n);
		n_author = subString(n_author, (int)n_author.length());

		std::string b = a.substr(n + 1);
		n = b.find(',');

		n_title = b.substr(0, n);
		n_title = subString(n_title, (int)n_title.length());

		std::string c = b.substr(n + 1);
		n = c.find(',');

		ncountry = c.substr(0, n);
		ncountry = subString(ncountry, (int)ncountry.length());

		std::string d = c.substr(n + 1);
		n = d.find(',');

		n_price = stod(d.substr(0, n));

		std::string e = d.substr(n + 1);
		n = e.find(',');

		n_year = stoi(e.substr(0, n));

		std::string f = e.substr(n + 1);
		n = f.find('\n');

		n_descr = f.substr(n + 1);
		n_descr = subString(n_descr, (int)n_descr.length());
	}

	std::ostream& operator << (std::ostream& os, Book& book) {
		os << setw(20) << setfill(' ') << right << book.n_author << " | " << setw(22) << book.n_title << " | " << setw(5) << book.ncountry << " | " << setw(4) << book.n_year << " | " << setw(6) << fixed << setprecision(2) << book.n_price << " | " << left << book.n_descr << endl;
		return os;
	}


	std::string& subString(std::string& string, int len) {
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