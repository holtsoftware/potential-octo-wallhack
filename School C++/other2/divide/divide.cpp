// divide.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <ap/apvector.h>

void out(const apvector<char> &);
int numx(const apvector<char> &);

int main(int argc, char* argv[])
{
	char temp;
	int count=0;
	apvector<char> divide(0,0);
	cout<<"Welcome!"<<endl;
	do{
		cin.get(temp);
		divide.resize(divide.length()+1);
		divide[count]=temp;
		count++;
	}while(temp!='\n');
	cout<<numx(divide);
	cout<<endl;
	return 0;
}

int numx(const apvector<char> &x)
{
	for(int t=0;t<x.length();t++)
	{
		if(x[t]=='^')
			return(x[t+1]-48);
	}
	return 0;
}
void getnums(const apvector<char> &findar,apvector<int> & 

void out(const apvector<char> &output)
{
	for(int t=0;t<output.length();t++)
		cout<<output[t];
}