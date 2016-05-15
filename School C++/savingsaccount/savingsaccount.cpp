// savingsaccount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream.h>
#include <iomanip.h>

class SavingsAccount
{friend ostream& operator<<(ostream&,const SavingsAccount&);

public:
	SavingsAccount();
	SavingsAccount(int,double,double);
private:
	double acctNum,
		interestRate,
		balance;
};

void main(void)
{
	SavingsAccount a1;
	cout<<a1;
}


SavingsAccount::SavingsAccount()
{
}

ostream& operator<<(ostream& outs,const SavingsAccount& sa)
{
	outs<<"Account#: "<<sa.acctNum<<endl
		<<"Interest Rate: "<<sa.interestRate<<endl
		<<setw(2)
		<<"Balance: "<<sa.balance<<endl;
	return outs;
}