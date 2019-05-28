// Workshop 4 - Templates
// w4.cpp
//Hansol Cho 103608170
//hscho5@myseneca.ca
//Sep 26 2018
#ifndef PAIR_H
#define PAIR_H
#include <iostream>

template < typename A, typename B>

class Pair {
	A m_Key;
	B m_Value;

public:

	Pair() : m_Key{}, m_Value{} {
	
	}
	Pair(const A& a, const B& b) : m_Key{ a }, m_Value{ b } {

	}
	const A& getKey() const {
		return m_Key;
	}
	const B& getValue() const {
		return m_Value;
	}
};



#endif