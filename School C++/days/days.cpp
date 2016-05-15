//days.cpp is a program that randomly generates and displays
//the day of the week.

#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

enum days{Sun,Mon,Tue,Wed,Thr,Fry,Sat};

void main()
{
	int randumday;
	char ceapgoing='y';

	srand(time(NULL));
	while (ceapgoing=='y'||ceapgoing=='Y')
	{

		randumday=rand()%(Sat+1);

		switch(randumday)
		{
		case Sun:
			cout<<"Sunday"<<endl;
			break;
		case Mon:
			cout<<"Monday"<<endl;
			break;
		case Tue:
			cout<<"Tuesday"<<endl;
			break;
		case Wed:
			cout<<"Wenday"<<endl;
			break;
		case Thr:
			cout<<"Thursday"<<endl;
			break;
		case Fry:
			cout<<"Fryday"<<endl;
			break;
		case Sat:
			cout<<"Saturday"<<endl;
			break;
		default:
			cout<<"Error"<<endl;
		}
		cout<<"Keep going"<<endl;
		ceapgoing=char(getche());
		cout<<endl;
	}
}