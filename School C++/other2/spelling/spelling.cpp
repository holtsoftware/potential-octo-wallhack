#include "stdafx.h"
#include <ap/apstring.h>
#include <iostream.h>
#include <fstream.h>
#include <ap/apvector.h>
#include <time.h>


bool loaddict(const apstring &,apvector<apstring> &, apvector<bool> &);
bool loaddict(const apstring &,apvector<apstring> &);
void save(const apstring &,const apvector<apstring> &,const apvector<bool> &);
ostream &operator<<(ostream &,const apvector<apstring> &);
apstring pickword();
istream &operator>>(istream &,bool &);


int main()
{
	apvector<apstring> words(10,"");
	for(int i=0;i<words.length();i++)
	{
		words[i]=pickword();
	}
	cout<<words; 
	return 0;
}


apstring pickword()
{
	srand(time(NULL));
	apvector<apstring> words;
	apvector<bool> used(1,false);
	int letter='a';
	apstring filename="dict/dict_";
	filename+=char(letter);
	filename+=".dict";
	bool loaded=loaddict(filename,words,used);
	if(!loaded)
	{
		return "No word was loaded!";
	}
	int num=rand()%words.length();
	while(used[num])
		num=rand()%words.length();
	
	used[num]=true;
	save(filename,words,used);
	if(words[num].find('_')!=npos)
	{
		words[num][words[num].find('_')]=' ';
	}
	return words[num];
}
		




ostream &operator<<(ostream &output,const apvector<apstring> &toout)
{
	for(int i=0;i<toout.length();i++)
	{
		output<<toout[i]<<endl;
	}
	return output;
}

istream &operator>>(istream &input,bool &con)
{
	int the;
	input>>the;
	if(the==0)
		con=false;
	else if(the ==1)
		con=true;
	else
		cout<<"Error in file!"<<endl;
	return input;
}

bool loaddict(const apstring &filename,apvector<apstring> &words,apvector<bool> &used)
{
	ifstream file(filename.c_str(),ios::nocreate);
	if(file.fail())
	{
		cout<<"load faild!"<<endl;
		return false;
	}
	int temp,i;
	file>>temp;
	words.resize(temp);
	used.resize(temp);
	for(i=0;i<temp;i++)
	{
		file>>words[i];
		file>>used[i];
	}
	return true;
}

bool loaddict(const apstring &filename,apvector<apstring> &words)
{
	ifstream file(filename.c_str(),ios::nocreate);
	if(file.fail())
	{
		cout<<"load faild!"<<endl;
		return false;
	}
	int temp,i,c;
	file>>temp;
	words.resize(temp);
	for(i=0;i<temp;i++)
	{
		file>>words[i];
		file>>c;
	}
	return true;
}


void save(const apstring &filename,const apvector<apstring> &words,const apvector<bool> &used)
{
	ofstream file(filename.c_str());
	file<<words.length()<<endl<<endl<<endl;
	for(int i=0;i<words.length();i++)
	{
		file<<words[i]<<endl;
		file<<used[i]<<endl;
	}
}