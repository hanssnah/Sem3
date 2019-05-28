// Name: Hansol Cho
// Seneca Student ID: 103608170
// Seneca email: hsscho5@myseneca.ca
// Date of completion: 11/16/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField;
char Utilities::m_delimiter;

Item::Item(std::string& str) {

	std::vector<std::string> nextStr;
	Utilities util;
	bool more = true;
	size_t position = 0;

	m_name = util.extractToken(str,position,more);
    
	if (more) {
		m_serialNumber = stoi(util.extractToken(str, position, more));
	}
	if (more) {
		m_quantity = stoi(util.extractToken(str, position, more));
	}
    
    m_widthField = util.getFieldWidth();
    
	if (more) {
		m_description = util.extractToken(str, position, more);
	}
	
	



	/*
	while (more) 
		nextStr.push_back(util.extractToken(str, position, more));
	
		m_name = nextStr[0];
		m_serialNumber = std::stoi(nextStr[1]);
		m_quantity = std::stoi(nextStr[2]);
		m_desscription = nextStr[3];


		m_widthField = util.getFieldWidth();
	*/

}
const std::string& Item::getName() const {
	return m_name;
};
const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
};
const unsigned int Item::getQuantity() {
	return m_quantity;
};
void Item::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity--;
	}
};
void Item::display(std::ostream& os, bool full) const {



	if (full) {
		os << std::fixed << std::setw(m_widthField) << std::left << m_name << " ["
			<< std::setw(6) << std::setfill('0') << std::right << m_serialNumber << std::setfill(' ') << "]"
			<< " Quantity: " << std::setw(m_widthField) << std::left
			<< m_quantity << std::right << " Description: " << m_description
			<< std::endl << std::setfill(' ');
	}
	else {

		os << std::fixed << std::setw(m_widthField) << std::left << m_name << " ["
			<< std::setw(6) << std::setfill('0') << std::right << m_serialNumber << std::setfill(' ') << "]" << std::endl;
	}
};
