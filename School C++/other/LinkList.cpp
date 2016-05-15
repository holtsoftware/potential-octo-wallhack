/////////////////////////////////////////////////////////////////////
// Programer: Adam Holt
// Last Editer: Adam Holt
// Last Change: 10-1-01
// LinkList.cpp: implementation of the LinkList class.
//////////////////////////////////////////////////////////////////////

#include "LinkList.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
template<class T>
LinkList<T>::LinkList()
//PostCondition: The Link List has a copasity of 0
{
	mylength=0;
	head=NULL;
	tail=NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
LinkList<T>::LinkList(int size)
//PreCondition: size >= 0
//PostCondition: Link List has a copasity to hold (size) items
{
	this<T>::change(size);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
LinkList<T>::LinkList(int size,const T &fillvalue)
//precondition: size>=0, fillvalue contains a value
//PostCondition: lisk list contains size items all initilized to fillvalue
{
	tail=NULL;
	head=NULL;

	int i;
	NODE<T> *newNode;
	newNode=NULL;

	for(i=0;i<size;i++)
	{
		newNode=new NODE<T>;

		if(!newNode)
		{
			cerr<<"Out Of Memory!"<<endl;
			exit(1);
		}
		else
		{
			if(head)
			{
				tail->next=newNode;
				tail=tail->next;
				tail->data=fillvalue;
				tail->next=NULL;
			}
			else
			{
				head=newNode;
				tail=head;
				tail->data=fillvalue;
			}
		}
	}

	if(size>=0)
	{
		mylength=size;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
LinkList<T>::LinkList(LinkList &tcopy)
//PostCondition: LinkList is a copy of tcopy
{
		head=NULL;
	tail=NULL;

	int i;
	NODE<T> *newNode;
	newNode=NULL;

	for(i=0;i<tcopy.length();i++)
	{
		newNode=new NODE<T>;

		if(!newNode)
		{
			cerr<<"Out Of Memory!"<<endl;
			exit(1);
		}
		else
		{
			if(head)
			{
				tail->next=newNode;
				tail=tail->next;
				tail->next=NULL;
				tail->data=tcopy[i];
			}
			else
			{
				head=newNode;
				tail=head;
				head->data=tcopy[i];
			}
		}
	}

	mylength=tcopy.length();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
LinkList<T>::~LinkList()
// PostCondition: LinkList is destroyed
{
	NODE<T> *tempNODE;

	while(head)
	{
		tempNODE=head->next;
		delete head;
		head=tempNODE;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//Member Functions
/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void LinkList<T>::change(int size)
{
	head=NULL;
	tail=NULL;

	int i;
	NODE<T> *newNode;
	newNode=NULL;

	for(i=0;i<size;i++)
	{
		newNode=new NODE<T>;

		if(!newNode)
		{
			cerr<<"Out Of Memory!"<<endl;
			exit(1);
		}
		else
		{
			if(head)
			{
				tail->next=newNode;
				tail=tail->next;
				tail->next=NULL;
			}
			else
			{
				head=newNode;
				head->next=NULL;
				tail=head;
			}
		}
	}

	if(size>=0)
	{
		mylength=size;
	}
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T> 
long int LinkList<T>::calcLength() 
//Description: Loops throw the link list to detrument the length of the link list
//PreCondtion: LinkList contains a link list
//PostCondtion: returns the size of the link list
{
	NODE<T> *tempnode;
	int i=0;

	tempnode=NULL;
	tempnode=head;

	while(tempnode)
	{
		i++;
		tempnode=tempnode->next;
	}

	return i;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
long int LinkList<T>::length() const
//PostCondtion: returns the size of the link list
{
	return mylength;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
T & LinkList<T>::at(int index)
//PreCondition: 0 <= K < length()
//PostCondition: returns the index item
{
	NODE<T> *temp;

	if(index>=0 && index<mylength)
	{
		temp=head;

		for(int i=0;i<index;i++)
		{
			temp=temp->next;
		}
	}
	else
	{
		cerr<<"Index Out Of Bounds!"<<endl;
		exit(1);
	}

	return temp->data;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
const T & LinkList<T>::atc(int index) const
//PreCondition: 0 <= K < length()
//PostCondition: returns the index item
{
	NODE<T> *temp;

	if(index>=0 && index<mylength)
	{
		temp=head;

		for(int i=0;i<index;i++)
		{
			temp=temp->next;
		}
	}
	else
	{
		cerr<<"Index Out Of Bounds!"<<endl;
		exit(1);
	}

	return temp->data;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T & LinkList<T>::operator [](int index)
//See atc() or at()
{
	return at(index);
}

////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void LinkList<T>::resize(int newsize)
// description: resizes the linklist to newsize elements
// precondition: the current capacity of vector is lenght(); newsize>=0
// PostCondition: the size of the linklist is newsize
{
	if(newsize>mylength)
	{
		NODE<T> *temp;
		temp=NULL;

		if(tail==NULL)
		{
			change(newsize);
			return;
		}
		for(int i=mylength;i<newsize;i++)
		{
			temp=new NODE<T>;
			
			if(!temp)
			{
				cerr<<"Out of Memory!"<<endl;
				exit(1);
			}
			else
			{
				tail->next=temp;
				tail=tail->next;
				tail->next=NULL;
			}
		}
		mylength=newsize;
	}
	else if(newsize<mylength && newsize>=0)
	{
		NODE<T> *temp,*temp2;
		temp=head;

		for(int i=0;i<newsize-1;i++)
		{
			temp=temp->next;
		}
		tail=temp;
		tail->next=NULL;

		temp=temp->next;

		while(temp)
		{
			temp2=temp->next;
			delete temp;
			temp=temp2;
		}
		mylength=newsize;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
const LinkList<T> & LinkList<T>::operator =(const LinkList<T> &rhs)
//PreCondition: rhs != this
//PostCondition: rhs is copyed into this
{
	if(this!=&rhs)
	{
		resize(rhs.length());
		for(int i=0;i<rhs.length();i++)
		{
			at(i)=rhs.atc(i);
		}
	}
	return *this;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void LinkList<T>::addinat(int index)
{
	addinat(index,NULL);
}
//////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void LinkList<T>::addinat(int index,const T &toadd)
{
	if(index<mylength)
	{
		NODE<T> *temp,*newnode,*lastnode;
		newnode=new NODE<T>;
		temp=NULL;

		if(!newnode)
		{
			cerr<<"Out of Memory!"<<endl;
			exit(1);
		}
		else
		{
			newnode->next=NULL;
			lastnode=head;
			temp=head;
			for(int i=0;i<index;i++)
			{
				lastnode=temp;
				temp=temp->next;
			}
			if(temp==tail && temp==head)
			{
				head=newnode;
				newnode->next=temp;
				newnode->data=toadd;
			}
			else if(temp==tail)
			{
				newnode->next=tail;
				lastnode->next=newnode;
				newnode->data=toadd;
			}
			else if(temp==head)
			{
				newnode->next=temp;
				head=newnode;
				newnode->data=toadd;
			}
			else
			{
				lastnode->next=newnode;
				newnode->next=temp;
				newnode->data=toadd;
			}
			mylength++;
		}
	}
	else if(mylength==0 && index == 0)
	{
		NODE<T> *newnode;
		newnode=new NODE<T>;

		if(!newnode)
		{
			cerr<<"Out of Memory!"<<endl;
			exit(1);
		}
		newnode->next=NULL;
		head=newnode;
		tail=newnode;
		newnode->data=toadd;
		mylength++;
	}
	else if(mylength==index && mylength>0)
	{
		NODE<T> *newnode;
		newnode=new NODE<T>;
		if(!newnode)
		{
			cerr<<"Out of Memory!"<<endl;
			exit(1);
		}
		tail->next=newnode;
		newnode->next=NULL;
		tail=newnode;
		newnode->data=toadd;
		mylength++;
	}
	else
	{
		cerr<<"Index out of bounds in addinit."<<endl;
		exit(1);
	}

}

template<class T>
T LinkList<T>::delat(int index)
{
	T  to_return;
	if(index>=0 && index<mylength)
	{
		NODE<T> *temp=head,*lastnode;

		if(index==0 && head==tail)
		{
			head=NULL;
			tail=NULL;
			to_return=temp->data;
			delete temp;
		}
		else if(index==0)
		{
			head=head->next;
			to_return=temp->data;
			delete temp;
		}
		else if(index==(mylength-1))
		{
			for(int i=0;i<(mylength-1);i++)
			{
				lastnode=temp;
				temp=temp->next;
			}
			lastnode->next=NULL;
			tail=lastnode;
			to_return=temp->data;
			delete temp;
		}
		else
		{
			for(int i=0;i<index;i++)
			{
				lastnode=temp;
				temp=temp->next;
			}
			lastnode->next=temp->next;
			to_return=temp->data;
			delete temp;
		}
		mylength--;
	}
	return to_return;
}