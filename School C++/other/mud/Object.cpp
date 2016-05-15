#include "object.h"

object::object()
{
}

object::~object()
{
}

void object::set(const string &index,const string &data)
{
	if(query(index)==UNDEFINED)
	{
		ob.resize(ob.length()+1);
		ob[ob.length()-1].index=index;
		ob[ob.length()-1].data=data;
	}
	else
	{
		for(int i=0;i<ob.length();i++)
		{
			if(ob[i].index==index)
			{
				ob[i].data=data;
				return;
			}
		}
	}
}

string object::query(const string &index)
{
	for(int i=0;i<ob.length();i++)
	{
		if(ob[i].index==index)
		{
			return ob[i].data;
		}
	}
	return UNDEFINED;
}

string object::firstpart(string &str,char sep)
{
	string to_return;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==sep)
		{
			to_return=str.substr(0,i);
			str=str.substr(i+1,str.length());
			return to_return;
		}
	}
	if(str.length()>0)
	{
		to_return=str;
		str="";
		return to_return;
	}
	return UNDEFINED;
}

string object::displayexits()
{
	string str=query("exits");
	string tmpstr;
	exits.resize(0);
	if(str==UNDEFINED)
	{
		return ("    There are no obvious exits.");
	}
	do
	{
		tmpstr=firstpart(str,':');
		if(tmpstr!=UNDEFINED)
		{
			exits.resize(exits.length()+1);
			exits[exits.length()-1].index=tmpstr;
			tmpstr=firstpart(str,',');
			exits[exits.length()-1].data=tmpstr;
		}
	}while(tmpstr!=UNDEFINED);

	tmpstr="    ";
	if(exits.length()==1)
	{
		tmpstr+="The only obvious exit is "+exits[0].index+".";
	}
	else if(exits.length()==2)
	{
		tmpstr+="Obvious exits are ";
		tmpstr+=exits[0].index+" and ";
		tmpstr+=exits[1].index+".";
	}
	else
	{
		tmpstr+="Obvious exits are:";
		for(int i=0;i<exits.length();i++)
		{
			if(i!=exits.length()-1)
			{
				tmpstr+=" "+exits[i].index+",";
			}
			else
			{
				tmpstr+=" and "+exits[i].index+".";
			}
		}
	}
	return tmpstr;
}

string object::displaylocs()
{
	string to_return="";
	displayexits();
	for(int i=0;i<exits.length();i++)
	{
		to_return+=exits[i].data+"\n";
	}
	return to_return;
}