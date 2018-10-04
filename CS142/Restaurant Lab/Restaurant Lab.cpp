/* Chandler Taylor, Section 002, chandler.taylor05@gmail.com
	Purpose: To help aid the decision of which restaurant to eat at by doing a process of elimination
	Inputs: Menu Selections, Add Restaurant, Delete Restaurant, Selecting winning restaurants during the tournament
		The user can also cut the list of restaurants at a certain point or shuffle the list randomly.
	Outputs: Restaurant list, winner of the restaurant tournament.
	Test Cases: 
		1.	Restaurants Added ("A", "B", "C")
			Print List:
			Here are the current restaurants:

			"A"
			"B"
			"C"
			Remove: "C"
			Cut: 1
			Print:
			Here are the current restaurants:

			"B"
			"C"
			"A"
			Shuffle: Error
			Battle: Error
		2.	Restaurants: (a, b, c, d, e, f, g, h)
			Shuffle:
			Print:
			Here are the current restaurants:

			"e"		"a"		"f"		"b"		"g"		"c"		"h"		"d" (Lines removed for space)
			Battle: 1, 2, 1, 2, a, 1, 2, 2
			The winning restaurant is g
		3.	Restaurants: (a)
			Remove "b": Error doesnt exist
			Add "b":
			Print:
			Here are the current restaurants:
			
			"a"
			"b"
			Remove "B": Error. Case sensitive checking working
After all of these test cases I was able to confirm that all of the error checking works as intended
and that the program functions.			
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int ProgramMenu() {
	int menuInput = 0;
	const int QUIT = 0;
	const int DISPLAY_REST = 1;
	const int ADD_REST = 2;
	const int REMOVE_REST = 3;
	const int CUT_REST = 4;
	const int SHUFFLE_REST = 5;
	const int RESTAURANT_BATTLE = 6;
	bool loop = true;

	while (loop == true) {
		cout << "Please select one of the following options:" << endl << endl;
		cout << "0 - Quit the program" << endl;
		cout << "1 - Display all restaurants" << endl;
		cout << "2 - Add a restaurant" << endl;
		cout << "3 - Remove a restaurant" << endl;
		cout << "4 - \"Cut\" the list of restaurants" << endl;
		cout << "5 - \"Shuffle\" the list of restaurants" << endl;
		cout << "6 - Begin the tournament" << endl << endl;
		cout << "Enter your selection now: ";
		cin >> menuInput;
		cout << endl;

		if ((cin) && (menuInput == QUIT || menuInput == DISPLAY_REST || menuInput == ADD_REST || menuInput == REMOVE_REST
			|| menuInput == CUT_REST || menuInput == SHUFFLE_REST || menuInput == RESTAURANT_BATTLE)) {
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "INVALID SELECTION.  Please try again." << endl << endl;
	}

	return menuInput;
}

void DisplayAllRestaurants(const vector<string> displayVec ) {
	int size = displayVec.size();

	cout << "Here are the current restaurants:" << endl << endl;
	for (int i = 0; i < size; ++i) {
		cout << "\t\"" << displayVec.at(i) << "\"" << endl;
	}
	cout << endl;

	return;
}

bool FindRestaurant(const vector<string> findVec, string restName) {
	int size = findVec.size();
	bool duplicateRestaurant = false;
	bool findName = find(findVec.begin(), findVec.end(), restName) != findVec.end();

	if (findName == true) {
		duplicateRestaurant = true;
	}

	return duplicateRestaurant;
}

void AddRestaurant(vector<string>& addVec) {
	string restaurantName;

	cout << "What is the name of the restaurant you want to add? ";
	cin.ignore();
	getline(cin, restaurantName);
	cout << endl;
	if (FindRestaurant(addVec, restaurantName) == true) {
		cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
	}
	else {
		addVec.push_back(restaurantName);
		cout << restaurantName << " has been added." << endl << endl;
	}

	return;
}

void RemoveRestaurant(vector<string>& removeVec) {
	int size = removeVec.size();
	string restaurantName;
	bool removeSuccess = false;

	cout << "What is the name of the restaurant you want to remove? ";
	cin.ignore();
	getline(cin, restaurantName);
	cout << endl;
	if (FindRestaurant(removeVec, restaurantName) == true) {
		for (int i = 0; i < size; ++i) {
			if (removeVec.at(i) == restaurantName) { 
				removeVec.erase(remove(removeVec.begin(), removeVec.end(), restaurantName), removeVec.end());
				cout << restaurantName << " has been removed." << endl << endl;
				size = removeVec.size();
				removeSuccess = true;
			}
		}	
	}

	if (removeSuccess == false) {
		cout << "That restaurant is not on the list, you can not remove it." << endl << endl;
	}

	return;
}

void CutRestaurants(vector<string>& cutVec) {
	int cutInt = 0;

	cout << "How many restaurants should be taken from the top and put on the bottom? ";
	cin >> cutInt;
	cout << endl << endl;
	for (int i = 0; i < cutInt; ++i) {
		cutVec.push_back(cutVec.at(i));
	}
	for (int i = 0; i < cutInt; ++i) {
		cutVec.erase(cutVec.begin());
	}	
	return;
}

void ShuffleRestaurants(vector<string>& shuffleVec) {
	int listSize = shuffleVec.size();
	vector<string> newShuffleVec(shuffleVec.size());
	const int HALF_VECTOR = 2;

	if ((listSize > 0) && ((listSize & (listSize - 1)) == 0)) { 
		for (int i = (listSize / HALF_VECTOR); i < listSize; ++i) {
			newShuffleVec.at((i * HALF_VECTOR) - listSize) = shuffleVec.at(i);
		}
		for (int i = 0; i < (listSize / HALF_VECTOR); ++i) {
			newShuffleVec.at((i * HALF_VECTOR) + 1) = shuffleVec.at(i);
		}
		for (int i = 0; i < listSize; ++i) {
			shuffleVec.at(i) = newShuffleVec.at(i);
		}
	}
	else {
		cout << "The current tournament size (" << listSize << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove resturants." << endl << endl;
	}
	return;
}

void RestaurantBattle(vector<string>& battleVec) { 
	int listSize = battleVec.size();
	int battleRound = 1;
	int battleChoice = 0;
	const int FIRST_CHOICE = 1;
	const int SECOND_CHOICE = 2;

	if ((listSize > 0) && ((listSize & (listSize - 1)) == 0)) {
		
		while (battleVec.size() != 1) {
			int i = 0;
			cout << "Round: " << battleRound << endl << endl;
			while (i < battleVec.size()) {
				cout << "Type \"1\" if you prefer " << battleVec.at(i) << " or" << endl;
				cout << "type \"2\" if you prefer " << battleVec.at(i + 1) << endl;
				cout << "Choice: ";
				cin.ignore();
				cin >> battleChoice;
				cout << endl << endl;
				if ((cin) && (battleChoice == FIRST_CHOICE || battleChoice == SECOND_CHOICE)) {
					if (battleChoice == FIRST_CHOICE) {
						battleVec.erase(battleVec.begin() + i + 1);
					}
					if (battleChoice == SECOND_CHOICE) {
						battleVec.erase(battleVec.begin() + i);
					}
					++i;
				}
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid entry please enter a 1 or a 2" << endl;
				}
			}
			++battleRound;
		}
		cout << "The winning restaurant is " << battleVec.at(0) << endl << endl;
	}
	else {
		cout << "The current tournament size (" << listSize << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A tournament is not possible. Please add or remove resturants." << endl << endl;
	}
	return;
}

int main() {
	int menuSelection = 0;
	const int QUIT = 0;
	const int DISPLAY_REST = 1;
	const int ADD_REST = 2;
	const int REMOVE_REST = 3;
	const int CUT_REST = 4;
	const int SHUFFLE_REST = 5;
	const int RESTAURANT_BATTLE = 6;
	bool menuExit = false;
	vector<string> restaurantVec;

	cout << "Welcome to the restaurant battle!" << endl << endl << endl;

	while (menuExit == false) {
		menuSelection = ProgramMenu();
		if (menuSelection == QUIT) {
			cout << "GOODBYE!" << endl;
			menuExit = true;
		}
		if (menuSelection == DISPLAY_REST) {
			DisplayAllRestaurants(restaurantVec);
		}
		if (menuSelection == ADD_REST) {
			AddRestaurant(restaurantVec);
		}
		if (menuSelection == REMOVE_REST) {
			RemoveRestaurant(restaurantVec);
		}
		if (menuSelection == CUT_REST) {
			CutRestaurants(restaurantVec);
		}
		if (menuSelection == SHUFFLE_REST) {
			ShuffleRestaurants(restaurantVec);
		}
		if (menuSelection == RESTAURANT_BATTLE) {
			RestaurantBattle(restaurantVec);
		}
	}
	return 0;
}