#include <iomanip>
#include "Product.h"

namespace w6 {
	
	Product::Product() : _prodNum{ 0 }, _prodPrice{ 0 } {};

	Product::Product(string p, double c) : _prodNum{ p }, _prodPrice{ c } {};
	Product::~Product() {};

	double Product::getPrice() const {
		return this->_prodPrice;
	};
	void Product::display(std::ostream& os) const {
		os << std::right << std::setw(16) << this->_prodNum
			<< std::setw(16) << std::fixed << std::setprecision(2)
			<< Product::getPrice() << std::setprecision(0);
	}

}
