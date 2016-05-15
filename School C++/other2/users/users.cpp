#include "stdafx.h"
#include <iostream.h>
#include <fstream.h>
#include <ap/apstring.h>
#include <ap/apvector.h>

struct user{
	apstring password;
	apstring number;
	apstring name;
	apstring username;
};

void loadusers(apvector<user> &users);
void getuser(const apvector<user> &dusers);


int main(int argc, char* argv[])
{
	apvector<user> users(0);
	loadusers(users);
	getuser(users);
	return 0;
}

bool validuser(const apvector<user> &fuser,const apstring &vuser,int &whare)
{
	for(int t=0;t<fuser.length();t++)
	{
		if(fuser[t].username==vuser)
		{
			whare=t;
			return true;
		}
	}
	return false;
}

bool validpassword(const apvector<user> &user,const apstring &vuser,const apstring &vpassword)
{
	int place=0;
	if(validuser(user,vuser,place))
	{
		if(user[place].password==vpassword)
			return true;
		else
			return false;
	}
	else
		return false;
}

void getuser(const apvector<user> &dusers)
{
	apstring username="",password="";
	int ption=0;
	while(!validpassword(dusers,username,password))
	{
		cout<<"Enter your user name ==> ";
		getline(cin,username);
		if(validuser(dusers,username,ption))
		{
			cout<<"Enter your password ==> ";
			getline(cin,password);
			if(validpassword(dusers,username,password))
			{
				cout<<"Welcome "<<dusers[ption].name<<"."<<endl;
				return ;
			}
			else
				cout<<"Invalid Password!"<<endl;
		}
		else
			cout<<"Invalid User!"<<endl;
	}



}



void loadusers(apvector<user> &users)
{
	int numberusers;
	ifstream userfile("users.dat");
	if(!userfile)
	{
		return;
	}
	userfile>>numberusers;
	userfile.ignore(1000,'\n');
	users.resize(numberusers);
	for(int i=0;i<numberusers;i++)
	{
		getline(userfile,users[i].password);
		getline(userfile,users[i].number);
		getline(userfile,users[i].name);
		getline(userfile,users[i].username);
		userfile.ignore(100,'\n');
	}
}


