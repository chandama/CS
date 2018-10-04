/*Chandler Taylor, Section 002, chandler.taylor02@gmail.com
Purpose: To expand no our earlier Playlist Lab adding new functionality
Inputs: Added 4 new inputs to old lab including:
1. Play random Song
2. Delete an entire playlist
3. Delete a song from a playlist
4. List all options
Outputs: These new 4 options will allow the user to play random songs "shuffle", to delete
an entire playlist by index number, delete the song pointer in a specific playlist,
and the "List all options" menu was a modification to the previous menu.
Test Cases: Not required
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

#include "Song.h"
#include "Playlist.h"

void AddNewSong(vector<Song*>& addToList) {
	bool exitLoop = false;
	string newSongName;
	string songFirstLine;
	int releaseYear = 0;

	while (exitLoop == false) {
		cout << "Song Name (type \"STOP\" when done): ";
		getline(cin, newSongName);
		if (newSongName == "STOP") {
			break;
		}
		cout << endl;
		cout << "That song's first line: ";
		getline(cin, songFirstLine);
		cout << "The year that song was released: ";
		cin >> releaseYear;
		cin.ignore();
		Song *newSong = new Song(newSongName, songFirstLine, releaseYear);
		addToList.push_back(newSong);
	}
}
void ListAllSongs(vector<Song*>& printList) {
	for (unsigned int i = 0; i < printList.size(); ++i) {
		cout << i << ": Name: \"" << printList.at(i)->GetName() << "\" FirstLine: \""
			<< printList.at(i)->GetFirstLine() << "\" Released in: "
			<< printList.at(i)->GetYearReleased() << " Played "
			<< printList.at(i)->GetPlayCount() << " times." << endl;
	}
	return;
}
void ListAllSongsWOFirstLines(vector<Song*>& printList) {
	for (unsigned int i = 0; i < printList.size(); ++i) {
		cout << i << ": " << printList.at(i)->GetName() << endl;
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
void DeletePlaylist(vector<Playlist>& userPlaylists) {
	int playlistIndex = -1;

	cout << "Delete a whole playlist: " << endl;
	ListAllPlaylists(userPlaylists);
	cout << "Pick a playlist index number: ";
	cin >> playlistIndex;
	cin.ignore();
	cout << endl;
	userPlaylists.erase(userPlaylists.begin() + playlistIndex);
}
void PlayRandomSongs(vector<Song*>& songList) {
	int songsToPlay = 0;
	int randomIndexNumber = -1;
	cout << "How many songs do you want played: ";
	cin >> songsToPlay;
	cout << "Playing random first lines: " << endl;
	for (unsigned int i = 0; i < songsToPlay; ++i) {
		randomIndexNumber = rand() % songList.size();
		cout << songList.at(randomIndexNumber)->GetFirstLine() << endl;
		songList.at(randomIndexNumber)->RaisePlayCount();
	}
}
void DeleteSongFromPlaylist(vector<Playlist>& deletePlaylists) {
	int indexNumber = -1;
	int deleteNumber = -1;

	cout << "Delete a song from a playlist: " << endl;
	ListAllPlaylists(deletePlaylists);
	cout << "Pick a playlist index number: ";
	cin >> indexNumber;
	cout << endl;
	cout << "Choose the song to delete: " << endl;
	deletePlaylists.at(indexNumber).ListSongs();
	cout << "Pick a song index number: ";
	cin >> deleteNumber;
	deletePlaylists.at(indexNumber).DeleteSong(deleteNumber);
	return;
}
void DeleteSongEverywhere(vector<Playlist>& userPlaylists, vector<Song*>& songList) {
	int userIndex = -1;
	Song* tempPtr = 0;
	cout << "Choose a song to delete: " << endl;
	ListAllSongsWOFirstLines(songList);
	cout << "Pick a song index number: ";
	cin >> userIndex;
	cout << endl;
	tempPtr = songList.at(userIndex);
	for (unsigned int i = 0; i < userPlaylists.size(); ++i) {
		userPlaylists.at(i).DeleteSongByPtr(tempPtr);
	}
	delete tempPtr;
	songList.erase(songList.begin() + userIndex);
	return;
}
void PrintMenu() {
	cout << "Please select one of the following options:" << endl << endl;
	cout << "0 - Quit the program" << endl;
	cout << "1 - Add songs" << endl;
	cout << "2 - List all songs" << endl;
	cout << "3 - Add a playlist" << endl;
	cout << "4 - Add a song to a playlist" << endl;
	cout << "5 - Play a playlist" << endl;
	cout << "6 - Play random songs" << endl;
	cout << "7 - Delete a whole playlist" << endl;
	cout << "8 - Delete a song from a playlist" << endl;
	cout << "9 - Delete a song from everywhere" << endl;
	cout << "10 - List all options" << endl;
	return;
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
		PlayRandomSongs(songList);
		break;
	case 7:
		DeletePlaylist(playlistVector);
		break;
	case 8:
		DeleteSongFromPlaylist(playlistVector);
		break;
	case 9:
		DeleteSongEverywhere(playlistVector, songList);
		break;
	case 10:
		PrintMenu();
		break;
	}
}
int main() {
	srand(42);
	int userOption = -1;
	vector<Song*> songList;
	vector<Playlist> userPlaylist;

	cout << "Welcome to the Firstline Player!" << endl << endl;
	do {
		cout << "Enter your selection now (Enter 10 to list all options): ";
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