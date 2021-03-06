// Name: Hansol Cho

// Seneca Student ID: 103608170

// Seneca email: hscho5@myseneca.ca

// Date of completion: Nov 22nd 2018

//

// I confirm that I am the only author of this file

//   and the content was created entirely by me.
#include <vector>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField;

CustomerOrder::CustomerOrder(const std::string& str) {
	std::string nextStr;
	Utilities util;
    m_cntItem = 0;
	bool more = true;
	size_t position = 0;
    size_t tempPos = 0;
	
	m_name = util.extractToken(str, position, more);
	if (more) {
		m_product = util.extractToken(str, position, more);
	}
	tempPos = position;
    
	do {
        
		nextStr = util.extractToken(str, position, more);
        if(nextStr != ""){
        ++m_cntItem;
        }
	} while (more);
	position = tempPos;
    more =true;
	m_lstItem = new ItemInfo*[m_cntItem];
	for (size_t i = 0; i<m_cntItem; i++) {
		nextStr = util.extractToken(str, position, more);
		m_lstItem[i] = new ItemInfo(nextStr);
    }
    if(m_widthField < util.getFieldWidth()){
    m_widthField = util.getFieldWidth();
    }
	/*
	while (more) {
		nextStr = util.extractToken(str, position, more);
		ItemInfo* tempItemInfo = new ItemInfo(nextStr);

		m_cntItem = (int)tempItem.size();
		m_lstItem = new ItemInfo*[m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++) {
			*m_lstItem[i] = tempItem[i];
		}

	}*/

}
CustomerOrder::CustomerOrder(CustomerOrder& cOrd) {
	throw std::string("No Copy Constructor accepted!!");
}
CustomerOrder::CustomerOrder(CustomerOrder&& custOrd) {
	*this = std::move(custOrd);
	
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& custOrd) {
    
	if (this != &custOrd) {
		if (m_lstItem) {
            for(size_t i =0; i< m_cntItem ;i ++){
               
                delete m_lstItem[i];
            }
            
            delete [] m_lstItem;
            m_lstItem = nullptr;
			
        }
		
		m_name = custOrd.m_name;
		m_product = custOrd.m_product;
		m_cntItem = custOrd.m_cntItem;
        m_widthField = custOrd.m_widthField;
        
        if(custOrd.m_lstItem != nullptr){
            m_lstItem = custOrd.m_lstItem;
            custOrd.m_lstItem =nullptr;
        }
        
	}

	return *this;

}
CustomerOrder::~CustomerOrder() {
	if (m_lstItem) {
		delete[] m_lstItem;
		m_lstItem = nullptr;
		m_cntItem = 0;
	}
}
bool CustomerOrder::getItemFillState(std::string str) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			return m_lstItem[i]->m_fillState;
		}
	}
	return true;
	}
bool CustomerOrder::getOrderFillState() const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false) {
			return false;
		}
	}
	return true;
}
void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item.getName() && m_cntItem >0) {
            this->m_lstItem[i]->m_fillState = true;
            item.updateQuantity();
            this->m_lstItem[i]->m_serialNumber = item.getSerialNumber();
            os<<"Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            break;
        }else if(m_lstItem[i]->m_itemName == item.getName()){
            os<< "Unable to filled" << m_name << m_product<<"[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            break;
        }
	}
}
void CustomerOrder::display(std::ostream& os) const {
    os<<m_name << " - " << m_product<< std::endl;
    
    if(m_lstItem && m_cntItem >0){
        for(size_t i =0; i<m_cntItem ; i++){
            os <<std::fixed<<"["<< std::left << std::setfill('0') << std::setw(6) << m_lstItem[i]->m_serialNumber <<  std::setfill(' ') << "] " <<std::setw(m_widthField)<< std::left << m_lstItem[i]->m_itemName << (m_lstItem[i]->m_fillState ? " - FILLED" : " - MISSING") <<std::endl;;
            
        }
    }
    
    
}

