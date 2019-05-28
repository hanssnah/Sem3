// Workshop 5 - Lambda Expression
// 345_w5.cpp
// 2018/10-11
//Hansol Cho 103608170 hscho5@myseneca.ca
#include <iostream>
#include "Grades.h"

using namespace std;

namespace sict {

	Grades::Grades(char* c)
	{
		try
		{
			ifstream fs(c);
			if (fs.is_open()){
				int line = 0;
				string str;

				while (getline(fs, str)) {
					line++;
				}
				fs.clear();
				fs.seekg(0);

				nos = line;
				stds = new string[nos];
				stdgrade = new double[nos];

				for (int i = 0; i < nos; i++) {
					fs >> stds[i];
					fs >> stdgrade[i];
				}
				fs.close();
			}
			else throw "ERROR!!!";
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
			exit(0);
		}
	}
}