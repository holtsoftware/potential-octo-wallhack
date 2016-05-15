#ifndef _MFILECOMMAND_H
#define _MFILECOMMAND_H

#include "mystrfuncs.h"
#include "DosTextEditer.h"
#include <io.h>
#include <direct.h>
#include <conio.h>
#include <LinkList.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define SSize 20

class MFileCommand:public DosTextEditer
{
public:
	MFileCommand();
	MFileCommand(const char *,const char *);
	~MFileCommand();

	void ls(const string &arg="");
	void cd(const string &arg="");
	void mv(const string &old,const string &dest);//move or rename
	void mkdir(const string &);
	void rmdir(const string &);
private:
	int do_more();
	const char *homedir,*homedrive;
};

#endif