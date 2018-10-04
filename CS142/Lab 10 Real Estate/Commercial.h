#pragma once
#include "Property.h"

class Commercial : public Property {
private:
	string discount;
	double disRate;

public:
	Commercial(string rental, double value, string discount, double disRate, string address);
	string toString() const;
	double taxtoString() const;
	string tax() const;
};