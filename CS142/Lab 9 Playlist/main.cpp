/*Chandler Taylor, Section 002, chandler.taylor02@gmail.com
	Purpose: To create a funcioning playlist manager that also tracks song playcount
	Inputs: Song names, titles, playlist names, songs to add to playlists.
	Outputs: The program will "play" playlists by outputting the first lines of each song
		in a selected playlist and raise the playcount of each song played by one
	Test Cases: Since error checking isn't included in this lab the test cases are just to 
		test the functionality of the program itself assuming correct user inputs.
		1. Inputs: 1, Back in Black, I'm back in black, STOP, 2
		   Output: The song correctly displayed with a playcount of 0
		2. Inputs (continued from test case 1) 1, YYZ, no lyrics, 3, Classic Rock,
				4, 0, 1, 5, 0, 4, 1, 1, 5
		   Output: The program correctly created and played a playlist.
		3. Inputs (continued) 2
		   Output: The song YYZ correctly showed a playcount of 2 after being played 
				previous test case from 2 different playlists.
	Conclusion: The program correctly creates and manages a library of songs and user playlists
		as intended and will also correctly track playcount of the songs regardless of what	
		playlist they were played from which shows that the pointers and classes are all working
		as they should be.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Song.h"
#include "Playlist.h"

void AddNewSong(vector<Song*>& addToList) {
	bool exitLoop = false;
	string newSongName;
	string songFirstLine;

	while (exitLoop == false) {
		cout << "Song Name (type \"STOP\" when done): ";
		getline(cin, newSongName);
		if (newSongName == "STOP") {
			break;
		}
		cout << endl;
		cout << "That song's first line: ";
		getline(cin, songFirstLine);
		Song *newSong = new Song(newSongName, songFirstLine);
		addToList.push_back(newSong);
	}
}
void ListAllSongs(vector<Song*>& printList) {
	for (unsigned int i = 0; i < printList.size(); ++i) {
		cout << i << ": Name: \"" << printList.at(i)->GetName() << "\" FirstLine: \""
			<< printList.at(i)->GetFirstLine() << "\" Played "
			<< printList.at(i)->GetPlayCount() << " times." << endl;
	}
	return;
}
void ListAllSongsWOFirstLines(vector<Song*>& printList) {
	for (unsigned int i = 0; i < printList.size(); ++i) {
		cout << i << ": " << printList.at(i)->GetName() <<  endl;
	}
	return;
}
void AddNewPlaylist(vector<Playlist>& addPlaylist) {
	string playlistName;
	cout << "Playlist name: ";
	getline(cin, playlistName);	
	Playlist newPlaylist(playlistName);
	addPlaylist.push_back(newPlaylist);
	cout << endl;
	return;
}
void ListAllPlaylists(vector<Playlist>& printPlaylist) {
	for (unsigned int i = 0; i < printPlaylist.size(); ++i) {
		cout << i << ": " << printPlaylist.at(i).GetPlaylistName() << endl;
	}
	return;
}
void AddSongToPlaylist(vector<Playlist>& userPlaylists, vector<Song*>& songList) {
	int songIndexNumber = -1;
	int playlistIndexNumber = -1;

	cout << "Add to a playlist:" << endl;
	ListAllPlaylists(userPlaylists);
	cout << "Pick a playlist index number: ";
	cin >> playlistIndexNumber;
	cout << endl;
	cout << "Find a song to add:" << endl;
	ListAllSongsWOFirstLines(songList);
	cout << "Pick a song index number: ";
	cin >> songIndexNumber;
	cin.ignore();
	userPlaylists.at(playlistIndexNumber).PlaylistAddSong(songList.at(songIndexNumber));
	return;
}
void PlayPlaylist(vector<Playlist>& userPlaylists) {
	int playlistIndex = -1;

	cout << "Pick a playlist to play:" << endl;
	ListAllPlaylists(userPlaylists);
	cout << "Pick a playlist index number: ";
	cin >> playlistIndex;
	cin.ignore();
	cout << endl;
	cout << "Playing first lines:" << endl;
	userPlaylists.at(playlistIndex).PlayFirstLines();
	return;
}
void PrintSizeGreater(vector<Song*>& songList) { //Might not need for final
	int minSize = 0;

	cout << "Enter a size: ";
	cin >> minSize;
	for (unsigned int i = 0; i < songList.size(); ++i) {
		if (songList.at(i)->GetSize() > minSize) {
			cout << songList.at(i)->GetName() << " and has size " //ToStr Function here
				<< songList.at(i)->GetSize() << " MB." << endl;
		}
	}
}
void DeletePlaylist(vector<Playlist>& userPlaylists) {
	int playlistIndex = -1;

	cout << "Pick a playlist to delete:" << endl;
	ListAllPlaylists(userPlaylists);
	cout << "Pick a playlist index number: ";
	cin >> playlistIndex;
	cin.ignore();
	cout << endl;
	userPlaylists.erase(userPlaylists.begin() + playlistIndex);
}
void DeleteAllDuplicatesFromLibrary(vector<Playlist>& duplicatePlaylist, vector<Song*>& songList) {
	Song* songPtr; //Might not need a temp pointer if you compare each i to the j's after it.
	for (unsigned int i = 0; i < songList.size(); i++) {
		songPtr = songList.at(i); //Dont need this if you delete the tempPtr
		for (unsigned int j = i; j < songList.size(); j++) {
			if (songList.at(i) == songList.at(j)) { //OR if (songList.at(i) == songList.at(j))
				//Move Pointers to duplicate song in playlists to original song
					//Do this by looping and if a playlist has a pointer to the
					//duplicate song than move that pointer to the song you're keeping
					// and do this for each song looping through each playlist
				//Delete the duplicate song fromg SongList
			}
		}
	}
}
void SortByTimesPlayed(vector<Song*>& songList) {
	Song* tempPtr;
	for (unsigned int i = 0; i < (songList.size() - 1); ++i) {
		for (unsigned int j = 0; j < (songList.size() - 1); j++) {
			if (songList.at(j)->GetPlayCount() > songList.at(j + 1)->GetPlayCount()) {
				tempPtr = songList.at(j);
				songList.at(j) = songList.at(j + 1);
				songList.at(j + 1) = tempPtr;
			}
		}
	}
}

void ExecuteChoice(vector<Song*>& songList, vector<Playlist>& playlistVector, int menuOption) {
	switch (menuOption) {
	case 1:
		cout << "Read in Song names and first lines:" << endl;
		AddNewSong(songList);
		break;
	case 2:
		ListAllSongs(songList);
		break;
	case 3:
		AddNewPlaylist(playlistVector);
		break;
	case 4:
		AddSongToPlaylist(playlistVector, songList);
		break;
	case 5:
		PlayPlaylist(playlistVector);
		break;
	case 6:
		DeletePlaylist(playlistVector);
		break;
	case 7: //Might not need for final****************************
		PrintSizeGreater(songList);
		break;
	case 8: 
		DeleteAllDuplicatesFromLibrary(playlistVector, songList);
		break;
	}
}
int main() {
	int userOption = -1;
	vector<Song*> songList;
	vector<Playlist> userPlaylist;
		
	cout << "Welcome to the Firstline Player!" << endl << endl;
	do {
		cout << "Please select one of the following options:" << endl << endl;
		cout << "0 - Quit the program" << endl;
		cout << "1 - Add songs" << endl;
		cout << "2 - List all songs" << endl;
		cout << "3 - Add a playlist" << endl;
		cout << "4 - Add a song to a playlist" << endl;
		cout << "5 - Play a playlist" << endl;
		//cout << "6 - Delete a playlist" << endl;
		//cout << "7 - Print playlists greater than a given size" << endl << endl; //Might not need
		//cout << "8 - Delete duplicate songs from library"
		cout << "Enter your selection now: ";
		cin >> userOption;
		cin.ignore();
		cout << endl;
		ExecuteChoice(songList, userPlaylist, userOption);

	} while (userOption != 0);

	for (unsigned int i = 0; i < songList.size(); ++i) { //It was i=1 but I think that was an error
		delete songList.at(i);
	}

	cout << "GOODBYE!" << endl;
    return 0;
}