#include <iostream.h>
#include <ctype.h>

void main()
{
	char upper[]="THIS WAS ALL UPPER-CASE!";
	char lower[50]="this was all lower-case!";
	int i;

	//Strings initialized useing double quotes get the '\0' character added automaticly

	cout<<"Before conversions, upper contained: "<<upper<<endl
		<<"lower contained: "<<lower<<endl;

	i=0;
	while(upper[i]!='\0')
	{
		upper[i]=tolower(upper[i]);
		i++;
	}
	i=0;
	while(upper[i]!='\0')
	{
		lower[i]=toupper(lower[i]);
		i++;
	}

	cout<<"After conversions."<<endl
		<<"upper contains: "<<upper<<endl
		<<"lower contains: "<<lower<<endl;
}