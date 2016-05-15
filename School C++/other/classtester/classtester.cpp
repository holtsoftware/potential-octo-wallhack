#include "MFileCommand.h"
#include "mystrfuncs.h"

void main()
{
	string strcmd,tmpstr;
	mystrfuncs funcs;
	int pos;
	system("COLOR 0f");
	MFileCommand cmd;
	while(tmpstr!="quit")
	{
		cout<<">";
		MSF::getline(cin,strcmd);

		pos=funcs.instr(strcmd,' ');
		if(pos>=0)
		{
			tmpstr=strcmd.substr(0,pos);
			strcmd=strcmd.substr(pos+1,strcmd.length());
		}
		else
		{
			tmpstr=strcmd;
			strcmd="";
		}

		if(tmpstr=="ls")
		{
			cmd.ls(strcmd);
		}
		else if(tmpstr=="quit")
		{
		}
		else if(tmpstr=="cd")
		{
			cmd.cd(strcmd);
		}
		else if(tmpstr=="mkdir")
		{
			cmd.mkdir(strcmd);
		}
		else if(tmpstr=="rmdir")
		{
			cmd.rmdir(strcmd);
		}
		else if(tmpstr=="ed")
		{
			cmd.ed(strcmd);
		}
		else
		{
			cout<<"huh?"<<endl;
		}
	}

}