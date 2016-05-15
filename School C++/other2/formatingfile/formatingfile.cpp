#include "stdafx.h"
#include <iostream.h>
#include <fstream.h>
#include <ap/apstring.h>
#include <ap/apvector.h>



int main(int argc, char* argv[])
{
	apvector<apstring> words(1,"0");
	ifstream file("dict_a.dict",ios::nocreate);
	int count=0;
	while(file>>words[count])
	{
		words.resize(words.length()+1);
		count++;
	}
	words.resize(words.length()-1);
	ofstream output("dict_a.dict");
	output<<words.length()<<endl<<endl<<endl;
	for(int i=0;i<words.length();i++)
	{
		output<<words[i]<<endl<<0<<endl;
	}

	return 0;
}
