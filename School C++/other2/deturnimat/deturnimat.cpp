// deturnimat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <ap/apmatrix.h>



int main(int argc, char* argv[])
{
	int k,t;
	apmatrix<int> r(3,3,0);
	for(k=0;k<3;k++)
	{
		for(t=0;t<3;t++)
		{
			cout<<"Enter "<<k+1<<","<<t+1<<" ==> ";
			cin>>r[k][t];
		}
	}

	int det=(r[0][0]*r[1][1]*r[2][2])+(r[0][1]*r[1][2]*r[2][0])+(r[0][2]*r[1][0]*r[2][1])
		-(r[2][0]*r[1][1]*r[0][2])-(r[2][1]*r[1][2]*r[0][0])-(r[2][2]*r[1][0]*r[0][1]);
	cout<<det<<endl;
	return 0;
}
