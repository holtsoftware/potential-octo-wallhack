#ifndef _READFILE_H_
#define _READFILE_H_

#include "object.h"
#include <lvector.h>
#include <fstream>
#include <string>
using namespace std;

class readfile  
{
public:
	readfile();
	readfile(string,object &);
	~readfile();

	int read(string,object &);
private:
	string getword(ifstream &,char);
	string getline(ifstream &in,char);
};

#endif