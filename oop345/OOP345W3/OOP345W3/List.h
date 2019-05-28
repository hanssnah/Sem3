// Workshop 4 - Templates
// w4.cpp
//Hansol Cho 103608170
//hscho5@myseneca.ca
//Sep 26 2018
#ifndef LIST_H
#define LIST_H
#include <iostream>

template<typename T, int N>
class List {
private: 
	T m_List[N];
	int noa;
public:


	List() : noa(0) {
		
	}
	
	size_t size() const {
		return noa;
	}

	const T& operator[](int index) const {
		return m_List[index];
	}

	void operator+=(const T& x) {
		if (noa < N) {
			m_List[noa] = x;
			noa++;
		}
	}
	

};





#endif