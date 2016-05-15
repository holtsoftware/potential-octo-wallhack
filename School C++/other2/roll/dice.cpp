#include <iostream.h>

void dis1()
//dis1 is used with dis2 and dis3 and dis4 and dis5 and dis6 to generate a dise
{
	cout<<" -----"<<endl;
}
//--------------------------------------------------------------------
void dis2()
{
	cout<<"|*   *|"<<endl;
}
//--------------------------------------------------------------------
void dis3()
{
	cout<<"|*    |"<<endl;
}
//--------------------------------------------------------------------
void dis4()
{
	cout<<"|    *|"<<endl;
}
//--------------------------------------------------------------------
void dis5()
{
	cout<<"|     |"<<endl;
}
//--------------------------------------------------------------------
void dis6()
{
	cout<<"|  *  |"<<endl;
}

//--------------------------------------------------------------------
void dice(int ots)
{
	if(ots>=1&&ots<=6)//deturmans if onetosix is a valid dise size
	{
		dis1();// -----
		switch (ots)
		{
		case 1:
			       // -----
			dis5();//|     |
			dis6();//|  *  |
			dis5();//|     |
			       // -----
			break;
		case 2:
			       // -----
			dis3();//|*    |
			dis5();//|     |
			dis4();//|    *|
				   // -----
			break;
		case 3:
				   // -----
			dis3();//|*    |
			dis6();//|  *  |
			dis4();//|    *|
			       // -----
			break;
		case 4:
				   // -----
			dis2();//|*   *|
			dis5();//|     |
			dis2();//|*   *|
			       // -----
			break;
		case 5:
				   // -----
			dis2();//|*   *|
			dis6();//|  *  |
			dis2();//|*   *|
			       // -----
			break;
		case 6:
			       // -----
			dis2();//|*   *|
			dis2();//|*   *|
			dis2();//|*   *|
			       // -----
			break;
		default:
			dis1();// -----
		}
		dis1();
		cout<<endl;

	}
	else
		cout<<"Not a valid side"<<endl;
}

