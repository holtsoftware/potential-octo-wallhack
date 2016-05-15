//sorts a list of numbers entered at the keyboard.
//Adam Holt
//Display 11.33

#include <iostream.h>
#include <stdlib.h>
#include <stddef.h>

void fill_array(int *a,int size);

void sort(int *a,int size);

void main()
{
	cout<<"This program shorts numbers from lowest to highest."<<endl;

	int array_size;
	cout<<"How many numbers will be sorted?";
	cin>>array_size;

	int * a;

	a=new int[array_size];
	if(a==NULL)
	{
		cout<<"Error: Insufficient memory."<<endl;
		exit(1);
	}

	fill_array(a, array_size);
	sort(a,array_size);

	cout<<"In sorted order the numbers are:"<<endl;
	for(int index=0;index<array_size;index++)
		cout<<a[index]<<" ";
	cout<<endl;

	delete [] a;
}

void fill_array(int *a,int size)
{
	cout<<"Enter "<<size<<" integers."<<endl;
	for(int i=0;i<size;i++)
		cin>>a[i];
}
int index_of_smallest(const int *a,int start_index, int size)
{
	int min=a[start_index],index_of_min=start_index;
	for(int i=start_index+1;i<size;i++)
		if(a[i]<min)
		{
			min=a[i];
			index_of_min=i;
		}
	return index_of_min;
}

void swap_values(int &v1,int &v2)
{
	int temp;
	temp=v1;
	v1=v2;
	v2=temp;
}

void sort(int *a,int size)
{
	int index;
	for(int i=0;i<size-1;i++)
	{
		index=index_of_smallest(a, i,size);
		swap_values(a[i],a[index]);
	}
}
