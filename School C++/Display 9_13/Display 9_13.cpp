//Test the procedure sort.
//Adam Holt
//Display 9.13
#include <iostream.h>

void fill_array(int a[], int size,int &number_used);

void sort(int a[],int number_used);

void swap_values(int& v1,int& v2);

int index_of_smallest(const int a[],int start_index, int number_used);

void main()
{
	cout<<"This program sorts numbers form lowest to highest."<<endl;

	int sample_array[10],number_used;

	fill_array(sample_array,10, number_used);
	sort(sample_array, number_used);

	cout<<"In sorted order the number are:"<<endl;
	for(int index=0;index<number_used; index++)
		cout<<sample_array[index]<<" ";
	cout<<endl;
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

void sort(int a[],int number_used)
{
	int index_of_next_smallest;
	for(int index=0;index<number_used -1;index++)
	{
		index_of_next_smallest=index_of_smallest(a,index,number_used);
		swap_values(a[index],a[index_of_next_smallest]);
	}
}

void swap_values(int& v1,int& v2)
{
	int temp;
	temp=v1;
	v1=v2;
	v2=temp;
}

int index_of_smallest(const int a[], int start_index,int number_used)
{
	int min=a[start_index],index_of_min=start_index;
	for(int index=start_index+1;index<number_used;index++)
		if(a[index]<min)
		{
			min=a[index];
			index_of_min=index;
		}
		
	return index_of_min;
}
