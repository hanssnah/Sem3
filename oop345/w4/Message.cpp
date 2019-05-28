//Oct 3rd 2018
//Hansol Cho hscho5@myseneca.ca
//#103608170
//Message.cpp
//Prof : Mahboob Ali
#include <iostream>
#include <fstream>
#include "Message.h"

using namespace std;

namespace w4 {
	//set variables empty
	void Message::setempty() {
		user_[0] = '\0';
		tweet_[0] = '\0';
		reply_[0] = '\0';
	}
	//default constructor
	Message::Message() {
		setempty();
	}
	//get record from in file and store in msg object. c is the delimiter
	Message::Message(std::ifstream& in, char c) {
		if (in.is_open()) {
			string str;
			getline(in, str, c); // get the line from file and store into string obj
			
			int counter = 0;

			unsigned long findEnd = str.find('\n'); // find the end from the string
			if (findEnd != string::npos) { // if findEnd is not the maxsize of size_t
				str.erase(findEnd);		   // erase findEnd from the string
			}

			for (size_t i = 0; i < str.size()&& str[i] !=' '; ++i) { // looping til size of string
				if (str[i] != ' ') {				  // if index of string is not empty
					user_ += str[i];				  // store into user
					counter++;						  // increase counter
				}
			}

			str.erase(0, counter + 1);				  // find next reply

			unsigned long findEmptySpace = str.find(' ');

			if (str[0] == '@') {
				for (size_t i = 1; i < findEmptySpace; ++i) {
					reply_ += str[i];
				}
				findEmptySpace = str.find(' ');
				str.erase(0, findEmptySpace+1);   // delete empty space
			}

			//treat it if theres no more space, its tweet
			for (size_t i = 0; i < str.size(); ++i) {
				tweet_ += str[i];
			}
		}

	}
	bool Message::empty() const {
		return tweet_[0] == '\0';
	}
	void Message::display(std::ostream& os) const {
		os << "Message" << endl;
		os << " User  : " << user_ << endl;
		if (!reply_.empty()) {
			os << " Reply : " << reply_ << endl;
		}
		os << " Tweet : " << tweet_ << endl;
		os << endl;
	}
	
}