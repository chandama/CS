/* Chandler Taylor, Section 002, chandler.taylor05@gmail.com
Purpose: To create a program that will store and edit a user's notes
Inputs: Various menu functions inluding: add note, insert note , replace note, replacefirst instance,
replace all instances, print notes, quit program.
Outputs: The user may enter "print" to print the list of notes and any changes that may have been made.
Also when using the replace first or replace all functions, the program outputs the number of
corrections made.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ListMenu() {

	cout << "Options for the Notes program are : " << endl;
	cout << "\"add\" - Add a note." << endl;
	cout << "\"print\" - Print notes." << endl;
	cout << "\"remove\" - Remove a note." << endl;
	cout << "\"insert\" - Insert a note." << endl;
	cout << "\"replacefirst\" - Replace first occurrence of a phrase in each note." << endl;
	cout << "\"replaceall\" - Replace all occurrences of a phrase in each note." << endl;
	cout << "\"quit\" - quit the Notes program." << endl;

	return;
}

void AddNote(vector<string>& addVector) {
	string newNote;

	getline(cin, newNote);
	addVector.push_back(newNote);

	return;
}

void PrintNotes(const vector<string> printVector) {
	cout << "Current List of notes: " << endl;

	for (int i = 0; i < printVector.size(); ++i) {
		cout << "Note " << (i + 1) << ": " << printVector.at(i) << endl;
	}
	return;
}

vector<string> RemoveNote(const vector<string> removeVector, int noteNumber) {
	vector<string> updatedVector;

	for (int i = 0; i < noteNumber - 1; ++i) {
		updatedVector.push_back(removeVector.at(i));
	}
	for (int i = noteNumber; i < removeVector.size(); ++i) {
		updatedVector.push_back(removeVector.at(i));
	}

	return updatedVector;
}

void InsertNote(vector<string>& insertVector, int insertLocation) {
	vector<string> tempVector;
	int vectorSize = insertVector.size();

	for (int i = 0; i < insertLocation - 1; ++i) {
		tempVector.push_back(insertVector.at(i));
	}
	cout << "Enter new note: ";
	AddNote(tempVector);

	for (int i = insertLocation - 1; i < insertVector.size(); ++i) {
		tempVector.push_back(insertVector.at(i));
	}
	insertVector.resize(0);
	for (int i = 0; i < tempVector.size(); ++i) {
		insertVector.push_back(tempVector.at(i));
	}

	return;
}

void ReplaceFirst(vector<string>& replaceVector) {
	string vectorString;
	string searchPhrase;
	string replacePhrase;
	int searchLength = 0;
	int replacementsDone = 0;

	cout << "Enter search phrase: ";
	getline(cin, searchPhrase);
	searchLength = searchPhrase.length();
	cout << endl;

	cout << "Enter replace phrase: ";
	getline(cin, replacePhrase);
	cout << endl;

	for (int i = 0; i < replaceVector.size(); ++i) {
		vectorString = replaceVector.at(i);
		if (vectorString.find(searchPhrase) != string::npos) {
			vectorString.replace(vectorString.find(searchPhrase), searchLength, replacePhrase);
			replaceVector.at(i) = vectorString;
			replacementsDone++;
		}
	}

	cout << replacementsDone << " replacements done." << endl;

	return;
}

void ReplaceAll(vector<string>& replaceAllVector) {
	string vectorString;
	string searchPhrase;
	string replacePhrase;
	int searchLength = 0;
	int replacementsDone = 0;

	cout << "Enter search phrase: ";
	getline(cin, searchPhrase);
	searchLength = searchPhrase.length();
	cout << endl;

	cout << "Enter replace phrase: ";
	getline(cin, replacePhrase);
	cout << endl;

	for (int i = 0; i < replaceAllVector.size(); ++i) {
		vectorString = replaceAllVector.at(i);
		while (vectorString.find(searchPhrase) != string::npos) {
			if (vectorString.find(searchPhrase) != string::npos) {
				vectorString.replace(vectorString.find(searchPhrase), searchLength, replacePhrase);
				replaceAllVector.at(i) = vectorString;
				replacementsDone++;
			}
		}
	}

	cout << replacementsDone << " replacements done." << endl;

	return;
}

int main() {
	vector<string> noteVector;
	string menuInput;
	int noteToRemove = 0;
	int noteInsertNumber = 0;
	bool menuExit = false;

	cout << "*** Notes Program *** - type \"list\" to see options" << endl << endl;
	while (menuExit == false) {
		cout << "Option: ";
		getline(cin, menuInput);
		if (menuInput == "list") {
			ListMenu();
		}
		else if (menuInput == "add") {
			cout << "Enter note: ";
			AddNote(noteVector);
		}
		else if (menuInput == "print") {
			PrintNotes(noteVector);
		}
		else if (menuInput == "remove") {
			cout << "Note number to remove: ";
			cin >> noteToRemove;
			cin.ignore();
			noteVector = RemoveNote(noteVector, noteToRemove);
		}
		else if (menuInput == "insert") {
			cout << "New inserted note number: ";
			cin >> noteInsertNumber;
			cin.ignore();
			InsertNote(noteVector, noteInsertNumber);
		}
		else if (menuInput == "replacefirst") {
			ReplaceFirst(noteVector);
		}
		else if (menuInput == "replaceall") {
			ReplaceAll(noteVector);
		}
		else if (menuInput == "quit") {
			menuExit = true;
		}
	}
	cout << "Good Bye.";

	return 0;
}

