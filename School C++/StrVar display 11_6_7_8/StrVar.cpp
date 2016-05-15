//display 11.8
//Adam Holt

//This is the IMPLeMENTATION FILE: strvar.cpp
//9Your system may require some suffix other then .cpp.)
//This is th IMPLEMENTATION  of the class StringVar.
//The interface for the class StringVar is in the header file StrVar.h
#include <iostream.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "StrVar.h"

//Uses stddef and stdlib.h
StringVar::StringVar(int size)
{
	max_length=size;
	value=new char[max_length+1];//+1 is for '\0'
	if(value==NULL)
	{
		cout<<"Error: Insufficient memory."<<endl;
		exit(1);
	}
	value[0]='\0';
}

//uses stddef and stdlib.h
StringVar::StringVar()
{
	max_length=100;
	value=new char[max_length+1];//+1 is for '\0'.
	if(value== NULL)
	{
		cout<<"Error: Insufficient memory."<<endl;
		exit(1);
	}

	value[0]='\0';
}

//uses sting .h , stddef, and std lib.h
StringVar::StringVar(const char *a)
{
	max_length=strlen(a);
	value=new char[max_length+1];
	if(value==NULL)
	{
		cout<<"Error: Insufficient memory."<<endl;
		exit(1);
	}
	strcpy(value,a);
}

StringVar::StringVar(const StringVar& string_object)
{
	max_length=string_object.length();
	value=new char[max_length+1];
	if(value==NULL)
	{
		cout<<"Error: Insufficient Memory."<<endl;
		exit(1);
	}
	strcpy(value,string_object.c_str());
}

StringVar::~StringVar()
{
	delete [] value;
}

const char * StringVar::c_str()const
{
	return value;
}

int StringVar::length()const
{
	return max_length;
}

void StringVar::input_line(istream& ins)
{
	ins.getline(value,max_length+1);
}


ostream& operator<<(ostream& outs,const StringVar& the_string)
{
	outs<<the_string.value;
	return outs;
}

