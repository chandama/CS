/* Chandler Taylor, chandler.taylor05@gmail.com, Section 002
Purpose: To manage a group of residential and commercial properties and print a tax report for them.
Inputs: The user is prompted for a file name containing the info of the properties.
Outputs: The program outputs the properties, their addresses, value, occupation status,
	rental or not, and if they qualify for a discounted tax rate. The program then proceeeds
	to calculate the taxes for each property. The user is prompted for a file path if he or she
	wants to save the file. The program also sorts the properties from lowest tax rate to highest.
Test Cases: There is only one possible test case since there is only one input file
	Input: Test.txt
	Output: 

*/

#include "Property.h"
#include "Residential.h"
#include "Commercial.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void inputFile(vector<Property*>& propList) {
	string fileName;
	string line;
	string propType;
	string rental;
	string occupationStatus;
	string propAddress;
	string propDiscount;
	double value = 0.0;
	double disRate = 0.0;
	ifstream input;

	cin >> fileName;
	input.open(fileName.c_str());

	cout << endl;
	while (getline(input, line)) {
		stringstream ss(line);
		ss >> propType;
		if (propType == "Residential") {
			if (ss >> rental >> value >> occupationStatus) {
				getline(ss, propAddress);
				Property* house = new Residential(rental, value, occupationStatus, propAddress);
				propList.push_back(house);
			}
			else {
				cout << "\n Ignoring INVALID Unknown Residential Input: " << line << endl;
			}
		}
		else if (propType == "Commercial") {
			if (ss >> rental >> value >> propDiscount >> disRate) {
				getline(ss, propAddress);
				Property* newProperty = new Commercial(rental, value, propDiscount, disRate, propAddress);
				propList.push_back(newProperty);
			}
			else {
				cout << "\n Ignoring INVALID Unknown Commercial Input: " << line << endl;
			}
		}
		else {
			cout << "\n Unknown bad input: " << line << endl;
		}
	}
	input.close();
	cout << endl;
}
void listAllProperties(vector<Property*>& propList) {
	cout << "All properties: " << endl;
	for (int unsigned i = 0; i < propList.size(); i++) {
		cout << propList.at(i)->toString() << endl << endl;
	}
	cout << endl;
}
void listPropertyTaxes(vector<Property*>& taxList, ofstream& output) {
	cout << "TAX REPORT: " << endl;
	output << "TAX REPORT: " << endl;
	for (int unsigned i = 0; i < taxList.size(); i++) {
		cout << taxList.at(i)->tax() << endl << endl;
		output << taxList.at(i)->tax() << endl << endl;
	}
}
void listPropTaxesNoOstream(vector<Property*>& sortList) {
	cout << "TAX REPORT: " << endl;
	for (int unsigned i = 0; i < sortList.size(); i++) {
		cout << sortList.at(i)->tax() << endl << endl;
	}
}
void sortProperties(vector<Property*>& sortList) {
	Property* tempPtr;
	for (unsigned int i = 0; i < (sortList.size() - 1); i++) {
		for (unsigned int j = 0; j < (sortList.size() - 1); j++) {
			if ((sortList.at(j)->taxtoString()) >(sortList.at(j + 1)->taxtoString())) {
				tempPtr = sortList.at(j);
				sortList.at(j) = sortList.at(j + 1);
				sortList.at(j + 1) = tempPtr;
			}
		}
	}
}
int main() {
	vector<Property*> propertyList;
	vector<Property*> sortedList;
	ofstream output("Output.txt");
	string outputFilePath;


	cout << "starting..." << endl;
	cout << "Where should I read the data from: ";

	inputFile(propertyList);
	listAllProperties(propertyList);
	listPropertyTaxes(propertyList, output);
	cout << "Where should I write the report (just press return to skip):";
	cin.ignore();
	getline(cin, outputFilePath);
	cout << endl << endl;
	cout << "SORTED VERSION:" << endl << endl;
	sortedList = propertyList;
	sortProperties(sortedList);
	listPropTaxesNoOstream(sortedList);
	//system("pause");
	return 0;
}