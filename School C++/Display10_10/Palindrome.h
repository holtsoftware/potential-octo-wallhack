//Test for Palindrom property.

#include <iostream.h>
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
