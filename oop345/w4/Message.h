//Oct 3rd 2018
//Hansol Cho hscho5@myseneca.ca
//#103608170
//Message.h
//Prof : Mahboob Ali
#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>
namespace w4 {
	class Message{

		std::string user_;
		std::string tweet_;
		std::string reply_;

	public:
		Message();
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
		void setempty();
	};
}
#endif