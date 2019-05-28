// Workshop 5 - Lambda Expression
// 345_w5.cpp
// 2018/10-11
//Hansol Cho 103608170 hscho5@myseneca.ca

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}


	//Update the main functions as per the specifications here
	//Lambda function
	try {
		sict::Grades grades(argv[1]);

		auto letter = [](double grd) {
			string a;
			letters lt;
			if (grd >= 90) lt = Ap;
			else if (grd >= 80) lt = A;
			else if (grd >= 75) lt = Bp;
			else if (grd >= 70) lt = B;
			else if (grd >= 65) lt = Cp;
			else if (grd >= 60) lt = C;
			else if (grd >= 55) lt = Dp;
			else if (grd >= 50) lt = D;
			else lt = F;
			a = grading(lt);
			return a;

		};
		grades.displayGrades(std::cout, letter);
	}
	catch (std::string err)
	{
		std::cout << " There was an error : " << err << std::endl;


	}
	return 0;
}