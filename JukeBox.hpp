#include <iostream>

#include <cstdio>

class JukeBox {
public:
	Song GetCurrentSong() {
		return currentSong;
	}
private: 
	CDPlayer cdPlayer;
	User user;
	set<CD> cdCollection;
	Song currentSong;
};

class CDPlayer {
};

class PlayList {
public:
	void AddSong(Song song);
	void DeleteSong(Song song);
private:
	queue<Song> songList;
};
