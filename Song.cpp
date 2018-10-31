#include "Song.h"
using namespace std;

Song::Song(string nameIn, string firstLineIn/*, int timesPlayedIn*/)
{
	name = nameIn;
	firstLine = firstLineIn;
	//timesPlayed = timesPlayedIn;
	timesPlayed = 0;
}
Song::Song()
{
	name = "none";
	firstLine = "none";
	timesPlayed = 0;
}
Song::~Song()
{

}

string Song::GetName()
{
	return name;
}


string Song::GetFirstLine()
{
	return firstLine;
}


int Song::GetTimesPlayed()
{
	return timesPlayed;
}


void Song::SetName(string nameIn)
{
	name = nameIn;
}


void Song::SetFirstLine(string firstLineIn)
{
	firstLine = firstLineIn;
}


void Song::SetTimesPlayed(int timesPlayedIn)
{
	timesPlayed = timesPlayedIn;
}


string Song::ToString()
{
	ostringstream oss;

	oss << name << ": \"";
	oss << firstLine << "\", ";
	oss << timesPlayed << " play(s)." << endl;

	return oss.str();
}


void Song::IncreaseTimesPlayed()
{
	timesPlayed++;
}


void Song::DecreaseTimesPlayed()
{
	timesPlayed--;
}