//Adam Holt
//Display 10.2
#include <iostream.h>
#include <string.h>

void string_copy(char target[],const char source[],int target_size);

void main()
{
	char short_string[11];
	string_copy(short_string,"Hello",11);
	cout<<short_string<<" STRING ENDS HERE."<<endl;

	char long_string[]="This is rather long.";
	string_copy(short_string,long_string,11);
	cout<<short_string<<" STRING ENDS HERE."<<endl;
}

void string_copy(char target[],const char source[],int target_size)
{
	int new_length=strlen(source);
	if(new_length>(target_size-1))
		new_length=target_size-1;
	int index;
	for(index=0;index<new_length;index++)
		target[index]=source[index];
	target[index]='\0';
}
