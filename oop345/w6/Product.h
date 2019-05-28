//Hansol Cho #103608170 
//hscho5@myseneca.ca
#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H
#include <string>
#include "iProduct.h"
using namespace std;
namespace w6 {
	class Product : public iProduct {

		string _prodNum;
		double _prodPrice;

	public:
		Product(); // default constructor and setting empty
		Product(string p, double c); // getting prodnum and cost from file and setting it own.
		~Product(); // destructor

		virtual double getPrice() const; // it returns cost
		virtual void display(std::ostream&) const; // displaying function
	};

}
#endif

