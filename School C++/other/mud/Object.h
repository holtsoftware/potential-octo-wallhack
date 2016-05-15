#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <LinkList.h>
#include <string>
using namespace std;

#define UNDEFINED "UNDEFINED"
#ifndef _info_
#define _info_
struct info
{
	string index;
	string data;
};
#endif

class object
{
public:
	object();
	~object();

	void set(const string &,const string&);
	string query(const string &);
	string displayexits();
	string displaylocs();
private:
	string firstpart(string &,char);
	LinkList<info> ob;
	LinkList<info> exits;
};

#endif