//This is the implementation file: dtime.cpp(your system may require some suffix other then .cxx).
//this is the implementation of the adt DigitalTime .
//the interface for the class DigitalTime is in the header file digitaltime.h
//Adam Holt

#include <iostream.h>
#include <ctype.h>
#include <stdlib.h>
#include "DigitalTime.h"

#define MIN_HOUR		0
#define MIN_MINUTE		0
#define MAX_HOUR		23
#define MAX_MINUTE		59
#define ERRORCODE		1
#define HOUR_IN_DAY		24
#define MINUTE_IN_HOUR	60
#define HAZ_2_DIGITES	10
#define ZERO			'0'

//These prototype are for the definition of the overloaded input operator>>:

void read_hour(istream& ins,int& the_hour);
//Precondition; Next input in the stream ins is a time in notation, like 9:45 or 14:45
//PostCondition: the+_hour has been set to the hour part of the time.
//The colon has been discarded and the next imput to be read is the minute.

void read_minute(istream & ins,int & the_minute);
//reads the minute from the stream ins after read_hour has read the hour.

int digit_to_int(char c);
//Precondition: c is one of the digits '0' through '9'
//returns the integer for the digit: e.g., digit_to_int('3') returns 3.

bool operator==(const DigitalTime& time1,const DigitalTime& time2)
{
	return(time1.hour==time2.hour&&time1.minute==time2.minute);
}

DigitalTime::DigitalTime(int the_hour,int the_minute)
{
	if(the_hour<MIN_HOUR || the_hour>MAX_HOUR || the_minute<MIN_MINUTE||the_minute>MAX_HOUR)
	{
		cerr<<"Illegal argument to DigitalTime constructor.";
		exit(ERRORCODE);
	}
	else
	{
		hour=the_hour;
		minute=the_minute;
	}
}

DigitalTime::DigitalTime()
{
	hour=MIN_HOUR;
	minute=MIN_MINUTE;
}

void DigitalTime::advance(int minutes_added)
{
	int gross_minutes = minute + minutes_added;
	minute=gross_minutes%MINUTE_IN_HOUR;

	int hour_adjustment=gross_minutes/MINUTE_IN_HOUR;
	hour=(hour+hour_adjustment)%HOUR_IN_DAY;
}

void DigitalTime::advance(int houres_added,int minutes_added)
{
	hour=(hour+houres_added)%HOUR_IN_DAY;
	advance(minutes_added);
}

istream& operator >>(istream& ins, DigitalTime& the_object)
{
	read_hour(ins, the_object.hour);
	read_minute(ins,the_object.minute);
	return ins;
}

ostream& operator<<(ostream& outs, const DigitalTime& the_object)
{
	outs<<the_object.hour<<":";
	if(the_object.minute<HAZ_2_DIGITES)
		outs<<ZERO;
	outs<<the_object.minute;
	return outs;
}

int digit_to_int(char c)
{
	return(int(c)-int(ZERO));
}

void read_hour(istream& ins,int & the_hour)
{
	char c1,c2;
	ins>>c1>>c2;
	if(!(isdigit(c1)&&(isdigit(c2)||c2==':')))
	{
		cerr<<"Error illegal input to read_hour"<<endl;
		exit(ERRORCODE);
	}

	if(isdigit(c1)&&c2==':')
	{
		the_hour=digit_to_int(c1);
	}
	else
	{
		the_hour=digit_to_int(c1)*HAZ_2_DIGITES+digit_to_int(c2);
		ins>>c2;
		if(c2!=':')
		{
			cerr<<"Error illegal input to read_hour"<<endl;
			exit(ERRORCODE);
		}
	}
	
	if(the_hour<MIN_HOUR||the_hour>MAX_HOUR)
	{
		cerr<<"Error illegal input to read_hour"<<endl;
		exit(ERRORCODE);
	}
}

void read_minute(istream & ins, int & the_minute)
{
	char c1,c2;
	ins>>c1>>c2;

	if(!(isdigit(c1)&&isdigit(c2)))
	{
		cerr<<"Error illegal input to read_minute"<<endl;
		exit(ERRORCODE);
	}

	the_minute=digit_to_int(c1)*HAZ_2_DIGITES + digit_to_int(c2);

	if(the_minute<MIN_MINUTE || the_minute> MAX_MINUTE)
	{
		cerr<<"Error illegal input to read_minut"<<endl;
		exit(ERRORCODE);
	}
}
