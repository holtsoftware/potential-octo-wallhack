#include "mystrfuncs.h"

mystrfuncs::mystrfuncs()
{
}

mystrfuncs::~mystrfuncs()
{
}

string mystrfuncs::replace(string temp,const char *find,const char *trepl)
{
	int found=0;
	for(int i=0;i<temp.length();i++)
	{
		if(temp[i]==find[0])
		{
			for(int t=i;(t-i)<strlen(find);t++)
			{
				found=1;
				if(temp[t]!=find[t-i])
				{
					found=0;
					break;
				}
			}
			if(found)
			{
				temp=temp.replace(i,strlen(find),trepl);
				i=i+strlen(trepl);
			}
		}
	}
	return temp;
}

int mystrfuncs::instr(string temp,char find)
{
	for(int i=0;i<temp.length();i++)
	{
		if(temp[i]==find)
		{
			return i;
		}
	}
	return -1;
}

void mystrfuncs::getline(istream &in,string &str)
{
	str="";
	char temp;
	in.get(temp);
	while(temp!='\n' && !in.eof())
	{
		str+=temp;
		in.get(temp);
	}
}

string mystrfuncs::toupper(const string &str)
{
	string to_return;
	for(int i=0;i<str.length();i++)
	{
		to_return+=::toupper(str[i]);
	}
	return to_return;
}

string mystrfuncs::tolower(const string &str)
{
	string to_return=str;
	for(int i=0;i<str.length();i++)
	{
		to_return[i]=::tolower(to_return[i]);
	}
	return to_return;
}

string mystrfuncs::strchrb(const string &str,char tofind)
{
	int last=str.length()-1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==tofind)
			last=i;
	}
	return str.substr(0,last+1);
}