#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds {
	class Book {
		std::string n_author;
		std::string n_title;
		std::string ncountry;
		size_t n_year;
		std::string n_descr;

	public:
		double n_price;
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream& os, Book& b);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(n_descr);
		}
	};
	std::string& subString(std::string& val, int len);
}
#endif 