// horse race.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <ap/apvector.h>
#include <conio.h>

void winer(int);
void showhourse(int hpl,int a);
void hourserace();
void drawscreen(apvector<int> &hplace);
int genrand();

const int trackl=45;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	hourserace();
	return 0;
}
void firstshow()
{
	for(int r=0;r<3;r++)
		showhourse(1,r);
	cout<<"Hit Enter to start the race "<<endl;
	getch();
}

void hourserace()
{
	apvector<int> hp(3,1);
	firstshow();
	while(hp[1]!=trackl&& hp[2]!=trackl&&hp[0]!=trackl)
	{
			drawscreen(hp);
	}
}



void drawscreen(apvector<int> &hplace)
{
	int wonornot=-1;
	system("cls");
	for(int e=0;e<3;e++)
	{
		if(genrand()>50)
				hplace[e]++;
		int c=hplace[e];
		showhourse(c,e);
		if(hplace[e]==trackl)
		{
			wonornot=e;
		}
	}
	if(wonornot>-1)
	{
		winer(wonornot);
	}
	for(long double c=0;c<=99999999;c++);
}

void winer(int winer)
{
	cout<<"The winer is "<<++winer<<endl;
}

void showhourse(int hpl, int a)
{
	cout<<++a<<"|";
	for(int i=1;i<=trackl;i++)
	{
		if(i==hpl)
			cout<<"H";
		else
			cout<<"-";
	}
	cout<<"|"<<endl;
	
}

int genrand()
{
	return(1+rand()%100);
}