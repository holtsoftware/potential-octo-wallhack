#include "object.h"


object::object()
{
	create();
}

object::~object()
{
}

void object::create()
{
}

void object::set(const apstring &index,const apstring &tdate)
{
	if(query(index)==UNDEFINED)
	{
		data.resize(data.length()+1);
		data[data.length()-1].item=index;
		data[data.length()-1].data=tdata;
	}
	else
	{
		for(int i=0;i<data.length();i++)
		{
			if(data[i].item==index)
			{
				data[i].data=tdate;
				return;
			}
		}
	}
}

apstring object::query(const apstring &index)
{
	apstring to_return;
	for(int i=0;i<data.length();i++)
	{
		if(data[i].item==index)
			return data[i].data;
	}
	return UNDEFINED;
}