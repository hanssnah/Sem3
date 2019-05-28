// Name: Hansol Cho
// Seneca Student ID: 103608170
// Seneca email: hsscho5@myseneca.ca
// Date of completion: 11/16/2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
#pragma once
#ifndef MS_UTILITIES_H
#define MS_UTILITIES_H
#include <iostream>
#include <string>

	class Utilities {
		size_t m_widthField = 1;
		static char m_delimiter;

	public:
		//constructor
		Utilities();
		//setter for width
		void setFieldWidth(size_t);
		//getter for width
		size_t getFieldWidth() const;
		//extract tokens from the first parameter
		const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		//setter for delimiter
		static void setDelimiter(const char);
		//getter for delimiter
		const char getDelimiter() const;
	};

#endif

