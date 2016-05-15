//////////////////////////////////////////////////////////////////////////////////////////////////
//Program that asks the user for his/her hand and tell them what they have in it
//Programer Adam Holt
//last edited date 8-13-01
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream.h>
#include <ctype.h>
//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////Categories that a hand can fall into///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
#define straightflush 1
#define fourofakind 2
#define fullhouse 3
#define flush 4
#define straight 5
#define threeofakind 6
#define twopairs 7
#define onepair 8
#define nothing 0
//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////End Categories///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

struct card
{
	int face;
	char suite;
};

void get_users_cards(card *);
int test_cards(card *);
void display_type(int);

void main()
{
	card *usercards;
	int returned;
	char con='Y';
	while (con=='Y')
	{
		usercards=new card [5];
		get_users_cards(usercards);
		returned=test_cards(usercards);
		display_type(returned);
		delete [] usercards;
		cout<<"Do you want to test another hand?(Y,N)"<<endl;
		cin>>con;
		con=toupper(con);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void get_users_cards(card *usercards)
{
	int face;
	char sute;
	bool iscorrect;

	for(int i=0;i<5;i++)
	{
		iscorrect=false;
		while(! iscorrect)
		{
			cout<<"Please enter #"<<i+1<<" card face and suit. I.E.(7 C)";
			cin>>face>>sute;
			sute=toupper(sute);
			if((face>=2 && face<=13) &&((sute=='C' ||sute=='D') || (sute=='H' || sute=='S')))
			{
				iscorrect=true;
			}
			for(int t=0;t<i;t++)
			{
				if((usercards[t].face==face) && (usercards[t].suite==sute))
				{
					iscorrect=false;
				}
			}
		}
		usercards[i].face=face;
		usercards[i].suite=sute;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void sortcards(card *usercards)
//sortes the cards face from lowest to highest so it is easyer to test the hand
{
	for(int i=0;i<5;i++)
	{
		int last_min=usercards[i].face;
		for(int t=i;t<5;t++)
		{
			if(usercards[t].face<last_min)
			{
				last_min=usercards[t].face;
				card temp_card;
				temp_card=usercards[i];
				usercards[i]=usercards[t];
				usercards[t]=temp_card;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////Card Test Functions////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

bool straght_flush(const card *usercards)
{
	for(int i=0;i<4;i++)
	{
		if(usercards[i].suite!=usercards[i+1].suite)
		{
			return false;
		}
	}
	int last=usercards[0].face;
	for(int t=1;t<5;t++)
	{
		if(!(usercards[t].face==(last+1)))
		{
			return false;
		}
		last=usercards[t].face;
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
bool four_of_a_kind(const card *usercards)
{
	return (((usercards[0].face==usercards[1].face )&&(usercards[1].face==usercards[2].face)&&(usercards[2].face==usercards[3].face))
		||((usercards[1].face==usercards[2].face)&&(usercards[2].face==usercards[3].face )&&(usercards[3].face ==usercards[4].face)));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
bool full_house(const card *usercards)
{
	return (((usercards[0].face==usercards[1].face)&&
		(usercards[2].face==usercards[3].face)&&(usercards[3].face==usercards[4].face))||
		((usercards[0].face==usercards[1].face)&&(usercards[1].face==usercards[2].face)&&
		(usercards[3].face==usercards[4].face)));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
bool f_flush(const card *usercards)
{
	for(int i=0;i<4;i++)
	{
		if(usercards[i].suite!=usercards[i+1].suite)
			return false;
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
bool f_straight(const card *usercards)
{
	int last=usercards[0].face;
	for(int t=1;t<5;t++)
	{
		if(!(usercards[t].face==(last+1)))
		{
			return false;
		}
		last=usercards[t].face;
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
bool three_of_a_kind(const card *usercards)
{
	return (((usercards[0].face==usercards[1].face)&&(usercards[1].face==usercards[2].face))||
		((usercards[2].face==usercards[3].face)&&(usercards[3].face==usercards[4].face)));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
bool two_pairs(const card *usercards)
{
	return (((usercards[0].face==usercards[1].face)&&(usercards[2].face==usercards[3].face))||
		((usercards[1].face==usercards[2].face)&&(usercards[3].face==usercards[4].face))||
		((usercards[0].face==usercards[1].face)&&(usercards[3].face==usercards[4].face)));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
bool one_pair(const card *usercards)
{
	return ((usercards[0].face==usercards[1].face)||
		(usercards[1].face==usercards[2].face)||
		(usercards[2].face==usercards[3].face)||
		(usercards[3].face==usercards[4].face));
}
//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////End Card Test Functions////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
int test_cards(card * usercards)
{
	sortcards(usercards);
	int toreturn;
	if(straght_flush(usercards))
		toreturn=straightflush;
	else if(four_of_a_kind(usercards))
		toreturn=fourofakind;
	else if(full_house(usercards))
		toreturn=fullhouse;
	else if(f_flush(usercards))
		toreturn=flush;
	else if(f_straight(usercards))
		toreturn=straight;
	else if(three_of_a_kind(usercards))
		toreturn=threeofakind;
	else if(two_pairs(usercards))
		toreturn=twopairs;
	else if(one_pair(usercards))
		toreturn=onepair;
	else
		toreturn=nothing;
	return toreturn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void display_type(int hand)
{
	switch (hand)
	{
	case nothing:
		cout<<"You have nothing in the hand. Sarry!"<<endl;
		break;
	case onepair:
		cout<<"You have a Pair in your hand."<<endl;
		break;
	case twopairs:
		cout<<"You have Two Pairs in your hand."<<endl;
		break;
	case threeofakind:
		cout<<"You have Three Of A Kind in your hand."<<endl;
		break;
	case straight:
		cout<<"You have a Straight in your hand."<<endl;
		break;
	case flush:
		cout<<"You have a Flush in your hand."<<endl;
		break;
	case fullhouse:
		cout<<"You have a Full House in your hand."<<endl;
		break;
	case fourofakind:
		cout<<"You have Four Of A Kind in your hand."<<endl;
		break;
	case straightflush:
		cout<<"You have a Straight Flush in your hand."<<endl;
		break;
	default:
		cout<<"An Error has accoured!"<<endl;
		break;
	};
}