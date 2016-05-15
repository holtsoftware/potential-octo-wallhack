// magic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
#include <ap/apvector.h>
#include <ap/apstring.h>
#include <stdlib.h>
#include <time.h>
#include <ap/apmatrix.h>
//#include <conio.h>

enum type{land,creature};
enum fly{flying,notflying};
const int numofcards=26;

void filldeck(apvector<apstring> &deck,
			  apvector<type> &value,
			  apvector<int> &ast,
			  apvector<int> &life,
			  apmatrix<int> &castcostl,
			  apvector<int> &castcostcl,
			  apvector<fly> &flys,
			  apvector<int> &number);
void firstdrow(apvector<int> &hand,apvector<int> &num,apvector<type> &cty);
void drawht(apvector<int> &yhand,apvector<int> &ytabel,const apvector<apstring> &ydeck);
void carddown(apvector<int> &hand,int cr,apvector<int> &tabl);
int putd(apvector<int> &yhand,apvector<int> &tabel);
void putdown(apvector<int> &hand,apvector<int> &tabe,const apvector<apstring> &deck);
char drawtwo(apvector<int> &hand,apvector<int> &num);


int main(int argc, char* argv[])
{
	srand(time(NULL));
	apvector<apstring> yourdeck(numofcards,"0");
	apvector<type> cvalue(numofcards,land);
	apvector<int> cast(numofcards,0);
	apvector<int> clife(numofcards,0);
	apmatrix<int> castcost(numofcards,2,0);
	apvector<int> castcostco(numofcards,0);
	apvector<fly> fornot(numofcards,notflying);
	apvector<int> num(numofcards,1);
	apvector<int> cnum(numofcards,1);
	apvector<int> yhand(11,-1);
	apvector<int> chand(11,-1);
	apvector<int> table(1,-1);
	filldeck(yourdeck,cvalue,cast,clife,castcost,castcostco,fornot,num);
	cnum=num;
	firstdrow(yhand,num,cvalue);
	firstdrow(chand,cnum,cvalue);
	for(int u=0;u<11;u++)
	{
		cout<<u+1<<","<<yourdeck[yhand[u]];
		if(cvalue[yhand[u]]==land)
			cout<<" land"<<endl;
		else
			cout<<" Creature"<<endl;

	}
	int ypoints=20,cpoints=20,z=0;
	char the;
	while(the!='n'&&ypoints>0&&cpoints>0)
	{
		putdown(yhand,table,yourdeck);
		the=drawtwo(yhand,num);
		if(the!='n')
		{
			cout<<"\nhand\n-------\n";
			for(z=0;z<yhand.length();z++)
			{
				cout<<z+1<<","<<yourdeck[yhand[z]]<<endl;
			}
			cout<<"\nTabel\n-------\n";
			for(int k=0;k<table.length();k++)
			{
				cout<<k+1<<","<<yourdeck[table[k]]<<endl;
			}
		}
		
	}

	return 0;
}


//--------------------------------------------------------------------

void filldeck(apvector<apstring> &deck,
			  apvector<type> &value,
			  apvector<int> &ast,
			  apvector<int> &life,
			  apmatrix<int> &castcostl,
			  apvector<int> &castcostcl,
			  apvector<fly> &flys,
			  apvector<int> &number)
{
	deck[0]="Balloon Peddler";value[0]=creature;ast[0]=2;life[0]=2;castcostl[0][0]=1;castcostcl[0]=2;flys[0]=notflying;//type if a 1 it is a creatcher if it is a 0 land
	deck[1]="Merfolk Raiders";value[1]=creature;ast[1]=2;life[1]=3;castcostl[1][0]=1;castcostcl[1]=1;flys[1]=notflying;
	deck[2]="Remote Isle";value[2]=land;number[2]=2;
	deck[3]="Stern Proctor";value[3]=creature;ast[3]=1;life[3]=2;castcostl[3][0]=2;castcostcl[3]=0;flys[3]=notflying; 
	deck[4]="Sandbar Serpent";value[4]=creature;ast[4]=3;life[4]=4;castcostl[4][0]=1;castcostcl[4]=4;flys[4]=notflying;number[4]=3;
	deck[5]="Cloud Sprite";value[5]=creature;ast[5]=1;life[5]=1;castcostl[5][0]=1;castcostcl[5]=0;flys[5]=flying;
	deck[6]="Plains";value[6]=land;number[6]=3;
	deck[7]="Polluted Mire";value[7]=land;number[7]=2;
	deck[8]="Swamp";value[8]=land;number[8]=9;
	deck[9]="Island";value[9]=land;number[9]=10;
	deck[10]="Drake hatchling";value[10]=creature;ast[10]=1;life[10]=3;castcostl[10][0]=1;castcostcl[10]=2;flys[10]=flying;
	deck[11]="Drifting Meadow";value[11]=land;number[11]=2;
	deck[12]="Sandbar Merfolk";value[12]=creature;ast[12]=1;life[12]=1;castcostl[12][0]=1;castcostcl[12]=0;flys[12]=notflying;
	deck[13]="Bog Smuglers";value[13]=creature;ast[13]=1;life[13]=2;castcostl[13][1]=2;castcostcl[13]=1;flys[13]=notflying;
	deck[14]="Pendrell Drake";value[14]=creature;ast[14]=2;life[14]=3;castcostl[14][0]=1;castcostcl[14]=3;flys[14]=flying;number[14]=3;
	deck[15]="Phyrexian Ghoul";value[15]=creature;ast[15]=2;life[15]=2;castcostl[15][1]=1;castcostcl[15]=2;flys[15]=notflying;
	deck[16]="Pit Imp";value[16]=creature;ast[16]=0;life[16]=1;castcostl[16][1]=1;castcostcl[16]=0;flys[16]=flying;
	deck[17]="Somnophore";value[17]=creature;ast[17]=2;life[17]=2;castcostl[17][0]=2;castcostcl[17]=2;flys[17]=flying;
	deck[18]="Shaper Guildmage";value[18]=creature;ast[18]=1;life[18]=1;castcostl[18][0]=1;castcostcl[18]=0;flys[18]=notflying;
	deck[19]="Wizard Mentor";value[19]=creature;ast[19]=2;life[19]=2;castcostl[19][0]=1;castcostcl[19]=2;flys[19]=notflying;
	deck[20]="Metallic Sliver";value[20]=creature;ast[20]=1;life[20]=1;castcostl[20][0]=0;castcostcl[20]=1;flys[20]=notflying;
	deck[21]="Abyssal horror";value[21]=creature;ast[21]=2;life[21]=2;castcostl[21][1]=2;castcostcl[21]=4;flys[21]=flying;
	deck[22]="Cerulean Wyvern";value[22]=creature;ast[22]=3;life[22]=3;castcostl[22][0]=1;castcostcl[22]=4;flys[22]=flying;
	deck[23]="Igneous Golem";value[23]=creature;ast[23]=3;life[23]=4;castcostl[23][0]=0;castcostcl[23]=5;flys[23]=notflying;
	deck[24]="Deepwood Ghoul";value[24]=creature;ast[24]=2;life[24]=1;castcostl[24][1]=1;castcostcl[24]=2;flys[24]=notflying;
	deck[25]="Skyshroud Vampire";value[25]=creature;ast[25]=3;life[25]=3;castcostl[25][1]=2;castcostcl[25]=3;flys[25]=flying;
}

//--------------------------------------------------------------------

void firstdrow(apvector<int> &hand,apvector<int> &num,apvector<type> &cty)
{
	int ct=0;
	while(ct==0)
	{
		for(int i=0;i<11;i++)
		{
			while(hand[i]==-1)
			{
				int temp=rand()%numofcards;
				if(num[temp]>0)
				{
					hand[i]=temp;
					num[temp]--;
				}
			}
			if(cty[i]==land)
				ct++;
		}
		if(ct==0)
		{
			for(int y=0;y<11;y++)
			{
				num[hand[y]]++;
			}
		}

	}
}
//--------------------------------------------------------------------
char drawtwo(apvector<int> &hand,apvector<int> &num)
{
	char two;
	int leng=hand.length();
	hand.resize(leng+2);
		for(int i=leng;i<hand.length();i++)
		{
			while(hand[i]<=0)
			{
				int temp=rand()%numofcards;
				if(num[temp]>0)
				{
					hand[i]=temp;
					num[temp]--;
				}
			}
		}
		cout<<"Continue again(y or n)==> \n";
		cin>>two;
		return two;
}

//--------------------------------------------------------------------
void putdown(apvector<int> &hand,apvector<int> &tabe,const apvector<apstring> &deck)
{
	int e;
	while(e!=-1)
	{

		e=putd(hand,tabe);
		if(e!=-1)
			drawht(hand,tabe,deck);
	}
}

//--------------------------------------------------------------------
int putd(apvector<int> &yhand,apvector<int> &tabel)
{
	int card;
	cout<<"What card do you want to putdown?"<<endl<<"-1 to quit.";
	cin>>card;
	if(card!=-1)
		carddown(yhand,card,tabel);
	return card;
}

//--------------------------------------------------------------------

void carddown(apvector<int> &hand,int cr,apvector<int> &tabl)
{
	int you=cr-1,len,temp,tmp;
	if(tabl[0]==-1)
		tabl[0]=hand[you];
	else
	{
		len=tabl.length();
		tabl.resize(len+1);
		tabl[len]=hand[you];
	}
		for(int c=0;c<hand.length();c++)
		{
			tmp=hand.length();
			if(c>=you)
			{
				if(c<tmp-1)
				{
					temp=hand[c+1];
					hand[c]=temp;
				}
			}
		}
		len=hand.length();
		hand.resize(len-1);
	
}

//--------------------------------------------------------------------
void drawht(apvector<int> &yhand,apvector<int> &ytabel,const apvector<apstring> &ydeck)
{
	cout<<"\nhand\n-------\n";
	for(int k=0;k<yhand.length();k++)
	{
		cout<<k+1<<","<<ydeck[yhand[k]]<<endl;
	}
	cout<<"\nTabel\n-------\n";
	for(int z=0;z<ytabel.length();z++)
	{
		cout<<z+1<<","<<ydeck[ytabel[z]]<<endl;
	}
}
