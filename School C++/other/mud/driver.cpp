#include "MFileCommand.h"

void main()
{
	MFileCommand test;
	test.ls(apstring("  f"));
/*	readfile file;
	object obj;
	file.read("test_room.c.txt",obj);
	obj.set("short","a test object");
	obj.set("long","    A test object that is used to test my code.\n"
		"you are welcome to stay her for now.");
	obj.set("exits","east:/u/g/grinder/room,south:/u/g/grinder/workroom.c,north:/u/g/grinder/rooms/secr.c");
	cout<<obj.query("short").c_str()<<endl;
	cout<<obj.query("long").c_str()<<endl;
	cout<<endl<<obj.displayexits().c_str()<<endl;
	cout<<obj.displaylocs().c_str()<<endl;*/
}