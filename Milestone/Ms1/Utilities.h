

// Name: Patel Tirth kanubhai
// Seneca Student ID: 172244212
// Seneca email: tpatel103@myseneca.ca
// Date of completion: 21/07/23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>

namespace sdds
{
	class Utilities
	{
		size_t m_widthField = 1;
		static std::string m_delimiter;

	public:
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;

		static void setDelimiter(char newDelimiter);
		static std::string getDelimiter();

	};
}
#endif //SDDS_UTILITIES_H
