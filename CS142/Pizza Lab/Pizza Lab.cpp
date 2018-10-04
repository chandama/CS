/*
Chandler Taylor, Section 002, chandler.taylor05@gmail.com

Purpose: Calculate the quantity, size, and price of pizzas that the user needs to buy
Inputs: Number of people eating and the tip amount (expressed as a percentage)
Output: The number and different sizes of pizzas
	required to feed the group as well as the cost of the pizza.
Test Cases:
Test 1: Input: 73 guests and 20% tip
	Output: 10 large pizzas and 1 medium pizza. 
		3342.65 sq inches of pizza (45.7898 per person). 
		Total cost = $190
Test 2: Input: 4 guests and 35% tip
	Output: 1 medium pizza and 1 small pizza. 
		314.159 sq inches of pizza (78.5397 per person)
		Total cost = $25
Test 3: Input: 42 guests and 25% tip
	Output: 6 large pizzas.
	1884.95 sa inches of pizza (44.8799 per person)
	Total cost = $110
*/


#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	const int PEOPLE_PER_LARGE = 7;
	const int PEOPLE_PER_MEDIUM = 3;
	const int LARGE_RADIUS = 10;
	const int MEDIUM_RADIUS = 8;
	const int SMALL_RADIUS = 6;
	const double LARGE_PRICE = 14.68;
	const double MEDIUM_PRICE = 11.48;
	const double SMALL_PRICE = 7.28;
	const double PI = 3.14159;
	const double PERCENTAGE = 0.01;

	int numberGuests = 0;
	int largePizzas = 0;
	int mediumPizzas = 0;
	int smallPizzas = 0;
	
	double largePizzaArea = 0.0;
	double mediumPizzaArea = 0.0;
	double smallPizzaArea = 0.0;
	double pizzaAreaTotal = 0.0;
	double pizzaAreaPerGuest = 0.0;

	double tipAmount = 0.0;
	double tipTotal = 0.0;
	double pizzaCost = 0.0;
	int roundedCost = 0;

	cout << "Please enter the number of guests: ";
	cin >> numberGuests;
	cout << endl << endl;

	largePizzas = numberGuests / PEOPLE_PER_LARGE;
	mediumPizzas = (numberGuests % PEOPLE_PER_LARGE) / PEOPLE_PER_MEDIUM;
	smallPizzas = numberGuests - ((largePizzas * PEOPLE_PER_LARGE) + (mediumPizzas * PEOPLE_PER_MEDIUM));

	cout << largePizzas << " large pizzas, " << mediumPizzas;
	cout << " medium pizzas, and " << smallPizzas;
	cout << " small pizzas will be needed." << endl << endl;

	largePizzaArea = (LARGE_RADIUS * LARGE_RADIUS) * PI;
	mediumPizzaArea = (MEDIUM_RADIUS * MEDIUM_RADIUS) * PI;
	smallPizzaArea = (SMALL_RADIUS * SMALL_RADIUS) * PI;
	pizzaAreaTotal = (largePizzaArea * largePizzas) + (mediumPizzaArea * mediumPizzas) + (smallPizzaArea * smallPizzas);
	pizzaAreaPerGuest = pizzaAreaTotal / numberGuests;

	cout << "A total of " << pizzaAreaTotal << " square inches of pizza will be purchased (" << pizzaAreaPerGuest << " per guest)." << endl << endl;

	cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";
	cin >> tipAmount;
	cout << endl << endl;

	pizzaCost = (largePizzas * LARGE_PRICE) + (mediumPizzas * MEDIUM_PRICE) + (smallPizzas * SMALL_PRICE);
	tipTotal = (pizzaCost * tipAmount) * PERCENTAGE;
	roundedCost = (pizzaCost + tipTotal) + 0.5;
	cout << "The total cost of the event will be: $" << roundedCost << endl;


	system("pause");
    return 0;
}

