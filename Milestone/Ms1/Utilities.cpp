

// Name: Patel Tirth kanubhai
// Seneca Student ID: 172244212
// Seneca email: tpatel103@myseneca.ca
// Date of completion: 21/07/23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <stdexcept>

namespace sdds
{
	std::string Utilities::m_delimiter = "|";
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		size_t first_pos = next_pos;

		next_pos = str.find(m_delimiter, first_pos);

		if (first_pos == next_pos)
		{
			more = false;
			throw std::invalid_argument("delimiter");
		}

		std::string temp;
		if (next_pos == std::string::npos) {
			temp = str.substr(first_pos);
		}
		else {
			temp = str.substr(first_pos, next_pos - first_pos);
		}

		size_t width = std::max(temp.length(), m_widthField);
		setFieldWidth(width);

		more = (next_pos != std::string::npos);

		if (more)
		{
			next_pos++;
		}

		return temp;
	}

	void Utilities::setFieldWidth(size_t newWidth)
	{
		this->m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return this->m_widthField;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	std::string Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}

