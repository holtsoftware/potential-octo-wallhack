//Program that ask the user for a word that is <= then 20 charicters 
// the Program then deturmes if the word is a Palindrome
//
//Adam Holt
//Date: 7/1/01

#include <iostream.h>
#include <ctype.h>

#define arraysize 20//The size of the array

bool isPalindrome(const char a[],const int);//returns true if a[] is a palindrom
int first_space(const char *a);//returns the first accurance of a space
void output(const char a[])//outputs a[] tell the first space
{
	int size=first_space(a);

	for(int i=0;i<size;i++)
	{
		cout<<a[i];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	char p[arraysize],temp;

	char keepgoing='Y';
	int count;
	
	while(keepgoing!='N')
	{
		for(int i=0;i<arraysize;i++)
		{
			p[i]=' ';
		}
		
		cout<<"Please enter a word that is less <= "<<arraysize<<" charicters long\nand i will tell you if it is a palandrome."<<endl;


		count=0;

		for(count=0;count<arraysize && temp != '.';count++)
		{
			cin>>temp;
			if(temp!='.')
			{
				p[count]=temp;
			}
		}
		
		if(isPalindrome(p,first_space(p)))
		{
			output(p);cout<<" is a palaindrom.";
		}
		else
		{
			cout<<"Sarry ";output(p);cout<<" is not a palaindrom.";
		}
		cout<<endl<<"Do you wont to test again?(Y/N)";
		cin>>keepgoing;
		keepgoing=toupper(keepgoing);
		temp=' ';
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
int first_space(const char *a)
{
	int i;

	for(i=0;i<arraysize &&a[i]!=' ';i++);

	if(i==0)
	{
		return 0;
	}
	else if(i>arraysize || i<0)
	{
		return 0;
	}
	else
	{
		return i;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
bool isPalindrome(const char a[],const int sp)
{
	int size = sp,i=0;
	bool Palindrom=true;

	for(i=0;i<int(size/2);i++)
	{
		if(!(a[i]==a[size-i-1]))
		{
			Palindrom=false;
		}
	}

	return Palindrom;
}
