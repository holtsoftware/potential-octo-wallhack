// roll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <dice.h>
#include <rand.h>


int main(int argc, char* argv[])
{
	srnd();
	for(int t=0;t<=rnd(8);t++)
	dice(rand()%6+1);
	return 0;
}
