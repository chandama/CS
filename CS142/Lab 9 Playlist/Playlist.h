//Playlist header file containing data members and function declarations.
#pragma once
#include "Song.h"
class Playlist {
public:
	Playlist(string playlistName);
	string GetPlaylistName() const;
	void PlaylistAddSong(Song* songIndex);
	void PlayFirstLines();
	void DeleteSong(int index);
	void DeleteSongByPtr(Song* deletePtr);
	void ListSongs();
private:
	vector<Song*> songs;
	string name;
};
