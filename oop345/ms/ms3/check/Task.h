// Name: Hansol Cho

// Seneca Student ID: 103608170

// Seneca email: hscho5@myseneca.ca

// Date of completion: Nov 30th 2018

//

// I confirm that I am the only author of this file

//   and the content was created entirely by me.
#ifndef MS_TASK_H
#define MS_TASK_H

#include <deque>
#include "Item.h"
#include "CustomerOrder.h"

class Task: public Item{
    std::deque<CustomerOrder> m_orders;
    Task * m_pNextTask;
    
public:
    Task(const std::string&);
    Task(const Task&) =delete;
    Task(const Task&&) = delete;
    Task& operator = (Task&) = delete;
    Task& operator = (Task&&) = delete;
    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream&);
    Task& operator+=(CustomerOrder&&);
    
};


#endif /* Task_hpp */
