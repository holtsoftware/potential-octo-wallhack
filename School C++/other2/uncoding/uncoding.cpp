#include "stdafx.h"
#include <fstream.h>
#include <iostream.h>
#include <ap/apstring.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	apstring filename,temp;
	cout<<"Enter the file to be uncoded ==> ";
	getline(cin,filename);
	ifstream input(filename.c_str());
	getline(input,temp);
	int r=filename.find(".");
	filename=filename.substr(0,r);
	filename+="."+temp;
	ofstream output(filename.c_str());
	char c;
	while(input.get(c))
	{
		c-=10;
		output<<c;
		
	}
	cout<<"Compleat"<<endl;


	return 0;
}
