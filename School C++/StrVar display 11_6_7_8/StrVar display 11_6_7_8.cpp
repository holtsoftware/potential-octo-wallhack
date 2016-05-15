//Display 11.7
//Adam Holt

//Program to demonstrate use of theclass StringVar.
#include < iostream.h>
#include "StrVar.h"

void conversation(int);
//Carries on a conversation with the user.

void main()
{
	conversation(30);
	cout<<"End of demonstratoin."<<endl;
}

//this is only a demonstration functoin:
void conversation(int max_size)
{
	StringVar your_name(max_size), our_name("Borg");

	cout<<"What is your name?"<<endl;
	your_name.input_line(cin);
	cout<<"We are "<<our_name<<endl;
	cout<<"we will meet again "<<your_name<<endl;
}