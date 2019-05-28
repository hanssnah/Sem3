//Oct 3rd 2018
//Hansol Cho hscho5@myseneca.ca
//#103608170
//Notifications.h
//Prof : Mahboob Ali
#pragma once
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <iostream>
#include <fstream>
#include "Message.h"


namespace w4 {

	const int MAXMSG = 10;

	class Notifications{

		Message *my_msg;
		size_t count;

	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator= (Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

#endif