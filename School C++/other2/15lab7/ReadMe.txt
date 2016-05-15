// Soda.cpp: implementation of the Soda class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Soda.h"
#include <iostream.h>

const int drinkp=50;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Soda::Soda()
{
	drinkprice=50;
	lastdiposit=0;
	for(int i=0;i<brands;i++)
	{
		numdrinks[i]=6;
	}
	totalmoney=0.;
}
void Soda::addmoney(int cents)
{
	cout<<"You have dipasited "<<cents<<char(162)<<endl;//¢=162
	if(cents<drinkprice)
	{
		cout<<"You did not give anof money"<<endl;
		cout<<cents<<char(162)<<" has been returned"<<endl;
	}
	else
	{
		lastdiposit=50;
		totalmoney+=50;
		cout<<cents-50<<"¢ has been returned"<<endl;
	}
}
void dd()
{
}
void Soda::dispensedrink()
{
	int bra;
	bool valid=false;
	if(lastdiposit<drinkprice)
		valid=true;
	while(!valid)
	{
	cout<<"Enter the value of the brand ==> "<<endl;
	for(int i=0;i<brands;i++)
	{
		cout<<i+1<<" "<<brandname[i]<<endl;
	}
	cin>>bra;
	switch(bra){
	case 1:
		if(numdrinks[0]<=0)
		{
			cout<<"That brand is not in stock"<<endl;
		}
		else
		{
			if(lastdiposit>=drinkprice)
			{
			dd();
			valid=true;
			numdrinks[0]--;
			}
			else
				cout<<"not enof money"<<endl;
			
		}
		break;
	case 2:
		if(numdrinks[1]<=0)
		{
			cout<<"That brand is not in stock"<<endl;
		}
		else{
			if(lastdiposit>=drinkprice)
			{
			dd();
			valid=true;
			numdrinks[1]--;
			}
			else
				cout<<"not enof money"<<endl;
		}
		break;
	case 3:
		if(numdrinks[2]<=0)
		{
			cout<<"That brand is not in stock"<<endl;
		}
		else
		{
			if(lastdiposit>=drinkprice)
			{
			dd();
			valid=true;
			numdrinks[2]--;
			}
			else
				cout<<"not enof money"<<endl;
		}
		break;
	case 4:
		if(numdrinks[3]<=0)
		{
			cout<<"That brand is not in stock"<<endl;
		}
		else
		{
			if(lastdiposit>=drinkprice)
			{
			dd();
			valid=true;
			numdrinks[3]--;
			}
			else
				cout<<"not enof money"<<endl;
		}
		break;
	case 5:
		if(numdrinks[4]<=0)
		{
			cout<<"That brand is not in stock"<<endl;
		}
		else
		{	if(lastdiposit>=drinkprice)
		{
			dd();
			valid=true;
			numdrinks[4]--;
		}
		else
				cout<<"not enof money"<<endl;
		}
		break;
	default:
		cout<<"That is not a valide choice"<<endl;
	}
	}
	if(lastdiposit>=drinkprice)
		lastdiposit=0;
}
void Soda::returnmoney()
{
	cout<<lastdiposit<<"has been returned to you";
	totalmoney-=lastdiposit;
	lastdiposit=0;
}

Soda::~Soda()
{
	cout.precision(2);
	cout<<"The total money collected in the machean was $"<<double(totalmoney)/100<<"."<<endl;
}
