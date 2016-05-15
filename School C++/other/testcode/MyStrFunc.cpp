#include <string>
using namespace std;

string replace(string temp,const char *find,const char *trepl)
{
	int found=0;
	for(int i=0;i<temp.length();i++)
	{
		if(temp[i]==find[0])
		{
			for(int t=i;(t-i)<strlen(find);t++)
			{
				found=1;
				if(temp[t]!=find[t-i])
				{
					found=0;
					break;
				}
			}
			if(found)
			{
				temp=temp.replace(i,strlen(find),trepl);
				i=i+strlen(trepl);
			}
		}
	}
	return temp;
}