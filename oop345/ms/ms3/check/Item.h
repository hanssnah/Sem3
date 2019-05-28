// Name: Hansol Cho
// Seneca Student ID: 103608170
// Seneca email: hsscho5@myseneca.ca
// Date of completion: 11/16/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#pragma once
#ifndef MS_ITEM_H
#define MS_ITEM_H
#include <iostream>
#include <string>
#include "Utilities.h"


class Item{
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity;

public:
    
    static size_t m_widthField;
	//custom constructor
	Item(const std::string&);
	//getter for name
	const std::string& getName() const;
	//getter for serial number
	const unsigned int getSerialNumber();
	//getter for quantity
	const unsigned int getQuantity();
	//update the quantity (selling)
	void updateQuantity();
	//display function
	void display(std::ostream& os, bool full) const;
};


#endif // !MS_ITEM_H
