#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Song
{
private:
	string name;
	string firstLine;
	int timesPlayed;
public:
	Song(string nameIn, string firstLineIn/*, int timesPlayedIn*/);
	Song();
	~Song();
	string GetName();
	string GetFirstLine();
	int GetTimesPlayed();

	void SetName(string nameIn);
	void SetFirstLine(string firstLineIn);
	void SetTimesPlayed(int timesPlayedIn);
	void IncreaseTimesPlayed();
	void DecreaseTimesPlayed();
	string ToString();

};

