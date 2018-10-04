#include "Commercial.h"
#include <iomanip>

Commercial::Commercial(string rental, double propVal, string disc, double discRate, string propAddress) : Property(rental, propVal, propAddress, propTax) {
	discount = disc;
	disRate = discRate;
}

string Commercial::toString() const{
	stringstream comStream;
	comStream << "Address: " << address;
	if (rental == "yes") {
		comStream << ". Rental. ";
	}
	else {
		comStream << ". NOT rental. ";
	}
	comStream << " Estimated value: \n" << fixed << setprecision(2) << setw(15) << value << ". A Commercial Property. ";
	if (discount == "yes") {
		comStream << "In a discount zone with discount of: " << fixed << setprecision(2) << setw(15) << disRate << "%." << endl;
	}
	else {
		comStream << "NOT in a discount zone.";
	}

	return comStream.str();
}

double Commercial::taxtoString() const{
	cout << fixed << setprecision(2) << setw(15);
	double comRate = 0.012;
	double comRate2 = 0.01;
	double comTax = propTax;
	double disValue = 0.0;
	if (rental == "yes") {
		if (discount == "yes") {
			disValue = value*((100.0 - disRate) / 100.0);
			comTax = disValue*comRate;
		}
		else {
			comTax = value*comRate;
		}
	}
	else {
		if (discount == "yes") {
			disValue = value*((100.0 - disRate) / 100.0);
			comTax = disValue*comRate2;
		}
		else{
			comTax = value*comRate2;
		}
	}
	return comTax;
}

string Commercial::tax() const{
	stringstream comStream;
	comStream << "** Taxes due for the property at: " << address << endl;
	comStream << "  This property has an estimated value of: " << fixed << setprecision(2) << value << endl;
	comStream << "  Taxes due on this property are: " << taxtoString() << endl;
	return comStream.str();
}