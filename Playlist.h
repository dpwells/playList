#pragma once
#include <vector>
#include "Song.h"

using namespace std;

class PlayList
{
private:
	vector <Song*> playList;
	string name;
public:
	PlayList(string nameIn);
	PlayList();
	~PlayList();

	string GetName();
	int GetPlayListSize();
	int FindSong(Song* songToDelete);

	void SetName(string nameIn);
	void AddSong(Song* songIn);
	void DeletSong(int index);
	void DisplaySongs();
	void Play();

};