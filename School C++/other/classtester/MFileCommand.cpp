#include "MFileCommand.h"

MFileCommand::MFileCommand()
:homedir("C:\\temp2\\"),homedrive("C:"),DosTextEditer("C:\\temp2\\","C:")
{
	_chdir(homedir);
}
MFileCommand::MFileCommand(const char *path,const char *drive)
: homedir(path),homedrive(drive),DosTextEditer("C:\\temp2\\","C:")
{
	_chdir(homedir);
}
MFileCommand::~MFileCommand()
{
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void MFileCommand::ls(const string &arg)
{
	string tofind,the_path;
	static char path[_MAX_PATH];
	struct _finddata_t c_file;
	long hFile;
	int count=0,keep_going=1;
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];


	if( _getdcwd(_getdrive(), path, _MAX_PATH ) == NULL )
	{
	}
	the_path=path;
	the_path+="\\*.*";

	_splitpath(the_path.c_str(), drive, dir, fname, ext );

	the_path=dir;
	the_path=MSF::replace(the_path,MSF::replace(homedir,homedrive,"").c_str(),"/");
	the_path=MSF::replace(the_path,"\\\\","\\");
	the_path=MSF::replace(the_path,"\\","/");

	//if theres arg != "" then display arg as well
	(arg=="")?
		cout<<"Path: ["<<the_path<<"]"<<endl:
	    cout<<"Path: ["<<the_path<<arg.c_str()<<"]"<<endl;

	if(arg=="")
	{
		if((hFile = _findfirst("*.*",&c_file))==-1L)//findes the first file in the dir
		{
			cout<<"No files in dir."<<endl;//if no files in the dir display
		}
		else
		{
			cout<<c_file.name<<endl;//display the first file name
			count++;
			while((_findnext(hFile,&c_file)==0)&&keep_going)//keep displaying files in the dir tell theres no more or user did q on a more
			{
				if(!((the_path=="/") && (c_file.name[0]=='.' && c_file.name[1]=='.')))
				{
					cout<<c_file.name<<endl;//display the name of the file
					count++;
				}
				if(count>=SSize)
				{
					(do_more())?count=0:keep_going=0;
				}
			}
		}
	}
	else
	{
		if((hFile = _findfirst(arg.c_str(),&c_file))==-1L)//findes the first file in the dir meating the arg requirments
		{
			cout<<"No files that mach "<<arg.c_str()<<"."<<endl;//if none do display this
		}
		else
		{
			cout<<c_file.name<<endl;//display the first files name
			count++;
			while((_findnext(hFile,&c_file)==0)&&keep_going)//keep displaying files in the dir that mach arg tell theres no more or user did q on a more
			{
				if(!((the_path=="/") && (c_file.name[0]=='.' && c_file.name[1]=='.')))
				{
					cout<<c_file.name<<endl;//display the name of the file
					count++;
				}
				if(count>=SSize)
				{
					(do_more())?count=0:keep_going=0;//if the user dont wont to do more stop displaying
				}
			}
		}
	}
	_findclose(hFile);
}

void MFileCommand::cd(const string &arg)
{
	char temp[_MAX_PATH];
	string str;
	if(arg[0]=='/')
	{
		str=homedir;
		str+=MSF::replace(arg.substr(1,arg.length()),"/","\\");
		if(_chdir(str.c_str()))
		{
			cout<<arg.c_str()<<" isn't a dir."<<endl;
		}
		return;
	}
	else if(_chdir(MSF::replace(arg,"/","\\").c_str()))
	{
		cout<<arg.c_str()<<" isn't a dir."<<endl;
	}
	str=_getdcwd(_getdrive(),temp,_MAX_PATH);
	if(MSF::replace(str+"\\",MSF::replace(homedir,homedrive,"").c_str(),"")==(str+"\\"))
	{
		this->cd("/");
		cout<<arg.c_str()<<" isn't a dir."<<endl;
	}
}

int MFileCommand::do_more()
{
	char ch;
	cout<<"-MORE-";
	ch=_getch();
	cout<<endl;
	if(ch=='q' || ch=='Q')
	{
		return 0;
	}
	return 1;
}

void MFileCommand::mv(const string &old,const string &dest)
{
	rename(old.c_str(),dest.c_str());
}

void MFileCommand::mkdir(const string &tomake)
{
	char temp[_MAX_PATH];
	string str=_getdcwd(_getdrive(),temp,_MAX_PATH);
	str+="\\";
	str+=tomake;
	str=MSF::replace(str.c_str(),homedrive,"");
	if(_mkdir(str.c_str()))
	{
		cout<<"dir "<<tomake<<" was not created."<<endl;
	}
}

void MFileCommand::rmdir(const string &toremove)
{
		char temp[_MAX_PATH];
	string str=_getdcwd(_getdrive(),temp,_MAX_PATH);
	str+="\\";
	str+=toremove;
	str=MSF::replace(str.c_str(),homedrive,"");
	if(_rmdir(str.c_str()))
	{
		cout<<"dir "<<toremove<<" was not deleted."<<endl;
	}

}