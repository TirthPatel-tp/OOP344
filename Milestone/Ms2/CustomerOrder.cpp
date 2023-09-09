/* Tirth Patel
  Id: 172244212
  Email: tpatel103@myseneca.ca */
#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	size_t CustomerOrder::n_widthField = 0;
	
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		size_t pos = 0;
		Utilities u;
		
		bool flag = true;
		
		n_name = u.extractToken(str, pos, flag);
		n_product = u.extractToken(str, pos, flag);
		
		vector<Item*> v;
		Item* I;
		
		while (flag) {
			I = new Item(u.extractToken(str, pos, flag));
			v.push_back(I);
		}
		n_cntItem = v.size();
		n_lstItem = new Item * [n_cntItem];
		for (size_t i = 0; i < n_cntItem; i++) {
			n_lstItem[i] = v[i];
		}

		if (CustomerOrder::n_widthField <= u.getFieldWidth()) {
			CustomerOrder::n_widthField = u.getFieldWidth();
		}

	}

	CustomerOrder::CustomerOrder(const CustomerOrder& I)
	{
		throw "invalid";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& I) noexcept
	{
		*this = std::move(I);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept
	{
		if (this != &other) {
			for (size_t i = 0; i < n_cntItem; i++) delete n_lstItem[i];
			delete[] n_lstItem;
			n_name = other.n_name;
			n_product = other.n_product;
			n_cntItem = other.n_cntItem;
			n_lstItem = other.n_lstItem;
			other.n_lstItem = nullptr;
			other.n_cntItem = 0;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < n_cntItem; i++) delete n_lstItem[i];
		delete[] n_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool status = true;
		for (size_t i = 0; i < n_cntItem && status; i++) {
			if (n_lstItem[i]->n_isFilled == false)
			{
				status = false;
			}
		}
		return status;

	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool status = true;
		for (size_t i = 0; i < n_cntItem && status; i++)
		{
			if (n_lstItem[i]->n_itemName == itemName && n_lstItem[i]->n_isFilled == false)
			{
				status = false;
			}
		}
		return status;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < n_cntItem; i++) {
			Item* currentItem = n_lstItem[i];

			if (currentItem->n_itemName == station.getItemName() && !currentItem->n_isFilled) {
				if (station.getQuantity() >= 1) {
					station.updateQuantity();
					currentItem->n_serialNo = station.getNextSerialNumber();
					currentItem->n_isFilled = true;

					os << "    Filled " << n_name << ", " << n_product << " [" << currentItem->n_itemName << "]" << std::endl;
				}
				else {
					os << "    Unable to fill " << n_name << ", " << n_product << " [" << currentItem->n_itemName << "]" << std::endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << n_name << " - " << n_product << endl;
		
		for (size_t i = 0; i < n_cntItem; i++) {
			os << "[" << setw(6) << setfill('0') << n_lstItem[i]->n_serialNo << "] "
			   << left << setw(n_widthField) << setfill(' ') << n_lstItem[i]->n_itemName << " - " 
				<< (n_lstItem[i]->n_isFilled ? "FILLED" : "TO BE FILLED") << endl;
		}
	}
}