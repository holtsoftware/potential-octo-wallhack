#ifndef _FILEBUF_H_
#define _FILEBUF_H_

#include <LinkList.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class filebuf
{
public:

	enum open_mode { = 0x01,
                     = 0x02,
                     = 0x04,
                     = 0x08,
                     = 0x10,
                     = 0x20,
                     = 0x40,
                     = 0x80 };

	filebuf();
	filebuf(const char *);
	~filebuf();

	int open(const char *);
	int output(int start=0,int stop=size,ostream &out=cout);
	int write(const char *);
	int write();
	int insertb(int start,int stop);
	int insertb(int line);
	int inserta(int start,int stop);
	int inserta(int line);
	int del(int start,int stop);
	int del(int line);
	int move(int start,int stop,int to);
	int move(int start,int to);
	int getsize();
private:
	int size;
	char *filename;
	LinkList<string> filebufer;
};

#endif
