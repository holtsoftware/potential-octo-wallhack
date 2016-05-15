//Demonstrates the functjion read_and_clean
//Display 10.3
//Adam Holt

#include <iostream.h>
#include <stdlib.h>
#include <ctype.h>

void read_and_clean(int &n);

void new_line();

int main()
{
	int n;
	char ans;
	do 
	{
		cout<<"Enter an integer and press return: ";
		read_and_clean(n);
		cout<<"That string converts to the interger "<<n<<endl
			<<"Again? (Y/N): ";
		cin>>ans;
		new_line();
	}while(toupper(ans)!='N');
	return 0;
}

void read_and_clean(int& n)
{
	const int ARRAY_SIZE=6;
	char digit_string[ARRAY_SIZE];
	char next;
	cin.get(next);
	int index=0;
	while(next!='\n')
	{
		if((isdigit(next)) && index<(ARRAY_SIZE-1))
		{
			digit_string[index]=next;
			index++;
		}
		cin.get(next);
	}
	digit_string[index]='\0';

	n=atoi(digit_string);
}

void new_line()
{
	char next='-';
	while(next!='\n')
	{
		cin.get(next);
	}
}
