// Name: Hansol Cho

// Seneca Student ID: 103608170

// Seneca email: hscho5@myseneca.ca

// Date of completion: Nov 30th 2018

//

// I confirm that I am the only author of this file

//   and the content was created entirely by me.
#include <fstream>
#include <string>
#include <functional>
#include "Utilities.h"
#include "LineManager.h"


std::deque<size_t> taskIndex;
size_t k = 0;

LineManager::LineManager(const std::string& str, std::vector<Task*>& _task, std::vector<CustomerOrder>& _cusord){
    std::ifstream file(str);
    
    if(file){
    
    Utilities util;    std::string token;
    std::string temp;
        
        while(!file.eof()){
            
            bool more =true;
            size_t position =0;

            std::getline(file,temp);
            token = util.extractToken(temp,position,more);
            
            
            
            for(size_t i = 0; i < _task.size(); i++) {
                if(_task[i]->getName() == token) {
                    taskIndex.push_back(i);
                    
                    
                    if(more) {
                        token = util.extractToken(temp, position, more);
                        for(size_t j = 0; j < _task.size(); j++) {
                            if(_task[j]->getName() == token) {
                                _task[i]->setNextTask(*_task[j]);
                            }
                        }
                    }
                    i = _task.size();
                }
            }
        }
    
    }
    
    
    for(size_t i= 0; i<_task.size(); i++){
        AssemblyLine.push_back(_task[i]);
    }
    
    for(size_t i=0; i<_cusord.size();i++){
        ToBeFilled.push_front(std::move(_cusord[i]));
      
    }
    m_cntCustomerOrder = ToBeFilled.size();
 
}
bool LineManager::run(std::ostream& os){
  
     if(ToBeFilled.size()) {
        
        AssemblyLine[taskIndex[k]]->operator+=(std::move(ToBeFilled.back()));
        
        ToBeFilled.pop_back();
    }
    
    for(size_t i = 0; i < AssemblyLine.size(); i++) {
        AssemblyLine[i]->runProcess(os);
    }
    for(size_t i = 0; i < AssemblyLine.size(); i++) {
        if ( AssemblyLine[i]->moveTask() ) {
            
            
            CustomerOrder temp;
            if ( AssemblyLine[i]->getCompleted(std::ref(temp)) ) {
                Completed.push_back(std::move(temp));
            }
        }
    }
    
    
    if(Completed.size() == m_cntCustomerOrder && !ToBeFilled.size()){
        return true;
    }else{
        return false;
    }
    

}
void LineManager::displayCompleted(std::ostream& os) const{
    for(size_t i =0; i<Completed.size(); i++){
        Completed[i].display(os);
    }
}
void LineManager::validateTasks() const{
    for(size_t i = 0ul; i < AssemblyLine.size(); i++) {
        AssemblyLine[i]->validate(std::cout);
        
    }
}
