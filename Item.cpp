#pragma once

#include <iostream>
#include <string>
using namespace std;

class Item {
	public:
		string name;
		int price;

		Item(string n, int p) {
			name = n;
			price = p;
		}
};
