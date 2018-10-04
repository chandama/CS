#include "Property.h"
Property::Property(string rent, double propValue, string propAddress, double taxes) {
	rental = rent;
	value = propValue;
	address = propAddress;
	propTax = taxes;
}