/* Contains the member functions for the Song class with a constructor,
getter functions, and a function to raise the playcount */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include "Song.h"

Song::Song(string songName, string firstLine, int released) { //Might not need inpSize
	name = songName;
	firstLn = firstLine;
	playCount = 0;
	yearReleased = released;
}
string Song::GetName() const {
	return name;
}
string Song::GetFirstLine() const {
	return firstLn;
}
int Song::GetPlayCount() const {
	return playCount;
}
int Song::GetYearReleased() const {
	return yearReleased;
}
void Song::RaisePlayCount() {
	playCount++;
	return;
}


