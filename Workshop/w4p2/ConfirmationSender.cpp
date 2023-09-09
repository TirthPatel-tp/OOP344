
#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::ConfirmationSender() {
		reservation = nullptr;
		n_res = 0;
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] reservation;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& confirmation) {
		*this = confirmation;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& confirmation) {
		if (this != &confirmation) {
			delete[] reservation;

			n_res = confirmation.n_res;
			reservation = new const Reservation * [confirmation.n_res + 1];
			for (int i = 0; i < confirmation.n_res; i++)
			{
				reservation[i] = confirmation.reservation[i];
			}
		}

		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& confirmation) {
		*this = std::move(confirmation);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& confirmation) {
		if (this != &confirmation) {
			delete[] reservation;

			n_res = confirmation.n_res;

			reservation = confirmation.reservation;
			confirmation.reservation = nullptr;
			confirmation.n_res = 0;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		if (!left(res)) {
			const Reservation** temp = new const Reservation * [n_res];
			for (int i = 0; i < n_res; i++) {
				temp[i] = reservation[i];
			}

			delete[] reservation;
			n_res++;
			reservation = new const Reservation * [n_res];

			for (int i = 0; i < n_res - 1; i++) {
				reservation[i] = temp[i];
			}

			reservation[n_res - 1] = &res;
			delete[] temp;
		}

		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		if (left(res)) {
			int number = -1;
			for (int i = 0; i < n_res; i++)
			{
				if (*reservation[i] == res)
					number = i;
			}

			if (number > -1) {
				reservation[number] = nullptr;
				n_res--;
				for (int i = number; i < n_res; i++) reservation[i] = reservation[i + 1];
			}
		}

		return *this;
	}

	bool ConfirmationSender::left(const Reservation& res) {
		bool left = false;
		for (int i = 0; i < n_res; i++) {
			if (*reservation[i] == res) left = true;
		}
		return left;
	}

	std::ostream& ConfirmationSender::display(std::ostream& os) const {
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";

		if (n_res == 0) os << "There are no confirmations to send!\n";
		else for (int i = 0; i < n_res; i++) os << *reservation[i];

		os << "--------------------------" << std::endl;

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmation) {
		return confirmation.display(os);
	}
}