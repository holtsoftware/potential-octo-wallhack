#include "readfile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

readfile::readfile()
{
}

readfile::~readfile()
{

}

int readfile::read(string filename,object &myobj)
{
	char temp=' ',tmp=' ',*junk="";
	string word="";

	ifstream file(filename.c_str(),ios::nocreate);
	if(file.fail())
	{
		return 0;
	}

	while(file.get(temp))
	{
		if(temp=='/')
		{
			if(file.get(temp))
			{
				if(temp=='/')
				{
					getline(file,'\n');
				}
				else if(temp=='*')
				{
					do
					{
						if(!file.get(tmp))
						{
							return 0;
						}
						if(tmp!='/')
						{
							temp=tmp;
						}

					}while(temp!='*'&&tmp!='/');
				}
			}
			else
			{
				return 0;
			}
		}
		else if((temp>='A' && temp<='Z') || (temp>='a' && temp<='z') || 
			    (temp>='0' && temp<='9') || (temp=='_'))
		{

		}
	}
	file.close();
	return 1;
}

string readfile::getline(ifstream &in,char dil)
{
	string to_return;
	char temp;
	do
	{
		in.get(temp);
	    to_return+=temp;
	}while(temp!=dil);
	return to_return;
}

string readfile::getword(ifstream &file,char toadd)
{
	string toreturn="";
	while((toadd>='A' && toadd<='Z') || (toadd>='a' && toadd<='z') ||
		  (toadd>='0' && toadd<='9') || (toadd=='_'))
	{
		toreturn+=toadd;
		file.get(toadd);
	}
	file.putback(toadd);
	return toreturn;
}