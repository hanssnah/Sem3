//Hansol Cho #103608170 
//hscho5@myseneca.ca
#ifndef W6_TAXABLE_H
#define W6_TAXABLE_H
#include <string>
#include "Product.h"
using namespace std;
namespace w6 {

	class TaxableProduct : public Product {
		char _prodTax;
		double _taxRate[2];

	public:

		enum Rate { H, P }; //enumerator for HST and PST

		TaxableProduct(); // default constructor and set it empty
		TaxableProduct(string p, double c, char pt); // constuctor that getting data from file and set it own.
		
		virtual double getPrice() const; // getting cost
		virtual void display(std::ostream&) const; // display class
	
	};
}
#endif