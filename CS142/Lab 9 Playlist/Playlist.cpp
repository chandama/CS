/* Contains the member functions for the Playlist class where each playlist
is a vector of song pointers. Contains the functions the "play" the playlist
and add new songs to a certain playlist. */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

#include "Playlist.h"
#include "Song.h"

Playlist::Playlist(string playlistName) {
	name = playlistName;
}
string Playlist::GetPlaylistName() const {
	return name;
}
void Playlist::PlaylistAddSong(Song* songIndex) {
	songs.push_back(songIndex);
	return;
}
void Playlist::PlayFirstLines() {
	for (unsigned int i = 0; i < songs.size(); ++i) {
		cout << songs.at(i)->GetFirstLine() << endl;
		songs.at(i)->RaisePlayCount();
	}
	return;
}
void Playlist::DeleteSong(int index) {
	songs.erase(songs.begin() + index);
	return;
}
void Playlist::ListSongs() {
	for (unsigned int i = 0; i < songs.size(); ++i) {
		cout << i << ": " << songs.at(i)->GetName() << endl;
	}
	return;
}
void Playlist::DeleteSongByPtr(Song* deletePtr) {
	for (unsigned int i = 0; i < songs.size(); ++i) {
		Song* tempPtr = deletePtr;
		if (deletePtr->GetName() == songs.at(i)->GetName()) {
			tempPtr = deletePtr;
			songs.erase(songs.begin() + i);
		}
	}
	return;
}