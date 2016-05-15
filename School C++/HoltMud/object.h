#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <LinkList.h>
#include <string>
using namespace std;

#define UNDEFINED "UNDEFINED"

struct info
{
	apstring item;
	apstring data;
};

class object
{
public:
	object();
	~object();

	void create();
	void set(const apstring &,const apstring &);
	apstring query(const apstring &);
private:
	object *item;
	LinkList<info> data;
};

#endif