// newcomand and delet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>


int main(int argc, char* argv[])
{
	double *p;
	p=new double;
	*p=5;
	cout<<*p<<endl;
	delete p;
	cout<<p<<endl;
	return 0;
}
