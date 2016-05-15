/*chpter 6 lab:holidays
program to desplay the date of Memorialday,laberday, Election day,and thanksgiving
Adam Holt per.1*/

#include "stdafx.h"
#include <iostream.h>
#include <conio.h>
bool leapyear(int year)
{
	return (year%4==0&&(year%100!=0||year%400==0));
}

long years(int year)
{
	return (long(year - 1900) +(year - 1901)/4-(year -1901)/100+(year - 1601)/400);
}

int daysinmonth[12]={
	31,28,31,30,31,30,31,31,30,31,30,31};

int dayes(int startdate,int day)
{
	int output=startdate;
	for(int t=1;t<=daysinmonth[day-1];t++)
	{
		

		if(output==7)
		{
			output=0;
		}

		if(day==5&&t>24&&output==0)
		{
			cout<<"Memorial day is on "<<t<<" of May."<<daysinmonth[day-1]<<endl;
		}
		if(day==9&&t<8&&output==0)
		{
			cout<<"Labor day is on "<<t<<" of September."<<daysinmonth[day-1]<<endl;
		}
		if(day==11&&t>1&&t<9&&output==1)
		{
			cout<<"Election day is on "<<t<<" of November."<<daysinmonth[day-1]<<endl;
		}
		if(day==11&&t>19&&t<28&&output==3)
		{
			cout<<"Thanksgiving is on "<<t<<" of November."<<daysinmonth[day-1]<<endl;
		}
		output++;
	}
	return output;

	}

int main(int argc, char* argv[])
{
	int year, startdate;
	bool validyear=false;
	while (!validyear)
	{
		cout<<"Enter a year that is after 1900 ==> ";
		cin>>year;
		if(year>=1900)
			validyear=true;
	}
	if(leapyear(year)==true)
		daysinmonth[1]=29;
	startdate=years(year)%7;
	int month=1;
	for(int y=0;y<12;y++)
	{
		
		startdate=dayes(startdate,month);
		month++;
	}





	return 0;
}
