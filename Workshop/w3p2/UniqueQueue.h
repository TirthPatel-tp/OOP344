#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H


#include "Queue.h"

namespace sdds {

	template <typename T>
	class UniqueQueue :public Queue<T, 100> {
	public:
		bool push(const T& item) { 

			bool done = false;
			for (unsigned i = 0; i < Queue<T, 100>::size(); i++) {
				if (Queue<T, 100>::v_queue[i] == item) {
					return done;
				}
			}
			return Queue<T, 100>::push(item);
		}
	};


	template <>
	bool UniqueQueue<double>::push(const double& item) {
		bool done = false;
		for (unsigned i = 0; i < Queue <double, 100>::size(); i++) {

			if (std::abs(Queue<double, 100>::v_queue[i] - item) <= 0.005) {
				return done;
			}
		}
		return Queue<double, 100>::push(item);
	}
}
#endif 