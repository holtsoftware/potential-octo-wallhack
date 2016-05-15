//this is the application file: dtime.cpp 
//this program demonstrates use of the class DigitalTime
//Adam Holt

#include <iostream.h>
#include "DigitalTime.h"

void main()
{
	DigitalTime clock,old_clock;
	
	cout<<"Enter the time in 24 hour notation: ";
	cin>>clock;

	old_clock = clock;
	clock.advance(15);
	if(clock==old_clock)
		cout<<"Something is wrong.";
	cout<<"You entered " <<old_clock<<endl;
	cout<<"15 minutes later the time will be "
		<<clock<<endl;
	clock.advance(2,15);
	cout<<"2 hours and 15 minutes after that"<<endl
		<<"The time will be "<<clock<<endl;

}