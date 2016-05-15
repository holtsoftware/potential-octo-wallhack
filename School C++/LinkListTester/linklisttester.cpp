#include <lvector.h>
#include <stdlib.h>
#include <iostream.h>

void main()
{
//	char non;
	int i;
	lvector<double> testlist(2);
	testlist[0]=1;
	testlist[1]=2;
	cout<<"The lenght before resizeing "<<testlist.length()<<endl;
	testlist.resize(5);
	cout<<"The length of mylenght is "<<testlist.length()<<endl
		<<"Calculated length is "<<testlist.calcLength()<<endl;
	testlist[2]=3;
	testlist[3]=4;
	testlist[4]=5;

	cout<<"The values of test list are ";
	for(i=0;i<testlist.length();i++)
	{
		cout<<testlist[i]<<" ";
	}
	testlist.resize(3);
		cout<<endl<<"The length of mylenght is "<<testlist.length()<<endl
		<<"Calculated length is "<<testlist.calcLength()<<endl;
		cout<<"The values of test list are ";

	for(i=0;i<testlist.length();i++)
	{
		cout<<testlist[i]<<" ";
	}
	cout<<endl;

	lvector<double> testlist2=testlist;

	cout<<"After the use of the copy constructor the new link list has:"<<endl;
	for(i=0;i<testlist2.length();i++)
	{
		cout<<testlist2[i]<<" ";
	}
	cout<<endl<<"The Calculated lenght is: "<<testlist2.calcLength();
	testlist2.resize(32);
	cout<<endl<<endl<<"After resizeing testlist2 to 32 the lenght is: "<<testlist2.length()<<endl
		<<"The Calculated length is: "<<testlist2.calcLength()<<endl<<endl;
	testlist2=testlist;
	cout<<"After seting testlist2 to testlist the lenght of testlist2 is: "<<testlist2.length()
		<<endl<<"The Calculated lenght is: "<<testlist2.calcLength()<<endl
		<<"And the elements of testlist2 are: ";

	for(i=0;i<testlist2.length();i++)
	{
		cout<<testlist2[i]<<" ";
	}
	cout<<endl;

	lvector<double> Testlist(5,6.995);
	cout<<"After creating Testlist the length is: "<<Testlist.length()<<endl
		<<"The Calculated length is: "<<Testlist.calcLength()<<endl
		<<"The Elements of Testlist are: "; 
	for(i=0;i<Testlist.length();i++)
	{
		cout<<Testlist[i]<<" ";
	}
	cout<<endl;
	//cin>>non;
}

