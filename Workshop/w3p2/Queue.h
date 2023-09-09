#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include "Dictionary.h"

namespace sdds {

	template <typename T, unsigned int capacity>
	class Queue {
	protected:
		T v_queue[capacity];
		unsigned Size = 0;
		T object;

	public:
		Queue() : object() {
			Size = 0;
		}

		virtual ~Queue() {}

		virtual bool push(const T& item) {
			bool done = false;

			if (Size < capacity) {
				v_queue[size()] = item;
				Size++;
				done = true;
			}

			return done;
		}

		T pop() {
			T temp = v_queue[0];

			for (unsigned i = 0; i < Size - 1; i++) {
				v_queue[i] = v_queue[i + 1];
			}
			Size--;
			return temp;
		}

		unsigned size() const {
			return Size;
		}

		T& operator[](unsigned index)
		{
			if (index >= size())
			{
				return object;
			}
			else return v_queue[index];
		}

		std::ostream& display(std::ostream& ostr = std::cout) const {
			ostr << "----------------------\n";
			ostr << "| Dictionary Content |\n";
			ostr << "----------------------\n";
			for (unsigned i = 0; i < size(); i++) {
				ostr << v_queue[i] << std::endl;
			}
			ostr << "----------------------" << std::endl;
			return ostr;
		}

	};

	template<>
	Dictionary& Queue<Dictionary, 100u>::operator[](unsigned index) {
		if (index > Size) {
			v_queue[index].set("Empty Term", "Empty Substitute");
		}
		return v_queue[index];
	}
}
#endif