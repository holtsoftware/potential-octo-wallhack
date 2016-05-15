// Password.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <fstream.h>
#include <ap/apstring.h>

void sfile(apstring pass)
{
	ofstream passwordfile("Password.dat");
	passwordfile<<pass+10;
}

bool loadpassword(apstring &pass)
{
	ifstream passwordfile("Password.dat");
	if(passwordfile.is_open()==false)
	{
		return false;
	}
	getline(passwordfile,pass);
	return true;
}


int main(int argc, char* argv[])
{
	apstring password,password1;
	bool two;
	two=loadpassword(password);
	if(two==false)
	{
		cout<<"Enter a Pass Word ==> ";
		getline(cin,password);
		sfile(password);
	}
	else
	{
		cout<<"Enter your Pass Word ==> ";
		getline(cin,password1);
		if(password==password1)
		{
			
			char nes;
			cout<<"\t(c)ange";
			cin>>nes;
			if(nes=='c')
			{
				cin.ignore(100,'\n');
				cout<<"Enter new pass word ==> ";
				getline(cin,password);
				sfile(password);
			}
		}	
	}

	return 0;
}
