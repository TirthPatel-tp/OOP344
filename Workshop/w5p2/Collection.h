#ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
	template<typename T>
	class Collection
	{
		string n_name;
		T* n_item;
		size_t n_size;
		void (*observer)(const Collection<T>&, const T&) = nullptr;

	public:

		Collection(const string& name) :n_item{}, n_size(0)
		{
			n_name = name;
		}

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

		~Collection()
		{
			delete[] n_item;
		}

		const string& name() const
		{
			return n_name;
		}

		size_t size() const
		{
			return n_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->observer = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			for (auto i = 0u; i < n_size; i++)
			{
				if (this->n_item[i].title() == item.title())
				{
					return *this;
				}
			}

			T* temp = nullptr;
			temp = new T[n_size + 1];

			for (auto i = 0u; i < n_size; i++)
			{
				temp[i] = this->n_item[i];
			}

			temp[n_size] = item;
			delete[] n_item;

			n_item = temp;

			++n_size;

			if (this->observer != nullptr)
			{
				observer(*this, n_item[n_size - 1]);
			}
			return *this;
		}

		T& operator[](size_t index) const
		{
			if (index >= n_size)
			{
				string errorMsg = "Bad index [";
				errorMsg += to_string(index);
				errorMsg += "]. Collection has [";
				errorMsg += to_string(n_size);
				errorMsg += "] items.";
				throw out_of_range(errorMsg);
			}
			return this->n_item[index];
		}

		T* operator[](string title) const
		{
			bool done = false;
			T* temp = nullptr;

			for (size_t i = 0; i < n_size; i++)
			{
				if (n_item[i].title() == title)
				{
					done = true;
					temp = &n_item[i];
				}
			}
			if (done == false)
			{
				return nullptr;
			}
			else
			{
				return temp;
			}
		}
	};

	template<typename T>
	ostream& operator<<(ostream& os, const Collection<T>& value)
	{
		for (size_t i = 0; i < value.size(); i++)
		{
			os << value[i];
		}
		return os;
	}
}
#endif