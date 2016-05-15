//Program to demonstrate pointers and dynamic variables
//Display 11.2
//Adam Holt

#include <iostream.h>

void main()
{
	int *p1,*p2;

	p1=new int;
	*p1=42;
	p2=p1;
	cout<<"*p1 == "<<*p1<<endl;
	cout<<"*p2 == "<<*p2<<endl;

	*p2=53;
	cout<<"*p1 == "<<*p1<<endl;
	cout<<"*p2 == "<<*p2<<endl;

	p1=new int;
	*p1=88;
	cout<<"*p1 == "<<*p1<<endl;
	cout<<"*p2 == "<<*p2<<endl;

	cout<<"Hope you got the point of this example!"<<endl;
	delete p1;
	delete p2;
}