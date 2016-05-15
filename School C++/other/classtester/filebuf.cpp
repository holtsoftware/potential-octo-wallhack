#include "filebuf.h"

filebuf::filebuf()
{
	size=0;
	filename="";
}

filebuf::filebuf(const char *fn)
{
	strcpy(filename,fn);
	open(fn);
}