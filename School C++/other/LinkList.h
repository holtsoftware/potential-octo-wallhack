/////////////////////////////////////////////////////////////////////////////////////////////////
// Last Edited: 6-6-2001
// Inital Programer: Adam Holt
// Last Editer: Adam Holt
//
// 10-6-01: fixed a problem with resize of a LinkList that was initulized by LinkList()
//
// Class Link List is a link list that can be used as an array
//
//////////////////////////////////////////////////////////////////////

#ifndef LINKLIST_H
#define LINKLIST_H


template<class T>
struct NODE{
	T data;
	NODE *next;
};


template<class T>
class LinkList  
{
public:
	//constructers/destructer
	LinkList();//Defalt constructor Initilizes the link list to NULL
	LinkList(int);//Initial size of the linklist
	LinkList(int,const T &);
	LinkList(LinkList &);//Copy Constructer
	virtual ~LinkList();//Destructor

	//Assignment
	const LinkList & operator =(const LinkList &);
	//Accessores
	long int calcLength();//Calculates the size of the link list by looping throw the link list
	long int length() const;//Returns the langth of the of the link list stored in (mylength)

	//Indexing
	T &	operator[](int); 
	const T & operator[](int) const;
	T & at(int);
	const T & atc(int) const;

	//modifiers
	void resize(int); //changes the size dynamicly
	void addinat(int);//adds a node in at the (int) value between 0 and length()-1
	void addinat(int,const T &);//same as above but puts a value in the data
	T delat(int);//delets the node at the (int) place and returns the data

private:
	void change(int);//used to fix a problem with the resize of a linklist that was initulized by LinkList()
	NODE<T> *head;
	NODE<T> *tail;
	long int mylength;
};

#include "LinkList.cpp"

#endif // LINKLIST_H