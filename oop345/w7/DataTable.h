#pragma once
//HANSOL CHO 103608170 hscho5@myseneca.ca Nov 05 2018
#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <functional>

namespace w7 {

	template <class T>
	class DataTable {
		int wdt;
		int dec;
		std::vector<T> x;
		std::vector<T> y;

	public:
		DataTable() {}

		DataTable(std::ifstream& ifs, const int _wdt, const int _dec) {
			T newX;
			T newY;

			wdt = _wdt;
			dec = _dec;

			if (ifs.is_open()) {
				while (ifs >> newX >> newY) {
					x.push_back(newX);
					y.push_back(newY);
				}
			}
		}

		T mean() const {
			return accumulate(y.begin(), y.end(), (T)0) / y.size();
		}

		T sigma() const {
			T _mean = mean();
			T _num = y.size();
			std::vector<T> temp(y.size());
			std::transform(y.begin(), y.end(), temp.begin(),
				std::bind2nd(std::minus<T>(), _mean));
			T _sum = std::inner_product(temp.begin(), temp.end(), temp.begin(), (T)0);
			return std::sqrt(_sum / (_num - 1));
		}

		T median() const {   //should I use median for even number? or odd number?

			std::vector<T> temp = y;
			//if (temp.size() % 2 == 1) {

			sort(temp.begin(), temp.end());
			T index = temp[temp.size() / 2];
			return index;
			//}
			//else {
			//	sort(temp.begin(), temp.end());
			//	T sum = temp[(temp.size() / 2)-1] + temp[temp.size() / 2];
			//	return sum/2;
			//}
		}
		void regression(T& slope, T& y_intercept) const {

			
			T s_x = std::accumulate(x.begin(), x.end(), (T)0);
			T s_y = std::accumulate(y.begin(), y.end(), (T)0);
			T s_xy = std::inner_product(x.begin(), x.end(), y.begin(), (T)0);
			T s_sq_x = std::inner_product(x.begin(), x.end(), x.begin(), (T)0);
			T num = y.size();

			slope = (num * s_xy - s_x * s_y) / (num * s_sq_x - s_x * s_x);
			y_intercept = (s_y - slope * s_x) / num;
		}


		void display(std::ostream&os) const {
			os << std::fixed <<std::setw(wdt) << "x" << std::setw(wdt) << "y" << std::endl;
			for (size_t i = 0; i < x.size(); i++) {
				os << std::fixed <<std::setw(wdt) << std::setprecision(dec) << x[i] << std::setprecision(dec) << std::setw(wdt) << y[i] << std::endl;

			}

		}

		size_t getSize() const {
			return x.size();
		}

	};
	template<class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& dt) {
		dt.display(os);
		return os;
	}
}
#endif