// Name: Hansol Cho
// Seneca Student ID: 103608170
// Seneca email: hsscho5@myseneca.ca
// Date of completion: 11/16/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <sstream>
#include "Utilities.h"

Utilities::Utilities() {
};
void Utilities::setFieldWidth(size_t _wdt) {
	m_widthField = _wdt;

};
size_t Utilities::getFieldWidth() const {
	return m_widthField;
};
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string nextStr;

	if ( next_pos != str.length() && more)
	{
		int position = str.find_first_of(getDelimiter(), next_pos);

		nextStr = str.substr(next_pos, position - next_pos);

		m_widthField = (m_widthField < nextStr.length() && next_pos == 0)
			? nextStr.length() : m_widthField;

		next_pos = (str.find_first_of(getDelimiter(), next_pos) != SIZE_MAX)
			? position + 1 : str.length();
	}
	else
	{
		more = false;
	}

	return nextStr;
	


};
void Utilities::setDelimiter(const char dlim) {
	m_delimiter = dlim;
};
const char Utilities::getDelimiter() const {
	return m_delimiter;
};
