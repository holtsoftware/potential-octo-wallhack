#include "stdafx.h"
#include <ap/apvector.h>
#include <iostream.h>

class time{
	friend ostream &operator<<(ostream &,time &);
public:
	time();
	void settime(int h,int m,int s){hours=h;min=m;sec=s;}
private:
	int hours;
	int min;
	int sec;
};
time::time(){hours=min=sec=0;}


ostream &operator<<(ostream &output,time &ct)
{
	output<<ct.hours<<":"<<ct.min<<":"<<ct.sec;
	return output;
}


int main(int argc, char* argv[])
{
	time the;
	the.settime(3,87,3);
	cout<<the<<endl;
	return 0;
}
