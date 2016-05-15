#ifndef _MYSTRFUNCS_H_
#define _MYSTRFUNCS_H_

#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

#ifndef _UNICODE
    #ifdef _DEBUG
        #pragma comment(lib, "d:\\my c++ utilitys\\mystrfunc.lib")
    #else
        #pragma comment(lib, "d:\\my c++ utilitys\\mystrfuncs.lib")
    #endif
#else
    #ifdef _DEBUG
        #pragma comment(lib, "d:\\my c++ utilitys\\mystrfunc.lib")
    #else
        #pragma comment(lib, "d:\\my c++ utilitys\\mystrfuncs.lib")
    #endif
#endif

class mystrfuncs
{
public:
	mystrfuncs();
	~mystrfuncs();

	static int instr(string,char);//returns the first accurence of the char in the string -1 indicats it was not found
	static void getline(istream &,string &);//string will = the next line in the istream
	static string replace(string temp,const char *find,const char *trepl);//returns the temp with all the accurences of find replaced with trepl
	static string toupper(const string &);//returns the string in all upper case charicters
	static string tolower(const string &);//returns the string in all lower case charicters
	static string strchrb(const string &str,char tofind);//returns str exept for the charicters after the last accurence of tofind
};

#ifndef MSF
#define MSF mystrfuncs
#endif

#endif