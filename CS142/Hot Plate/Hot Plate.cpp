/*Chandler Taylor, Section 002, chandler.taylor05@gmail.com
	Purpose: To use arrays to simulate a hot plate and the temperatures at various locations (array elements)
	Inputs: None
	Outputs: There are 3 instances of the hotplate printed:
		1. Initial Plate
		2. Plate after one iteration
		3. Final plate after the heat has evened out after many iterations.
		
*/

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <iomanip>
#include <ios>

using namespace std;


int main()
{

	bool updateArray = true;

	const int ARRAY_WIDTH = 20;
	const int ARRAY_HEIGHT = 20;
	const int NUM_SIDES = 4;
	const double STARTING_HOT = 100.0;
	const double STARTING_COLD = 0.0;
	const double MIN_TEMP_DIFF = 0.1;

	double tempDiff = 0.0;
	double maxTempDiff = 0.0;

	double HotPlate[ARRAY_HEIGHT][ARRAY_WIDTH];
	double HotPlateOld[ARRAY_HEIGHT][ARRAY_WIDTH];

	cout << "Hotplate simulator" << endl << endl;
	cout << "Printing initial plate..." << endl;

	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			cout << setw(10) << fixed << setprecision(4);
			if ((i == 0 && (j > 0 && j < ARRAY_WIDTH - 1)) || (i == (ARRAY_HEIGHT - 1) && (j > 0 && j < ARRAY_WIDTH - 1))) {
				HotPlate[i][j] = STARTING_HOT;
			}
			else {
				HotPlate[i][j] = STARTING_COLD;
			}
			if (j >= 0 && j < (ARRAY_WIDTH - 1)) {
				cout << HotPlate[i][j] << ",";
			}
			else {
				cout << HotPlate[i][j];
			}
		}
		cout << endl;
	}

	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			HotPlateOld[i][j] = HotPlate[i][j];
		}
	}
	cout << endl;

	for (int i = 1; i < ARRAY_HEIGHT - 1; ++i) {
		for (int j = 1; j < ARRAY_WIDTH - 1; ++j) {
			HotPlate[i][j] = (HotPlateOld[i - 1][j] + HotPlateOld[i + 1][j]
				+ HotPlateOld[i][j - 1] + HotPlateOld[i][j + 1]) / NUM_SIDES;
		}
	}

	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			HotPlateOld[i][j] = HotPlate[i][j];
		}
	}
	
	cout << "Printing plate after one iteration..." << endl;

	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			cout << setw(10) << fixed << setprecision(4);
			if (j >= 0 && j < (ARRAY_WIDTH - 1)) {
				cout << HotPlate[i][j] << ",";
			}
			else {
				cout << HotPlate[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;

	while (updateArray == true) {
		for (int i = 1; i < ARRAY_HEIGHT - 1; ++i) {
			for (int j = 1; j < ARRAY_WIDTH - 1; ++j) {
				HotPlate[i][j] = (HotPlateOld[i - 1][j] + HotPlateOld[i + 1][j]
					+ HotPlateOld[i][j - 1] + HotPlateOld[i][j + 1]) / NUM_SIDES;
			}
		}

		for (int i = 0; i < ARRAY_HEIGHT; ++i) {
			for (int j = 0; j < ARRAY_WIDTH; ++j) {
				if (HotPlate[i][j] > HotPlateOld[i][j]) {
					tempDiff = HotPlate[i][j] - HotPlateOld[i][j];
					if (tempDiff > maxTempDiff) {
						maxTempDiff = tempDiff;
					}
				}
			}
		}

		if (maxTempDiff > MIN_TEMP_DIFF) {
			for (int i = 0; i < ARRAY_HEIGHT; ++i) {
				for (int j = 0; j < ARRAY_WIDTH; ++j) {
					HotPlateOld[i][j] = HotPlate[i][j];
				}
			}
		}
		else {
			updateArray = false;
		}
		tempDiff = 0.0;
		maxTempDiff = 0.0;
	}
	
	cout << "Printing final plate..." << endl;
	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			cout << setw(10) << fixed << setprecision(4);
			if (j >= 0 && j < (ARRAY_WIDTH - 1)) {
				cout << HotPlate[i][j] << ",";
			}
			else {
				cout << HotPlate[i][j];
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << "Printing final plate for excel..." << endl;
	for (int i = 0; i < ARRAY_HEIGHT; ++i) {
		for (int j = 0; j < ARRAY_WIDTH; ++j) {
			cout << fixed << setprecision(4);
			if (j >= 0 && j < (ARRAY_WIDTH - 1)) {
				cout << HotPlate[i][j] << "\t";
			}
			else {
				cout << HotPlate[i][j];
			}
		}
		cout << endl;
	}


	system("pause");
    return 0;
}

