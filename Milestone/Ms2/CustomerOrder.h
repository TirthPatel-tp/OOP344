/* Tirth Patel
  Id: 172244212
  Email: tpatel103@myseneca.ca */
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <string>
#include "Station.h"
namespace sdds {
	struct Item
	{
		std::string n_itemName;
		size_t n_serialNo{ 0 };
		bool n_isFilled{ false };

		Item(const std::string& src) : n_itemName(src) {};
	};


	class CustomerOrder {
		std::string n_name{};
		std::string n_product{};
		size_t n_cntItem{};
		Item** n_lstItem{};
		static size_t n_widthField;
	public:
		CustomerOrder(){}
		CustomerOrder(const std::string& sring);
		CustomerOrder(const CustomerOrder& obj);
		CustomerOrder& operator=(const CustomerOrder& other) = delete;
		CustomerOrder(CustomerOrder&& obj) noexcept;
		CustomerOrder& operator=(CustomerOrder&& other) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif //SDDS_CUSTOMERORDER_H