#pragma once

#include <iostream>
#include <string>
using namespace std;

class PaymentMethod {
public:
	string method;
	double subTotal;
	double cash;
	double change;

	PaymentMethod(string m, double s = 0, double c = 0, double ch = 0 ) {
		method = m;
		subTotal = s;
		cash = c;
		change = ch;
	}
};
