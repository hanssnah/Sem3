// Name: Hansol Cho

// Seneca Student ID: 103608170

// Seneca email: hscho5@myseneca.ca

// Date of completion: Nov 22nd 2018

//

// I confirm that I am the only author of this file

//   and the content was created entirely by me.
#pragma once
#ifndef MS_CUSTOMERORDER_H
#define MS_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Item.h"
#include "Utilities.h"

struct ItemInfo{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
    ItemInfo** m_lstItem = nullptr;

	public:
    
    static size_t m_widthField;
    CustomerOrder();
	CustomerOrder(const std::string&);
	CustomerOrder( CustomerOrder&);
	CustomerOrder& operator= (const CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&)  noexcept;
    CustomerOrder& operator =(CustomerOrder&&) ;
	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;

};
#endif
