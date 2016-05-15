//Adam Holt
//Display 9.11
#include <iostream.h>
const int DECLARED_SIZE=20;

void fill_array(int a[],int size,int& number_used);

int search(const int a[],int number_used,int target);

void main()
{
	int arr[DECLARED_SIZE],list_size,target;
	fill_array(arr,DECLARED_SIZE,list_size);

	char ans;
	int result;
	do
	{
		cout<<"Enter at number to search for: ";
		cin>>target;
		
		result=search(arr,list_size,target);
		if(result==-1)
			cout<<target<<" is not on the list."<<endl;
		else
			cout<<target<<" is stored in array position "<<result<<endl
			<<"(Remember: The first position is 0.)"<<endl;
		cout<<"Search agein?(y/n followed by return): ";
		cin>>ans;
	}while((ans!='n')&&(ans!='N'));
	cout<<"End of program."<<endl;
}

void fill_array(int a[],int size,int& number_used)
{
	cout<<"Enter up to "<<size <<" nonnegitve whole numbers"<<endl
		<<"Mark the end of the list with a negative number."<<endl;

	int next, index=0;
	cin>>next;
	while((next>=0)&&(index<size))
	{
		a[index]=next;
		index++;
		cin>>next;
	}
	number_used=index;
}

int search(const int a[],int number_used,int target)
{
	int index=0;
	bool found=false;
	while((!found)&&(index<number_used))
	if(target==a[index])
		found=true;
	else
		index++;

	if(found)
		return index;
	else
		return -1;
}