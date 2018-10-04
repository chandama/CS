#pragma once
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Property {
protected:
	string rental;
	double value;
	string address;
	double propTax;
public:
	Property(string rent, double propValue, string propAddress, double taxes);
	virtual string toString() const = 0;
	virtual double taxtoString() const = 0;
	virtual string tax() const = 0;
};