/*
David Wells
Section 3
dpwells9@gmail.com

calls for "delete" are on line 173 under "void DeleteLibrarySong()"
and line 182 under "void FreeMemory()"
////////////////////////////////////////////////////////////////////////////////////////////////////////////
Test case 1:

input:

expected out put:

actual out put:
////////////////////////////////////////////////////////////////////////////////////////////////////////////
Test case 2:

input:

expected out put:

actual out put:

////////////////////////////////////////////////////////////////////////////////////////////////////////////
Test case 3:

input:

expected out put:

actual out put:


*/
#include "Song.h"
#include "Playlist.h"

using namespace std;

void PrintMenu()
{
	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl;
	cout << endl;
}

void addToLibrary(vector <Song*> & library)
{
	string songName = "";
	string firstLine = "";
	cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;

	while (songName != "STOP")
	{
		cout << "Song Name:" << endl;
		getline(cin, songName);

		if (songName != "STOP")
		{
			cout << "Song's first line:" << endl;
			getline(cin, firstLine);
			library.push_back(new Song(songName, firstLine));
		}
	}
}

void DisplayLibrary(vector <Song*> library)
{
	for (unsigned int i = 0; i < library.size(); i++)
	{
		cout << i << ": " <<library.at(i)->GetName() << endl;
	}
	cout << endl;
}

void AddPlayList(vector <PlayList> & playLists)
{
	string input = "";
	cout << "Playlist name: " << endl;
	getline(cin, input);
	cout << endl;
	PlayList newPlayList(input);
	playLists.push_back(newPlayList);
}

void DisplayPlayLists(vector <PlayList>  playLists)
{
	for (unsigned int i = 0; i < playLists.size(); i++)
	{
		cout << i << ": " <<playLists.at(i).GetName() << endl;
	}
	cout << endl;
}

void AddSongToPlayList(vector <PlayList> & playLists , vector <Song*> & library)
{
	int PlayListInput = 0;
	int SongInput = 0;
	DisplayPlayLists(playLists);
	cout << "Pick a playlist index number:" << endl;
	cin >> PlayListInput;
	DisplayLibrary(library);
	cout << "Pick a song index number: " << endl;
	cin >> SongInput;
	cout << endl;
	playLists.at(PlayListInput).AddSong(library.at(SongInput));
}

void Play(vector <PlayList> playLists)
{
	if (playLists.size() > 0)
	{
		int playListIndex = 0;
		DisplayPlayLists(playLists);
		cout << "Pick a playlist index number:" << endl;
		cin >> playListIndex;
		playLists.at(playListIndex).Play();
	}

	else
	{
		cout << "There are no play lists to play from, Please create a playlist" << endl;
	}
	cout << endl;
}

void DeletePlayList(vector <PlayList> & playLists)
{
	int playListIndex = 0;
	DisplayPlayLists(playLists);
	cout << "Pick a playlist index number to delete: " << endl;
	cin >> playListIndex;
	playLists.erase(playLists.begin() + playListIndex);
}

void DeletePlayListSong(vector <PlayList> & playLists)
{
	int playListIndex = 0;
	int songIndex = 0;
	DisplayPlayLists(playLists);
	cout << "Pick a playlist index number:" << endl;
	cin >> playListIndex;
	playLists.at(playListIndex).DisplaySongs();
	cout << "Pick a song index number to delete:" << endl;
	cin >> songIndex;
	playLists.at(playListIndex).DeletSong(songIndex);
}

void DeleteLibrarySong(vector <PlayList> & playLists, vector <Song*> & library)
{
	const int NOT_FOUND = -1;
	int songIndex = 0;
	int songToDelete = 0;
	DisplayLibrary(library);
	cout << "Pick a song index number:" << endl;
	cin >> songIndex;

	for (unsigned int i = 0; i < playLists.size(); i++)
	{
		songToDelete = playLists.at(i).FindSong(library.at(songIndex));

		if (songToDelete != NOT_FOUND)
		{
			playLists.at(i).DeletSong(songToDelete);
		}
	}
	delete library.at(songIndex);
	library.erase(library.begin() + songIndex);
}

void FreeMemory(vector <Song*> & library)
{
	for (unsigned int i = 0; i < library.size(); i++)
	{
		delete library.at(i);
	}
}

int main()
{
	bool quit = false;
	bool validInput = false;
	string selection;
	vector <Song*> library;
	vector <PlayList> playLists;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;
	while (!quit)
	{
		validInput = false;
		cout << "Enter your selection now:" << endl;
		cin >> selection;
		cin.ignore();
		if (selection == "add")
		{
			addToLibrary(library);
			validInput = true;
			cout << endl;
		}

		if (selection == "list")
		{
			for (unsigned int i = 0; i < library.size(); i++)
			{
				cout << library.at(i)->ToString();
			}
			validInput = true;
			cout << endl;
		}


		if (selection == "addp")
		{
			AddPlayList(playLists);
			validInput = true;
			cout << endl;
		}


		if (selection == "addsp")
		{
			AddSongToPlayList(playLists , library);
			validInput = true;
			cout << endl;
		}


		if (selection == "listp")
		{
			DisplayPlayLists(playLists);
			validInput = true;
			cout << endl;
		}


		if (selection == "play")
		{
			Play(playLists);
			validInput = true;
			cout << endl;
		}


		if (selection == "delp")
		{
			DeletePlayList(playLists);
			validInput = true;
			cout << endl;
		}


		if (selection == "delsp")
		{
			DeletePlayListSong(playLists);
			validInput = true;
			cout << endl;
		}


		if (selection == "delsl")
		{
			DeleteLibrarySong(playLists , library);
			validInput = true;
			cout << endl;
		}


		if (selection == "options")
		{
			PrintMenu();
			validInput = true;
		}


		if (selection == "quit")
		{
			FreeMemory(library);
			quit = true;
			validInput = true;
			cout << "Goodbye!" << endl;
		}


		if (!validInput)
		{
			PrintMenu();
		}
	}
	//system("pause");
	return 0;
}