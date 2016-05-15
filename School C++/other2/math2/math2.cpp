#include "stdafx.h"
#include <iostream.h>

//struct NODE{
//	int t;
//	NODE* next;
//};


NODE *copy(NODE *head)
{
	NODE *temp,*ne=head,*re=0;
	while(ne)
	{
		ne=ne->next;
		temp=new NODE;
		temp->next=re;
		re=temp;
	}
	temp=re;
	ne=head;
	while(ne)
	{
		temp->t=ne->t;
		temp=temp->next;
		ne=ne->next;
	}
	return re;
}



void main()
{
}




//struct NODE{
//	SOMETYPE info;
//	NODE* next;
//};

void Rotate(NODE* &head)
{
	NODE *temp=head,*la=head;
	while(temp->next)
	{
		temp=temp->next;
	}
	head=head->next;
	temp->next=la;
	la->next=0;
}

struct POINT{
	double x;
	double y;
};
/*
struct NODE{
	POINT vertex;
	NODE *next;
};*/

void RemoveClosestVertex(const POINT &p,NODE* &polygon)
{
	NODE *toreplace=polygon,*pol=polygon,*last;
	int temp,dist=abs(pow((p.x-toreplace->vertex.x),2)+pow((p.y-toreplace->vertex.y),2));
	while(pol)
	{	
		temp=abs(pow((p.x-pol->vertex.x),2)+pow((p.y-pol->vertex.y),2));
		if(dist<temp)
		{
			toreplace=pol;
			dist=temp;
		}
		pol=pol->next;
	}
	pol=polygon;
	while(pol!=toreplace)
	{
		last=pol;
		pol=pol->next;
	}
	last->next=polygon->next;
	delete polygon;
}

/*enum COLOR{red=1,green,blue=4};
struct RECT{
	double left;
	double right;
	double top;
	double bottom;
	COLOR color;
};

struct NODE{
	RECT rect;
	NODE *next;
};*/

bool IsInRed(const POINT &p,NODE *sketch)
{
	NODE *tempnode=sketch;
	while(tempnode)
	{
		if((tempnode->rect.color==red)&&((p.x>tempnode->rect.top)&&(p.x<tempnode->rect.bottom)
			&&(p.y>tempnode->rect.left)&&(p.y<tempnode->rect.right)))
			return true;
	}
	return false;
}

struct NODE{
	apstring data;
	NODE *next;
};

struct LIST{
	NODE *head;
	NODE *tail;
};

void Append(LIST &list1,LIST &list2)
{
	list1.tail->next=list2.head;
	list2.head->next=list1.tail;
	list1.tail=list2.tail;
}


int Sum(NODE *head)
{
	NODE *temp=head;
	int sum=0;
	while(temp->next!=head)
	{
		sum+=temp->data;
		temp=temp->next;
	}
	return sum;
}