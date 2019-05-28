// Name: Hansol Cho

// Seneca Student ID: 103608170

// Seneca email: hscho5@myseneca.ca

// Date of completion: Nov 30th 2018

//

// I confirm that I am the only author of this file

//   and the content was created entirely by me.
#include <vector>
#include <string>
#include <iostream>
#include "Utilities.h"
#include "Task.h"


Task::Task(const std::string& str) : Item(str){
    m_pNextTask = nullptr;
    
}

void Task::runProcess(std::ostream& os){
    if(!m_orders.empty()){
        while(!m_orders.back().getItemFillState(getName())){
        
             
                m_orders.back().fillItem(*this, os);
                
            
            
        }
    }
}

bool Task::moveTask(){
    if(m_orders.size() <1){
        return false;
    }
    if(m_orders.back().getItemFillState(getName())){
        if(m_pNextTask){
         
            (*m_pNextTask) += std::move(m_orders.back());
            m_orders.pop_back();

        }return true;
    }
        return false;
    
}

void Task::setNextTask(Task& _task){
    if(m_pNextTask ) {
        delete m_pNextTask;
    }
    
    m_pNextTask = &_task;
}

bool Task::getCompleted(CustomerOrder& cusord){
    if(m_orders.size() <1){
        return false;
    }
    if(m_orders.back().getOrderFillState()){
     
        cusord = std::move(m_orders.back());
        m_orders.pop_back();
        return true;
        
    }
    return false;
    
}

void Task::validate(std::ostream& os){
    os<< this->getName() << " --> ";
    if(m_pNextTask){
        os<< m_pNextTask->getName();
    }else{
        os<<"END OF LINE";
    }
    os<<std::endl;
}

Task& Task::operator+= (CustomerOrder&& cusord){
    m_orders.push_front(std::move(cusord));
    return *this;
}
