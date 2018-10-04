/*
Chandler Taylor, Section 002, chandler.taylor05@gmail.com
Purpose: To see whether a Hybrid or a Non-Hybrid car is better based on user criteria
Inputs:
	Miles driven per year
	Hybrid cost
	Hybrid resale price (after 5 years)
	Non Hybrid cost
	Non Hybrid resale (after 5 years)
	Hybrid MPG efficiency
	Non Hybrid MPG efficiency
	Avg. Price for Gallon of Gas
	User preference of (Gas consumption or Total value)
Output: 
	Hybrid
		Gallons of gas used over 5 years
		Total cost of ownership of the Hybrid car over 5 years
	Non-Hybrid
		Gallons of gas used over 5 years
		Total cost of ownership of the Non Hybrid car over 5 years
Test cases: 
	Inputs: 25000, 3.00, 0, 50000, 50, 25000, 20000, 25, 10000, Total
	Output:
		For the Hybrid Car:

	The total gallons of fuel consumed over 5 years: 2500.00
	The total cost of owning the car for 5 years: 32500.00

	For the NON-Hybrid Car:

	The total gallons of fuel consumed over 5 years: 5000.00
	The total cost of owning the car for 5 years: 25000.00
	** The NON-HYBRID Car is better than the HYBRID Car when "Total" is the user's primary objective.

	Inputs: 25000, 3.00, 50000, 50, 1000, 20000, 25, 20000, Gas
	Output:For the Hybrid Car:

	The total gallons of fuel consumed over 5 years: 2500.00
	The total cost of owning the car for 5 years: 56500.00

	For the NON-Hybrid Car:

	The total gallons of fuel consumed over 5 years: 5000.00
	The total cost of owning the car for 5 years: 15000.00
	** The HYBRID Car is better than the NON-HYBRID Car when "Gas" is the user's primary objective.

	Inputs: 0, 10000, 0, 1.00, 0, 1000, 0, 1.0, 0, 1000, 0, 1.0, 0, 1000, Gas
	Output: For the Hybrid Car:

	The total gallons of fuel consumed over 5 years: 50000.00
	The total cost of owning the car for 5 years: 50000.00

	For the NON-Hybrid Car:

	The total gallons of fuel consumed over 5 years: 50000.00
	The total cost of owning the car for 5 years: 50000.00

	** The HYBRID Car is better than the NON-HYBRID Car when "Total" is the user's primary objective.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	const int YEARS_CAR_OWNED = 5;

	int milesDrivenPerYear = 0;
	int hybridCarCost = 0;
	int hybridResalePrice = 0;
	int nonHybridCost = 0;
	int nonHybridResalePrice = 0;

	double gasCostPerGallon = 0.0;
	double hybridEfficiencyMPG = 0.0;
	double nonHybridEfficiencyMPG = 0.0;
	double hybridGasConsumption = 0.0;
	double nonHybridGasConsumption = 0.0;
	double totalHybridFiveYearCost = 0.0;
	double totalNonHybridFiveYearCost = 0.0;

	string gasOrTotal;
	string pause;

	cout << "Please enter the following: " << endl << endl;
	cout << "The estimated miles driven per year: ";
	cin >> milesDrivenPerYear;
	if (milesDrivenPerYear <= 0) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The estimated miles driven per year: ";
		cin >> milesDrivenPerYear;
	}
	cout << endl;

	cout << "The estimated price of a gallon of gas during the 5 years of ownership: ";
	cin >> gasCostPerGallon;
	if (gasCostPerGallon <= 0.00) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The estimated price of a gallon of gas during the 5 years of ownership: ";
		cin >> gasCostPerGallon;
	}
	cout << endl;

	cout << "The initial cost of a hybrid car: ";
	cin >> hybridCarCost;
	if (hybridCarCost <= 0) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The initial cost of a hybrid car: ";
		cin >> hybridCarCost;
	}
	cout << endl;

	cout << "The efficiency of the hybrid car in miles per gallon: ";
	cin >> hybridEfficiencyMPG;
	if (hybridEfficiencyMPG <= 0.0) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The efficiency of the hybrid car in miles per gallon: ";
		cin >> hybridEfficiencyMPG;
	}
	cout << endl;

	cout << "The estimated resale value (a dollar amount) for a hybrid after 5 years: ";
	cin >> hybridResalePrice;
	if (hybridResalePrice <= 0) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The estimated resale value (a dollar amount) for a hybrid after 5 years: ";
		cin >> hybridResalePrice;
	}
	cout << endl;

	cout << "The initial cost of a non-hybrid car: ";
	cin >> nonHybridCost;
	if (nonHybridCost <= 0) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The initial cost of a non-hybrid car: ";
		cin >> nonHybridCost;
	}
	cout << endl;

	cout << "The efficiency of the non-hybrid car in miles per gallon: ";
	cin >> nonHybridEfficiencyMPG;
	if (nonHybridEfficiencyMPG <= 0) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The efficiency of the non-hybrid car in miles per gallon: ";
		cin >> nonHybridEfficiencyMPG;
	}
	cout << endl;

	cout << "The estimated resale value(a dollar amount) for a non - hybrid after 5 years: ";
	cin >> nonHybridResalePrice;
	if (nonHybridResalePrice <= 0) {
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter:" << endl;
		cout << "The estimated resale value(a dollar amount) for a non - hybrid after 5 years: ";
		cin >> nonHybridResalePrice;
	}
	cout << endl;

	cout << "The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total): ";
	cin >> gasOrTotal;
	if (gasOrTotal !== "Gas" || gasOrTotal !== "Total") {
		cout << "You must enter either \"Gas\" or \"Total\":" << endl;
		cout << "The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total): ";
		cin >> gasOrTotal;
	}
	cout << endl;

	hybridGasConsumption = milesDrivenPerYear / hybridEfficiencyMPG * YEARS_CAR_OWNED;
	totalHybridFiveYearCost = (hybridCarCost - hybridResalePrice) + (hybridGasConsumption * gasCostPerGallon) ;

	nonHybridGasConsumption = milesDrivenPerYear / nonHybridEfficiencyMPG * YEARS_CAR_OWNED;
	totalNonHybridFiveYearCost = (nonHybridCost - nonHybridResalePrice) + (nonHybridGasConsumption * gasCostPerGallon);

	cout << "For the Hybrid Car:" << endl << endl << endl;
	cout << "The total gallons of fuel consumed over 5 years: ";
	cout << fixed << setprecision(2) << hybridGasConsumption << endl;
	cout << "The total cost of owning the car for 5 years: ";
	cout << totalHybridFiveYearCost << endl << endl << endl;

	cout << "For the NON-Hybrid Car:" << endl << endl << endl;
	cout << "The total gallons of fuel consumed over 5 years: ";
	cout << nonHybridGasConsumption << endl;
	cout << "The total cost of owning the car for 5 years: ";
	cout << totalNonHybridFiveYearCost << endl << endl << endl;
	
	if (((totalHybridFiveYearCost <= totalNonHybridFiveYearCost) && (gasOrTotal == "Total")) || ((hybridGasConsumption <= nonHybridGasConsumption) && (gasOrTotal == "Gas"))) {
		cout << "** The HYBRID Car is better than the NON-HYBRID Car when \"" << gasOrTotal << "\" is the user's primary objective.";
	}
	else {
		cout << "** The NON-HYBRID Car is better than the HYBRID Car when \"" << gasOrTotal << "\" is the user's primary objective.";
	}

	cout << "Press any key to continue: ";
	cin >> pause;
    return 0;
}

