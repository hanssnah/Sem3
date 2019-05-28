#include "TaxableProduct.h"

namespace w6 {


	TaxableProduct::TaxableProduct() : _prodTax{ ' ' } {
		_taxRate[H] = 1.13;
		_taxRate[P] = 1.08;

	}
	TaxableProduct::TaxableProduct(string p, double c, char pt) : Product::Product(p, c), _prodTax{ pt } {
		_taxRate[H] = 1.13;
		_taxRate[P] = 1.08;
	}

	double TaxableProduct::getPrice() const {
		Rate rate;

		switch (this->_prodTax) {
		case 'H':
			rate = H;
			break;

		case 'P':
			rate = P;
			break;
		}
		return Product::getPrice() * _taxRate[rate];
	}
	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		os << " ";

		if (this->_prodTax == 'H') {
			os << "HST";
		}
		else {
			os << "PST";
		}
	}
}