#ifndef _DOSTEXTEDITER_H_
#define _DOSTEXTEDITER_H_

#include <LinkList.h>
#include <mystrfuncs.h>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DosTextEditer
{
public:
	DosTextEditer(const char *,const char *);
	~DosTextEditer();

	void ed(const string &);//starts editing the file name that was pased or the last file ed if no filename was pased or "default.txt"
protected:
	string & edcommand(string,ostream &,LinkList<string> &);//string filename,string prompt,ostream output
private:
	//string is the string to be anlyesd,LinkList<string> is the file buffer,int & is used to 
	//indecate wether or not the file has been changed
	int do_range(string &,LinkList<string> &,unsigned __int8 &,ostream &);//checks range for in the editer i.e.(1,$ | 1,3c | ect.)
	int do_double(string &,LinkList<string> &,unsigned __int8 &,ostream &);//checks double in the editer i.e.(1c | 1a | $c | ect.)
	int do_single(string &,LinkList<string> &,unsigned __int8 &,ostream &);//checks single in the editer i.e.(1 | a | c | $ | ect.)
	const char *homedir,*homedrive;
	string filename;
	int atline;
};
#endif