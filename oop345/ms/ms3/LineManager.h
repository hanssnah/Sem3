// Name: Hansol Cho

// Seneca Student ID: 103608170

// Seneca email: hscho5@myseneca.ca

// Date of completion: Nov 30th 2018

//

// I confirm that I am the only author of this file

//   and the content was created entirely by me.
#ifndef MS_LINEMANAGER_H
#define MS_LINEMANAGER_H

#include <iostream>
#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Item.h"
#include "Task.h"


class LineManager{
    std::vector<Task*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;
public:
    LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const;
};

#endif /* LineManager_h */
