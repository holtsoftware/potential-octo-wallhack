#include<iostream.h>
#include <ap/apvector.h>
#include <ap/apstring.h>

void coutvector(apvector<apstring> &a)
{
	cout<<"[ ";
	for(int b=0;b<a.length();b++)
		cout<<a[b]<<" ";
	cout<<"]";
}