//Test for Palindrom property.
//Display 10.10
//Adam Holt

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

void swqp(char& lhs,char &rhs);
//swaps char args corresponding to parameters lhs and rhs

string reverse(const string& str);
//retuns a copy of arg corresponding to parameter
//str with characters in revers order.

string removePunct(const string& src, const string &punct);
//returns copy of string src with characters
//in string punct removed

string makeLower(const string& s);
//returns a copy of parametersthat has all upper case
//characters forced to lower case, other charactrs unchanged.
//Users <string>, which provides tolower

bool isPal(const string& this_string);
//uses makeLower, removePunct.
//if this_string is a palindrom,
//	returns true;
//else
//	returns false;

int main()
{
	string str;
	cout<<"Enter a candidate for palindrom test "<<endl
		<<"Followed bny pressing return."<<endl;
	getline(cin,str);
	if(isPal(str))
		cout<<"\""<<str+"\"is a palindrome ";
	else
		cout<<"\""<<str+"\"is not a palindrome ";
	cout<<endl;
	return 0;
}

void swap(char & lhs, char& rhs)
{
	char temp=lhs;
	lhs=rhs;
	rhs=temp;
}

string reverse(const string& str)
{
	int start=0;
	int end=str.length();
	string temp=str;

	while(start<end)
	{
		end--;
		swap(temp[start], temp[end]);
		start++;
	}
	return temp;
}

string makeLower(const string& s)
{
	string temp(s);//This crates a working copy of s
	for(int i=0;i<s.length();i++)
		temp[i]=tolower(s[i]);
	return temp;
}

//returns a copy of src with characters in punct removed
string removePunct(const string& src,const string & punct)
{
	string no_punct;
	int src_len=src.length();
	int punct_len=punct.length();
	for(int i=0;i<src_len;i++)
	{
		string aChar = src.substr(i,1);
		int location=punct.find(aChar,0);
		//find location of successive characters
		//of src in punct

		if(location < 0 || location>= punct_len)
			no_punct=no_punct+aChar; //aChar not in punct -- keep it
	}
	return no_punct;
}

//uses functon makeLower, removePunct.
//returned value:
//if this_string is a palindrom,
//	returns true;
//else
//	returns false;
bool isPal(const string& this_string)
{
	string punctuation(",;:.?!'\" ");//includes a blank
	string str=this_string;
	str=makeLower(str);
	string lowerStr = removePunct(str,punctuation);
	return lowerStr == reverse(lowerStr);
}
