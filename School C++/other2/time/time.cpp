#include "stdafx.h"
#include <time.h>
#include <iostream.h>
#include <wchar.h>


void main()
{
	tm *current=0;
	time_t st,curr=0;
	st=time(NULL);
	current=localtime(&st);
	long start=current->tm_sec,last,cu=0;
	cout<<current->tm_hour<<":"<<current->tm_min<<":"<<start<<endl;
	cu=current->tm_sec;
	do{
		st=time(NULL);
		current=localtime(&st);
		if(last!=current->tm_sec)
		{
			last=current->tm_sec;
			cu++;
		}
	}while(start+60>cu);
	cout<<current->tm_hour<<":"<<current->tm_min<<":"<<current->tm_sec<<endl;
}
