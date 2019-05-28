//Hansol Cho hscho5@myseneca.ca 103608170  11/16/2018

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		Product * temp;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t a = 0; a < price.size(); a++) {
				if (desc[i].code == price[a].code) {
					temp = new Product(desc[i].desc, price[a].price);
					temp->validate();
					priceList += temp;
					delete temp;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t a = 0; a < price.size(); a++) {
				if (desc[i].code == price[a].code) {
					//Product * prod  = unique_ptr<Product>(new Product(desc[i].desc, price[a].price));
					unique_ptr<Product> prod = unique_ptr<Product> (new Product(desc[i].desc, price[a].price));
					prod->validate();
					priceList += prod.get();
				}
			}
		}

		return priceList;
	}
}