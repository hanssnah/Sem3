//Oct 3rd 2018
//Hansol Cho hscho5@myseneca.ca
//#103608170
//Notifications.cpp
//Prof : Mahboob Ali
#include <iostream>
#include "Notifications.h"
#include "Message.h"

using namespace std;
namespace w4 {
	//default constructor
	Notifications::Notifications() {
		my_msg = new Message[MAXMSG];
		count = 0;

	}

	//copy constructor
	Notifications::Notifications(const Notifications& src) {
		*this = src;
	}
	//copy assignment operator
	Notifications& Notifications::operator=(const Notifications& src) {
		if (this != &src) {
			my_msg = new Message[MAXMSG];
			for (int i = 0; i < MAXMSG; i++) {
				this->my_msg[i] = src.my_msg[i];
				count = src.count;
			}
		}
		return *this;

	};
	//move constructor
	Notifications::Notifications(Notifications&& src) {
		*this = move(src);
	}
	//move assignment operator
	Notifications& Notifications::operator= (Notifications&& src) {
		if (this != &src) {
			my_msg = new Message[MAXMSG];
			for (int i = 0; i < MAXMSG; ++i) {
				this->my_msg[i] = src.my_msg[i];
			}
			this->count = src.count;
			src.my_msg = nullptr;
		}
		return *this;
	}
	//destructor
	Notifications::~Notifications() {
		delete[] my_msg;
	}
	//operator adds msg to the set
	void Notifications::operator+=(const Message& msg) {
		if (count < MAXMSG) {
			my_msg[count] = msg;
			count++;
		}
		if (count == 0) {
			my_msg = new Message[MAXMSG];
		}
	}

	//insert the msg objects to the os output stream
	void Notifications::display(std::ostream& os) const {
		for (size_t i = 0; i < count; ++i) {
			my_msg[i].display(os);
		}
	}


}