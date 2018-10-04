/* Chandler Taylor, Section 002, chandler.taylor05@gmail.com
Purpose: Take an old Plinko simulator written in int main() and refactor the code using functions
Inputs: Menu inputs (0 - 3 for different options of play or quit game)
Number of chips
Which slot to drop chip in
How many chips (for multiple chip games)
Outputs: Winnings for single chip game, multiple game, and simulation of multiple chips in every slot.
Test Cases:
1. Input:  -1, junk, 1, 9, -1, junk, 5 (I tested for out of range and cin error inputs)
Output: $1000 WINNINGS. (All error checking functions for single chip game)
2. Input:  2, -1, junk, 50, -1, junk, 5 (Tested new number of chips for errors)
Output: Total Winnings on 50 chips: 69200.00
Average winnings per chip: 1384.00
3. Input: 3, -1, junk, 100
Output: Total Winnings on slot 0 chips: 70500.00
Average winnings per chip: 705.00

Total Winnings on slot 1 chips: 93700.00
Average winnings per chip: 937.00

Total Winnings on slot 2 chips: 174800.00
Average winnings per chip: 1748.00

Total Winnings on slot 3 chips: 260700.00
Average winnings per chip: 2607.00

Total Winnings on slot 4 chips: 230700.00
Average winnings per chip: 2307.00

Total Winnings on slot 5 chips: 215000.00
Average winnings per chip: 2150.00

Total Winnings on slot 6 chips: 130300.00
Average winnings per chip: 1303.00

Total Winnings on slot 7 chips: 91900.00
Average winnings per chip: 919.00

Total Winnings on slot 8 chips: 54900.00
Average winnings per chip: 549.00
*/

#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int PlinkoMenu() {
	int menuInput = 0;
	bool loop = true;
	const int menuOption1 = 1;
	const int menuOption2 = 2;
	const int menuOption3 = 3;
	const int menuOption0 = 0;

	cout << "MENU: Please select one of the following options:" << endl << endl;
	cout << "0 - Quit the program" << endl;
	cout << "1 - Drop a single chip into one slot" << endl;
	cout << "2 - Drop multiple chips into one slot" << endl;
	cout << "3 - Drop multiple chips into each slot" << endl << endl;
	cout << "Enter your selection now: ";


	while (loop == true) {
		cin >> menuInput;
		cout << endl;

		if ((cin) && (menuInput == menuOption0 || menuInput == menuOption1 ||
			menuInput == menuOption2 || menuInput == menuOption3)) {

			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "INVALID SELECTION.  Please enter 0, 1, 2 or 3" << endl;
		cout << "Enter your selection now: ";
	}
	return menuInput;
}
int GetSlot() {
	double chipSlot = 0.0;;
	const double MIN_SLOT = 0.0;
	const double MAX_SLOT = 8.0;
	bool loop = true;

	while (loop == true) {
		cout << "Which slot do you want to drop the chip(s) in (0-8)? ";
		cin >> chipSlot;
		cout << endl;

		if ((cin) && chipSlot >= MIN_SLOT && chipSlot <= MAX_SLOT) {
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "INVALID SLOT, please try again." << endl;
	}
	return chipSlot;
}
int GetNumChips() {
	int amountOfChips;
	bool loop = true;

	while (loop == true) {
		cout << "How many chips do you want to drop (>0)? ";
		cin >> amountOfChips;
		cout << endl;

		if ((cin) && amountOfChips > 0) {
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "INVALID NUMBER OF CHIPS, please try again." << endl;
	}
	return amountOfChips;
}
double ComputeWinnings(int slot) {
	double rewardAmount = 0.0;
	const double WINNINGS_1 = 0.0;
	const double WINNINGS_2 = 100.0;
	const double WINNINGS_3 = 500.0;
	const double WINNINGS_4 = 1000.0;
	const double WINNINGS_5 = 10000.0;

	if (slot == 0) {
		rewardAmount = WINNINGS_2;
	}
	else if (slot == 1) {
		rewardAmount = WINNINGS_3;
	}
	else if (slot == 2) {
		rewardAmount = WINNINGS_4;
	}
	else if (slot == 3) {
		rewardAmount = WINNINGS_1;
	}
	else if (slot == 4) {
		rewardAmount = WINNINGS_5;
	}
	else if (slot == 5) {
		rewardAmount = WINNINGS_1;
	}
	else if (slot == 6) {
		rewardAmount = WINNINGS_4;
	}
	else if (slot == 7) {
		rewardAmount = WINNINGS_3;
	}
	else if (slot == 8) {
		rewardAmount = WINNINGS_2;
	}

	return rewardAmount;
}
double SingleChipDrop(double chipSlot) {
	int randomNumber = 0;
	double rewardAmount = 0.0;
	double chipPosition = 0.0;
	const int NUM_ROWS = 12;
	const double MIN_SLOT = 0.0;
	const double MAX_SLOT = 8.0;
	const double CHIP_MOVE = 0.5;

	chipPosition = chipSlot;

	if (chipPosition >= MIN_SLOT && chipPosition <= MAX_SLOT) {
		for (int i = 0; i < NUM_ROWS; i++) {
			randomNumber = rand() % 2;
			if (chipPosition <= MIN_SLOT) {
				chipPosition += CHIP_MOVE;
			}
			else if (chipPosition >= MAX_SLOT) {
				chipPosition -= CHIP_MOVE;
			}
			else if (randomNumber == 0) {
				chipPosition -= CHIP_MOVE;
			}
			else if (randomNumber == 1) {
				chipPosition += CHIP_MOVE;
			}
		}

		cout << fixed << setprecision(2);
		rewardAmount = ComputeWinnings(chipPosition);
	}
	return rewardAmount;
}
double MultipleChipDrops(double chipSlot, double amountOfChips) {
	double totalWinnings = 0.0;

	for (int i = 0; i < amountOfChips; ++i) {
		totalWinnings = totalWinnings + SingleChipDrop(chipSlot);
	}
	return totalWinnings;
}
int main() {
	srand(42);
	int menuSelection = 0;
	int amountOfChips = 0;
	double chipSlot = 0.0;
	double totalWinnings = 0.0;
	const double MAX_SLOT = 8.0;
	bool menuExit = false;

	cout << "Welcome to the plinko simulator!" << endl << endl;

	while (menuExit == false) {
		menuSelection = PlinkoMenu();
		if (menuSelection == 0) {
			menuExit = true;
			cout << "GOODBYE!" << endl;
		}
		if (menuSelection == 1) {
			cout << "*** DROP SINGLE CHIP ***" << endl << endl;
			chipSlot = GetSlot();
			cout << "WINNINGS: $" << SingleChipDrop(chipSlot) << endl << endl;
		}
		if (menuSelection == 2) {
			cout << "*** DROP MULTIPLE CHIPS ***" << endl << endl;
			amountOfChips = GetNumChips();
			chipSlot = GetSlot();
			totalWinnings = MultipleChipDrops(chipSlot, amountOfChips);
			cout << "Total Winnings on " << static_cast<int>(amountOfChips) << " chips: " << totalWinnings << endl;
			cout << "Average winnings per chip: " << totalWinnings / amountOfChips << endl << endl;
		}
		if (menuSelection == 3) {
			amountOfChips = GetNumChips();
			cout << "*** SEQUENTIALLY DROP MULTIPLE CHIPS ***" << endl << endl;
			for (int j = 0; j <= MAX_SLOT; ++j) {
				totalWinnings = MultipleChipDrops(j, amountOfChips);
				cout << "Total Winnings on slot " << j << " chips: " << totalWinnings << endl;
				cout << "Average winnings per chip: " << totalWinnings / amountOfChips << endl << endl;
			}
			cout << endl;
		}
	}
	return 0;
}