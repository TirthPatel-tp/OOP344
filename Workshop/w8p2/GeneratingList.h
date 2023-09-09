// Patel Tirth 
// Id: 172244212
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		bool sinValid(const std::string& sin) {
			int len = (int)sin.length();
			int num = 0;
			bool even = false;
			for (int i = len - 1; i >= 0; i--) {
				int d = sin[i] - '0';

				if (even)
					d = d * 2;

				num += d / 10;
				num += d % 10;

				even = !even;
			}

			return (num % 10 == 0);
		}

		void operator+=(std::shared_ptr<T> value) {
			list.push_back(*value);
		}

		void operator+=(const T* value) {
			list.push_back(*value);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif //SDDS_GENERATINGLIST_H