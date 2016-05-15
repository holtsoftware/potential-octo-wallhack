#include "stdafx.h"
#include <iostream.h>


int main()
{
	const width=6;
	for(int i=2;i<15;i++)
	{
		cout.width(width);cout<<i;
	}
	cout<<endl;
	for(int k=2;k<15;k++)
	{
		cout.width(width);cout<<k*k;
	}
	cout<<endl;
	for(int d=2;d<15;d++)
	{
		cout.width(width);cout<<d*d*d;
	}
	cout<<endl;
	for(int f=2;f<15;f++)
	{
		cout.width(width);cout<<f*f*f*f;
	}
	cout<<"\n\n\n";

	return 0;
}
