//This is athe Header file digitaltime.h This is the Interface for the class digitaltime.
//values of this type are times of day. the values are impu and output in
//24 hour notation as in 9:20 for 9:30 AM and 14:45 for 2:45 pm.
//Adam Holt

#include <iostream.h>

#ifndef _DIGITALTIME_H_
#define _DIGITALTIME_H_

class DigitalTime
{
public:
	friend bool operator==(const DigitalTime& time1,const DigitalTime& time2);
	//Returns true if time1 and time 2 repersent the same time;
	//otherwise, returnd false.

	DigitalTime();
	//Initalizes the time value to 0:0(which is midnight);

	DigitalTime(int the_hour,int the_minute);
	//Precondition: 0<= the_hour <= 23 the_minute <=59.
	//Initalizes the time value to the_hour and the_minute.

	void advance(int minutes_added);
	//Preconditon: the object has a time value.
	//Postconition: the Time value has been changed to midutes_added minuts later.

	void advance(int houres_added,int minutes_added);
	//Preconditoin: the object has the time value.
	//Postcondition: the time value has been advanced hours_added hours plus minutes_added minutes.

	friend istream& operator>>(istream& ins,DigitalTime & the_object);
	//Overloads the >> operator for input values of type DigitalTime.
	//Precondition: if ins is a file input stream , then ins has already been connected to a file.

	friend ostream& operator<<(ostream& outs, const DigitalTime& the_object);
	//overloads teh << operator fore output  values of type DigitalTime.
	//Precondition: if outs is a file output stream, then outs has already been connected to a file.

private:
	int hour;
	int minute;
};

#endif