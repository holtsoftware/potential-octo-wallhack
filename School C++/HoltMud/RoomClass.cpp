#include <iostream.h>
#include <fstream.h>
#include <LinkList.h>
#include <ap/apstring.h>

Room::Room()
{
	exits.resize(0);
}

Room::~Room()
{
}

bool Room::change_room(const apstring &exit)
{
	for(int i=0;i<exits.length();i++)
	{
		if(exits[i].exitname==exit)
		{
			loadroom(exits[i].room_num);
			return true;
		}
	}
	return false;
}

bool Room::change_area(const apstring &filename)
{
	int room_num;
	ifstream area(filename.c_str(),ios::no_create);
	if(area.fail())
	{
		return false;
	}
	if(!(area>>room_num))
	{
		return false;
	}
	if(!(getline(area,roomn)))
	{
		return false;
	}
	if(!(getline(area,roomd)))
	{
		return false;
	}
	if(!(getexits(area)))
	{
		return false;
	}
	return true;
}

bool Room::getexits(ifstream &input)
{
	apstring exits;
	if(!(getline(input,exits)))
	{
		return false
	}
	int pos
	while
}