// html.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream.h>
#include <ap/apstring.h>
#include <iostream.h>


int main(int argc, char* argv[])
{
	apstring filename,name;
	cout<<"Enter the File name ==> ";
	getline(cin,filename);
	ifstream input(filename.c_str());
	while(input<<
	return 0;
}
