#include "DosTextEditer.h"

DosTextEditer::DosTextEditer(const char *dir,const char *drive)
:homedir(dir),homedrive(drive)
{
	_chdir(dir);
	filename="default.txt";
}

DosTextEditer::~DosTextEditer()
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////Editer functions///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
void DosTextEditer::ed(const string &filen)
// pre filen must equal the file that you wont to open or "" if you wont to open the default file
// the default file is the last file edited or "default.txt"
{
	ifstream file;
	char Title[80],path[_MAX_PATH],tmp[_MAX_PATH];
	LinkList<string> tmpfile;
	string command,tmpstr;

	if(filen!="")
		filename=filen;

	_getdcwd(_getdrive(),path,_MAX_PATH);
	filename=mystrfuncs::replace(filename,"\\","/");
	if((tmpstr=mystrfuncs::strchrb(filename,'/'))!=filename)
	{
		tmpstr=mystrfuncs::replace(tmpstr,"/","\\");
		if(_chdir(tmpstr.c_str())!=0)
		{
			cerr<<"You need to enter a valid directory change."<<endl;
			_chdir(path);
			return;
		}
		else if(_getdcwd(_getdrive(),tmp,_MAX_PATH)==NULL)
		{
			cerr<<"An unexpected error accured."<<endl;
			_chdir(path);
			return;
		}
		else if(mystrfuncs::replace(string(tmp)+"\\",
			mystrfuncs::replace(homedir,homedrive,"").c_str(),"")==(string(tmp)+"\\"))
		{
			cerr<<"You need to enter a valid directory change."<<endl;
			_chdir(path);
			return;
		}
		else
		{
			_chdir(path);
		}
	}
	tmpstr=mystrfuncs::replace(filename,"/","\\");
	if(_access(tmpstr.c_str(),0)==0)
	{
		file.open(tmpstr.c_str(),ios::in);
		tmpstr=mystrfuncs::strchrb(filename,'/');
		if(tmpstr!=filename)
		{
			_chdir(tmpstr.c_str());
			sprintf(Title, "Editing: %s", 
				MSF::replace(string(_getdcwd(_getdrive(),tmp,_MAX_PATH))+"\\"+
				MSF::replace(filename,tmpstr.c_str(),""),
				homedir,"\\").c_str());
		}
		else
		{
			sprintf(Title,"Editing: %s",
				MSF::replace(string(_getdcwd(_getdrive(),tmp,_MAX_PATH))+"\\"+
				filename,homedir,"\\").c_str());
		}
		cout<<MSF::replace(Title,"\\","/")<<endl;
		if(!file.is_open())
		{
			cout<<"Error opening "<<filename<<endl;
		}
		while(!file.eof())
		{
			MSF::getline(file,tmpstr);
			tmpfile.resize(tmpfile.length()+1);
			tmpfile[tmpfile.length()-1]=tmpstr;
		}
		tmpfile.resize(tmpfile.length()-1);
		file.close();
		atline=tmpfile.length()-1;
	}
	else
	{
		tmpstr=MSF::strchrb(filename,'/');
		if(tmpstr!=filename)
			_chdir(tmpstr.c_str());
		sprintf(Title, "Editing: %s [New File]", 
			mystrfuncs::replace(string(_getdcwd(_getdrive(),tmp,_MAX_PATH))+"\\"+filename,
			homedir,"\\").c_str());
		cout<<mystrfuncs::replace(Title,"\\","/")<<endl;
		atline=0;
	}
	_chdir(path);
	SetConsoleTitle(mystrfuncs::replace(Title,"\\","/").c_str());
	edcommand(":",cout,tmpfile);
	SetConsoleTitle(MSF::replace(MSF::replace(string(path)+"\\",homedir,"/"),"\\","/").c_str());
	cout<<"Exit from ed."<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
string & DosTextEditer::edcommand(string prompt,ostream &out,LinkList<string> &tmpfile)
// pre: string is == to the prompt you wont and ostream == to the stream you wont to output too tmpfile == the file you have opend
{
	string tmpstr;
	unsigned __int8 changed=0;
	do
	{
		cout<<prompt;
		MSF::getline(cin,tmpstr);
		if(tmpstr[0]!='Q')
		{
			tmpstr=MSF::tolower(tmpstr);
		}
		if(do_range(tmpstr,tmpfile,changed,out));
		else if(do_double(tmpstr,tmpfile,changed,out));
		else if(do_single(tmpstr,tmpfile,changed,out));
		else
		{
			cout<<"Bad command."<<endl;
		}
	}while(tmpstr[0]!='Q');
	return filename;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
int DosTextEditer::do_range(string &tmpstr,LinkList<string> &tmpfile,unsigned __int8 &changed,ostream &out)
{
	int start=0,stop=0,line=0;
	char ch=' ',ch2=' ';
	if(sscanf(tmpstr.c_str(),"%d,%d%c%d",&start,&stop,&ch,&line)==4)
	{
		if(start>0 && start<stop && stop<tmpfile.length() && ch=='m' && line>0 &&
			line<tmpfile.length() && (line<start || line>stop))
		{
		}
		else
		{
			out<<"Bad range index."<<endl;
		}
	}
	else if(sscanf(tmpstr.c_str(),"%d,%d%c",&start,&stop,&ch)==3)
	{
		if(start>0 && start<stop && start<tmpfile.length() && stop<=tmpfile.length())
		{
			if(ch=='c')
			{
				for(int i=start;i<=stop;i++)
				{
					tmpfile.delat(start-1);
				}
				changed=1;
				MSF::getline(cin,tmpstr);
				while(tmpstr!=".")
				{
					tmpfile.addinat(start++,tmpstr);
					MSF::getline(cin,tmpstr);
				}
				atline=start-1;
				tmpstr="  ";
			}
			else if(ch=='d')
			{
				for(int i=start;i<=stop;i++)
				{
					tmpfile.delat(start-1);
				}
				atline=stop-1;
			}
			else
			{
				out<<"Bad range index."<<endl;
			}
		}
	}
	else if(sscanf(tmpstr.c_str(),"%d,%d",&start,&stop)==2)
	{
		if(start>0 && start<stop && start<tmpfile.length() && stop<=tmpfile.length())
		{
			for(int i=start;i<=stop;i++)
			{
				out<<tmpfile[abs(i-1)]<<endl;
			}
		}
		else
		{
			out<<"Bad range index."<<endl;
		}
	}
	else if(sscanf(tmpstr.c_str(),"%d,%c%c",&start,&ch,&ch2)==3)
	{
		if(start>0 && start<tmpfile.length() && ch=='$' && ch2=='c')
		{
			start--;
			changed=1;
			MSF::getline(cin,tmpstr);
			while(tmpstr!=".")
			{
				tmpfile.addinat(start++,tmpstr);
				MSF::getline(cin,tmpstr);
			}
			atline=start-1;
			tmpstr="  ";
		}
		else if(start>0 && start<tmpfile.length() && ch=='$' && ch2=='d')
		{
			stop=tmpfile.length();
			changed=1;
			for(int i=start;i<=stop;i++)
			{
				tmpfile.delat(start-1);
			}
			atline=start-1;
		}
		else
		{
			out<<"Bad range"<<endl;
		}
	}
	else if(sscanf(tmpstr.c_str(),"%d,%c",&start,&ch)==2)
	{
		if(start>0 && start<=tmpfile.length() && ch=='$')
		{
			for(int i=start;i<=tmpfile.length();i++)
			{
				out<<tmpfile[abs(i-1)]<<endl;
			}

		}
		else
		{
			out<<"Bad range index."<<endl;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
int DosTextEditer::do_double(string &tmpstr,LinkList<string> & tmpfile,unsigned __int8 &changed,
							 ostream &out)
{
	int start=0,stop=0;
	char ch=' ';
	if(sscanf(tmpstr.c_str(),"%d%c",&start,&ch)==2)
	{
		if(ch=='a' && start<=tmpfile.length() && start>0)
		{
			stop=0;
			MSF::getline(cin,tmpstr);
			while(tmpstr!=".")
			{
				tmpfile.addinat(start+stop,tmpstr);
				stop++;
				MSF::getline(cin,tmpstr);
			}
			changed=1;
			atline=start+stop-1;
		}
		else if(ch=='i' && start<=tmpfile.length() && start>0)
		{
			stop=0;
			MSF::getline(cin,tmpstr);
			while(tmpstr!=".")
			{
				tmpfile.addinat(start-1+stop,tmpstr);
				stop++;
				MSF::getline(cin,tmpstr);
			}
			changed=1;
			atline=start+stop-2;
		}
		else if(ch=='c' && start<=tmpfile.length() && start>0)
		{
			stop=0;
			MSF::getline(cin,tmpstr);
			tmpfile.delat(start-1);
			while(tmpstr!=".")
			{
				tmpfile.addinat(start-1+stop,tmpstr);
				stop++;
				MSF::getline(cin,tmpstr);
			}
			changed=1;
			atline=start+stop-1;
		}
		else if(ch=='d' && start<=tmpfile.length() && start>0)
		{
			changed=1;
			tmpfile.delat(start-1);
			atline=start-1;
		}
		else
		{
			out<<"Bad command."<<endl;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
int DosTextEditer::do_single(string &tmpstr,LinkList<string> &tmpfile,unsigned __int8 &changed,
							 ostream &out)
{
	int start=0,stop=0;
	char ch=' ';
	if(sscanf(tmpstr.c_str(),"%d",&start)==1)
	{
		if(start<=tmpfile.length() && start>0)
		{
			out<<tmpfile[start-1]<<endl;
			atline=start-1;
			changed=1;
		}
		else
		{
			out<<"Bad line number."<<endl;
		}
	}
	else if(tmpstr=="a")
	{
		MSF::getline(cin,tmpstr);
		while(tmpstr!=".")
		{
			tmpfile.addinat(atline,tmpstr);
			atline++;
			MSF::getline(cin,tmpstr);
		}
		tmpstr="  ";
		changed=1;
	}
	else if(tmpstr=="$")
	{
		out<<tmpfile[tmpfile.length()-1]<<endl;
	}
	else if(tmpstr=="w")
	{
		if(_access(filename.c_str(),0)==0)
		{
			remove(filename.c_str());
		}
		ofstream outfile(filename.c_str());
		if(outfile.fail())
		{
			out<<"Failed to write to file."<<endl;
		}
		else
		{
			start=0;
			changed=0;
			for(int i=0;i<tmpfile.length();i++)
			{
				outfile<<tmpfile[i]<<endl;
				start+=tmpfile[i].length()+sizeof(char);
			}
			start+=tmpfile.length();
			outfile.close();
			
		}
		char path[_MAX_PATH];
		if(_getdcwd(_getdrive(),path,_MAX_PATH)!=NULL)
		{
			tmpstr=path;
			tmpstr+="\\";
			tmpstr=MSF::replace(tmpstr,homedir,"\\");
			tmpstr=MSF::replace(tmpstr,"\\","/");
			out<<"\""<<tmpstr+filename<<"\" "<<tmpfile.length()<<" lines "<<start<<" bytes"<<endl;
			tmpstr="  ";
		}
	}
	else if(tmpstr=="q")
	{
		if(changed==0)
		{
			tmpstr="Q";
		}
		else
		{
			out<<"File has been changed."<<endl;
		}
	}
	else if(tmpstr[0]=='Q');
	else
	{
		return 0;
	}
	return 1;
}