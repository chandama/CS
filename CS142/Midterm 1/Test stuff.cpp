/* Chandler Taylor, chandler.taylor05@gmail.com, section 005
Purpose: To determine the capacities of a resevoir given certain inflow and outflow values
Inputs: Resevoir Capacity, Inflow, Outflow
Outputs: Resevoir volumes simulated for 10 years repeated 15 times.
Average years it took to fill the resevoir completely.
OR
If it never filled completely, informs user that a dam shouldnt be built there.
Number of times there was a release failure.

Test Case:
Reservoir Capacity: 24.0
Required Outflow: 7.5
Values for the Inflow: 16.0 13.4 21.2 4.7 6.8 4.5 7.6 13.2 13.5 8.6
Processing Inflow data...
8.5    14.4    24.0    21.2    20.5    17.5    17.6    23.3    24.0    24.0
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;


int main() {

	double reservoirCapacity = 0.0;
	double inFlow = 0.0;
	double outFlow = 0.0;
	double lakeVolume = 0.0;
	double yearsToFill = 0.0;
	double totalFillYears = 0.0;
	int releaseFailures = 0;
	int maxReleaseFailures = 0;

	bool lakeFilled = false;
	bool shouldBuildDam = false;
	bool loopExit = false;

	const double EMPTY = 0.0;
	const int TEN_YEARS = 10;
	const int FIFTEEN_YEAR_PREDICTION = 15;

	cout << "Reservoir Capacity: ";
	cin >> reservoirCapacity;
	cout << endl;
	cout << "Required Outflow: ";
	cin >> outFlow;
	cout << endl;
	cout << "Values for the Inflow: " << endl;
	cout << "Processing Inflow data..." << endl;

	for (int i = 0; i < FIFTEEN_YEAR_PREDICTION; ++i) {
		for (int j = 0; j < TEN_YEARS; ++j) {
			cin >> inFlow;
			cout << fixed << setprecision(1) << setw(8);

			if (lakeVolume + inFlow - outFlow > reservoirCapacity) {
				lakeVolume = reservoirCapacity;
				cout << lakeVolume;
				shouldBuildDam = true;
				if (lakeFilled == false) {
					yearsToFill = j + 1;
					lakeFilled = true;
				}
			}
			else if (lakeVolume + inFlow - outFlow <= EMPTY) {
				lakeVolume = EMPTY;
				cout << lakeVolume;
				releaseFailures = releaseFailures + 1;
			}
			else {
				lakeVolume = lakeVolume + inFlow - outFlow;
				cout << lakeVolume;
			}
		}
		cout << endl;
		if (releaseFailures > maxReleaseFailures) {
			maxReleaseFailures = releaseFailures;
		}
		totalFillYears = totalFillYears + yearsToFill;
		releaseFailures = 0;
		lakeVolume = 0.0;
		lakeFilled = false;
		if (shouldBuildDam == false) {
			loopExit = true;
		}
		shouldBuildDam = false;
	}

	cout << setw(1);
	cout << "...done processing inflow batches." << endl;
	cout << "Summarizing..." << endl;
	cout << "Maximum number of release failures in any simulation: " << maxReleaseFailures << endl;

	if (loopExit == true) {
		cout << "It failed to fill in some cases, so an average cannot be computed." << endl;
		cout << "This is probably a bad place to build a dam." << endl;
	}
	else {
		cout << "Average number of years to fill: " << totalFillYears / FIFTEEN_YEAR_PREDICTION << endl;
	}

	cout << "...Done.";

	system("pause");
	return 0;
}

