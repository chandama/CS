#include "Residential.h"
#include <iomanip>

Residential::Residential(string rental, double propVal, string occupied, string address) : Property(rental, propVal, address, propTax) {
	occ = occupied;
}

string Residential::toString() const{
	stringstream resStream;
	resStream << " Address: " << address << ". ";
	if (rental == "yes") {
		resStream << "Rental. ";
	}
	else {
		resStream << "NOT rental. ";
	}
	resStream << " Estimated value: " << fixed << setprecision(2) <<value << ". A Residential Property. ";
	if (occ == "yes") {
		resStream << "Occupied.";
	}
	else {
		resStream << "NOT occupied.";
	}
	resStream << endl;
	return resStream.str();
}

double Residential::taxtoString() const{
	double resRate = 0.006;
	double resRate2 = 0.009;
	double resTax = propTax;
	stringstream resStream;
	resStream << fixed << setprecision(2) << setw(15);
	if (occ == "yes") {
		resTax = value*resRate;
	}
	else {
		resTax = value*resRate2;
	}

	return resTax;
}

string Residential::tax() const{
	stringstream resStream;
	resStream << "** Taxes due for the property at: " << address << endl;
	resStream << "  This property has an estimated value of: " << fixed << setprecision(2) << setw(15) << value << endl;
	resStream << "  Taxes due on this property are: " << taxtoString() << endl;
	return resStream.str();
}
