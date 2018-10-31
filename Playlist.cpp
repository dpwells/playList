#include "Playlist.h"

using namespace std;

PlayList::PlayList(string nameIn)
{
	name = nameIn;
}
PlayList::PlayList()
{
	name = "none";
}
PlayList::~PlayList()
{

}

string PlayList::GetName()
{
	return name;
}


int PlayList::GetPlayListSize()
{
	return playList.size();
}


void PlayList::SetName(string nameIn)
{
	name = nameIn;
}


void PlayList::AddSong(Song* songIn)
{
	playList.push_back(songIn);
}


void PlayList::DeletSong(int index)
{
	playList.erase(playList.begin() + index);
}


int PlayList::FindSong(Song* songToDelete)
{
	const int NOT_FOUND = -1;
	for (unsigned int i = 0; i < playList.size(); i++)
	{
		if (playList.at(i) == songToDelete)
		{
			return i;
		}
	}
	return NOT_FOUND;
}


void PlayList::DisplaySongs()
{
	for (unsigned int i = 0; i < playList.size(); i++)
	{
		cout << i << ": " << playList.at(i)->GetName() << endl;
	}
}


void PlayList::Play()
{
	cout << "Playing first lines of playlist : " << name << endl;
	if (playList.size() > 0)
	{
		for (unsigned int i = 0; i < playList.size(); i++)
		{
			cout << playList.at(i)->GetFirstLine() << endl;
			playList.at(i)->IncreaseTimesPlayed();
		}
	}
	/*else
	{
		cout << "The play list is empty, Please add a song to the play list" << endl;
	}*/
	
}