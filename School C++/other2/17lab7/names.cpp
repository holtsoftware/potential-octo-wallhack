// names.h: interface for the names class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _NAMES_H_
#define _NAMES_H_

#include <ap/apstring.h>

struct NODE{
	apstring name;
	NODE *next;
};

class names
{
public:
	names(const char *);
	names();
	~names();
	void display() const;
	void display(ostream &)const;
	bool insert(const apstring &);
	bool insertinorder(const apstring &);
	bool remove(const apstring &);
	void save();
private:
	NODE *head;
	const char *filename;

};

#include  "names.cpp"

#endif