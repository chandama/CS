#pragma once
#include "Property.h"

class Residential : public Property {
private:
	string occ;

public:
	Residential(string rental, double value, string occ, string address);
	string Property::toString() const;
	double taxtoString() const;
	string tax() const;
};
