// Ele.cpp: implementation of the Ele class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ele.h"
#include <iostream.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ele::Ele()
{
	numfloors=2;
	door=Close;
	curfloor=1;
}
Ele::Ele(const int num_floors)
{
	numfloors=num_floors;
	door=Close;
	curfloor=1;
}
Ele::Ele(const int num_floors,const int startfloor)
{
	numfloors=num_floors;
	door=Close;
	if(startfloor<1)
		cout<<"Invalid start floor trying to be initulisad"<<endl;
	curfloor=startfloor;
}
/////////////////////////////////////////////////////////////////////
//End of constructors
/////////////////////////////////////////////////////////////////////
void displayd(const int dp,const int floor)
{
	cout<<"                    "<<floor<<endl;
	int i,k;
	for(k=0;k<23;k++)
	{
		for(i=0;i<20-dp;i++)
		{
			cout<<'@';
		}
		if(dp==0)
			cout<<'|';
		else{
			cout<<'|';
			for(i=0;i<((dp*2)-1);i++)
				cout<<' ';
			cout<<'|';
		}
		for(i=0;i<20-dp;i++)
		{
			cout<<'@';
		}
		cout<<endl;
	}		
}
/*	long i=0,k;
	for(k=0;k<20;k++)
	{
		displayd(k);
		for(i=0;i<19999999;i++);
	}
	for(i=0;i<99999999;i++);
	for(k=20;k>=0;k--)
	{
		displayd(k);
		for(i=0;i<19999999;i++);
	}*/
void Ele::opendoor()
{
	door=Open;
	for(int k=0;k<=20;k++)
	{
		displayd(k,curfloor);		
		for(int i=0;i<19999999;i++);
		if(k!=20)
			system("cls");
	}
}
void Ele::gotofloor(const int t_floor)
{
	if(t_floor<=numfloors&&t_floor>0)
		curfloor=t_floor;
	else if(t_floor<=0)
		curfloor=1;
	else
		curfloor=numfloors;
}

Ele::~Ele()
{

}
