#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {

		const Reservation** reservation{};
		int n_res{ 0 };

	public:
		ConfirmationSender();
		~ConfirmationSender();





		ConfirmationSender(const ConfirmationSender& confirmation);
		ConfirmationSender(ConfirmationSender&& confirmation);





		ConfirmationSender& operator=(const ConfirmationSender& confirmation);
		ConfirmationSender& operator=(ConfirmationSender&& confirmation);


		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		bool left(const Reservation& res);


		
		
		std::ostream& display(std::ostream& os) const;
	
	
	};
	
	
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmation);
}
#endif 