#include "stdafx.h"
#include <ap/apstring.h>
#include <ap/apvector.h>
#include <iostream.h>
#include <fstream.h>
#include <conio.h>



bool find(apstring &,bool &,apstring &,apstring &);
bool load(const apstring &filename,apvector<apstring> &words,apvector<int> &);
void getdef(apstring &);
void savedef(const apstring &def,const apstring &word);
apstring inttostr(int num);
void save(apstring &,apstring &);


int main()
{
	cout<<"\tWelcome to the dictinary program!!!"<<endl;
	apstring word="0";
	apstring def="",filename="";
	while(word!="<.>")
	{	
		cout<<"Enter a word (<.> to end) ==> ";
		getline(cin,word);
		if(word=="<.>")
			continue;
		bool foundw,foundd=find(word,foundw,def,filename);
		if(!foundw)
		{
			cout<<"The word "<<word<<" is not in the dictionary."<<endl;
		}
		else if(!foundd)
		{
			cout<<"There is no definition defined for "<<word<<" do you want to define one ==> ";
			char c;
			cin.get(c);
			cin.ignore(100,'\n');
			if(c=='y'||c=='Y')
			{
				def="";
				cout<<"Enter the definition (<.>) to end \n(e.g.) A cow like animal. <.> \n==> ";
				getdef(def);
				cout<<def<<endl;
				savedef(def,word);
			}
		}
		else 
		{
			char c='o';
			cout<<word<<" "<<def<<endl<<endl;
			cout<<"Do you want to change the definition (y or n) ==>";
			cin>>c;cin.ignore(100,'\n');
			if(c=='y')
			{
					def="";
				cout<<"Enter the definition (<.>) to end \n(e.g.) A cow like animal. <.> \n==> ";
				getdef(def);
				cout<<def<<endl;
				save(def,filename);
			}
		}

	}
	return 0;
}

void save(apstring &def,apstring &filename)
{
	fstream file(filename.c_str(),ios::in | ios::out);
		file<<def;
}

bool find(apstring &word,bool &foundword,apstring &def,apstring &filname)
{
	apvector<apstring> words;
	apvector<int> filename;
	foundword=false;
	apstring fn="words/dict_";
	fn+=word[0];
	fn+=".dict";
	load(fn,words,filename);
	for(int i=0;i<words.length();i++)
	{
		while(words[i].find('_')>npos)
		{
			words[i][words[i].find('_')]=' ';
		}
		if(words[i]==word)
		{
			foundword=true;
			if(filename[i]>0)
			{
				apstring temp="words/def/a";
				temp+=inttostr(filename[i]);
				temp+=".def";
				filname=temp;
				ifstream file(temp.c_str(),ios::nocreate);
				def="";
				while(!file.fail())
				{
					char i;
					file.get(i);
					def+=i;
				}
				return true;
			}
		}
	}
	return false;
}

void getdef(apstring &def)
{
	char c;
	while(true)
	{
		cin.get(c);
		if(c=='<')
		{
			cin.get(c);
			if(c=='.')
			{
				cin.get(c);
				if(c=='>')
				{
					return;
				}
				else
				{
					def+="<.";
					def+=c;
				}
			}
			else
			{
				def+='<';
				def+=c;
			}
		}
		else
			def+=c;
	}
}



bool load(const apstring &filename,apvector<apstring> &words,apvector<int> &filelocation)
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
	filelocation.resize(temp);
	for(i=0;i<temp;i++)
	{
		file>>words[i];
		file>>filelocation[i];
	}
	return true;
}


apstring inttostr(int num)
{
	if(num==1)
	{
		return "1";
	}
	int count=0,temp=1;
	while(num>temp)
	{
		count++;
		temp*=10;
	}
	apstring number="";
	int times=temp/10,mod=temp;
	for(int i=0;i<count;i++)
	{
		number+=char(((num%mod)/times)+'0');
		times/=10;
		mod/=10;
	}
	return number;
}




void savedef(const apstring &def,const apstring &word)
{
	apvector<apstring> words;
	apvector<int> defnum;
	load("words/dict_a.dict",words,defnum);
	apstring filename="words/def/a";
	int count=0;
	for(int k=0;k<words.length();k++)
	{
		if(defnum[k]>=count)
		{
			count=defnum[k]+1;
		}
	}
	filename+=inttostr(count);
	filename+=".def";
	for(int i=0;i<words.length();i++)
	{
		
		if(words[i]==word)
		{
			defnum[i]=count;
		}
	}
	ofstream file(filename.c_str());
	if(file.fail())
		cout<<"save failed!"<<endl;
	file<<def;
	file.close();
	file.open("words/dict_a.dict");
	file<<words.length()<<endl<<endl<<endl;
	for(int d=0;d<words.length();d++)
	{
		while(words[d].find(' ')!=npos)
		{
			words[d][words[d].find(' ')]='_';
		}
		file<<words[d]<<endl;
		file<<defnum[d]<<endl;
	}

}


