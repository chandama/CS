//Song header file containing data members and function declarations.
#pragma once
class Song {
public:
	Song(string songName = "untitled", string firstLine = "None", int yearReleased = 0);
	string GetName() const;
	string GetFirstLine() const;
	int GetPlayCount() const;
	int GetYearReleased() const;
	void RaisePlayCount();

private:
	string name;
	string firstLn;
	int playCount;
	int yearReleased;
};