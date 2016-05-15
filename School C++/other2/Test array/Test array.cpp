// Test array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>




void main(int argc, char* argv[])
{
	char account[16]={'5','4','5','8','0','9','8','3','9','3','3','8','3','9','7','6'},chari;
	int u=0;
	switch(account[0]){
	case '4':
		chari='V';
		break;
	case '5':
		chari='M';
		break;
	case '3':
		if(account[1]=='7')
			chari='A';
		else
			chari='X';
		break;
	case '6':
		if(account[1]=='0')
		{
			for(int y=2;y<=3;y++)
				if(account[y]=='1')
					u++;
			if(u==2)
				chari='D';
			else
				chari='X';
		}
		else
			chari='X';
		break;
	default:
		{
		chari='X';
		break;
		}
}
	cout<<account[0]<<" "<<chari<<endl;
}
