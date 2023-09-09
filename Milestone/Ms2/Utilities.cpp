/* Tirth Patel
  Id: 172244212
  Email: tpatel103@myseneca.ca */
#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::n_delimiter = '|';
	
	void trim(string& string)
	{
		if (string.length() > 0) {
			int begin = string.find_first_not_of(' ');
			int end = string.find_last_not_of(' ');
			if (begin == -1) string = "";
			else string = string.substr(begin, end - begin + 1);
		}
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		int next_del;
		string result;
		if (str[next_pos] == n_delimiter)
		{
			more = false;
			throw - 1;
		}

		else {
			string temp = str.substr(next_pos);
			if ((next_del = temp.find_first_of(n_delimiter)) != -1) {
				result = temp.substr(0, next_del);
				trim(result);
				next_pos += next_del + 1;
				more = true;
			}
			else {
				result = temp;
				trim(result);
				more = false;
			}
		}
		if (n_widthField < result.length())
			n_widthField = result.length();

		return result;
	}


	void Utilities::setFieldWidth(size_t width)
	{
		n_widthField = width;
	}


	size_t Utilities::getFieldWidth() const
	{
		return n_widthField;
	}

	

	void Utilities::setDelimiter(char newDelimiter)
	{
		n_delimiter = newDelimiter;
	}


	char Utilities::getDelimiter()
	{
		return n_delimiter;
	}

}