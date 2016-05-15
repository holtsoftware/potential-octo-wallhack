#ifndef _ROOMCLASS_H_
#define _ROOMCLASS_H_

#include <ap/apstring.h>
#include <LinkList.h>
#include <fstream.h>
#include <iostream.h>

struct Rexit{
	apstring exitname;
	int room_num;
}

class Room
{
	friend ostream &operator <<(ostream &outs,const Room &);
public:
	//constructors/destructors
	Room();
	~Room();
	//memberfunctions
	bool change_room(const apstring &exit);
	bool change_area(const apstring &filename);
private:
	LinkList<Rexits> exits;
	apstring roomd;
	apstring roomn;
	apstring filename;
	bool loadroom(int roomnum);
	bool getexits(ifstream &);
};
#endif