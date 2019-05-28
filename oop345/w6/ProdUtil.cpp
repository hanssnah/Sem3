#include <string>
#include "Product.h"
#include "TaxableProduct.h"
#include "ProdUtil.h"

using namespace std;

namespace w6 {

	std::ostream& operator<<(std::ostream& os, const iProduct& _iProd) {
		_iProd.display(os);
		return os;
	}
	iProduct* readProduct(std::ifstream& ifs) {
		iProduct * _prod = nullptr;
		string pnum;
		double pcost = 0.0;
		char ptax = ' ';


		if (ifs.is_open()) {
			string temp;
			getline(ifs, temp);

			if (temp == "") {
				throw std::string("no such record! Reached the end of the file!");

			}
			else {
				int numEnd = temp.find(' ');
				pnum = temp.substr(0, numEnd);
				temp = temp.substr(numEnd + 1, temp.length());

				while (isspace(temp[0]))
					temp = temp.substr(1, temp.length() - 1);

				int costEnd = temp.find(' ');
				pcost = stod(temp.substr(0, costEnd));

				if (costEnd != -1) {
					temp = temp.substr(costEnd, temp.length() - 1);
					while (isspace(temp[0]))
						temp = temp.substr(1, temp.length() - 1);


					ptax = temp[0];
					if (ptax == 'C' || ptax == 'M') {
						throw std::string("Unrecognizable Tax Code!");
					}



				}

				if (ptax == ' ') {
					_prod = new Product(pnum, pcost);

				}
				else {
					_prod = new TaxableProduct(pnum, pcost, ptax);
				}



			}

		}

		return _prod;
	}

}
/*iProduct* pro = nullptr;
string pnum;
double pcost;
char ndl;
ifs >> pnum >> pcost;
ndl = ifs.get();

if (ndl == ' ') {
	ifs >> ndl;

	if (ndl == 'H') {
		TaxableProduct *Tpro = new TaxableProduct(pnum, pcost, 'H');
		pro = Tpro;
	}
	else if (ndl == 'P') {
		TaxableProduct *Tpro = new TaxableProduct(pnum, pcost, 'P');
		pro = Tpro;
	}
}
else {
	Product *NTpro = new Product(pnum, pcost);
	pro = NTpro;
}
return pro;
}*/





