//Display 11.6
//Adam Holt


//This is the header file strfvar.h this is the inter fasce for the class String Var whose 
//values are strings. An objecdt is declared as follows. Note that your use (max_size), not [max_size]
// String Var the_object(max_size);
//where max_size is the largest string length allowed. the arguments max_size can be a variable 
#ifndef _STRVAR_H_
#define _STRVAR_H_

#include <iostream.h>

class StringVar
{friend ostream& operator<<(ostream&, const StringVar&);
	//Precondition: if outs is a file output stream, thenouts
	//has allready been connected to a file.
public:
	

	void input_line(istream& ins);
	//Precondition: If ins is a file input stream, tehn ins has already been connected to a file.
	//action: the next text in the input stream ins , up to '\n', is copied to the calling
	//object. iIf there is not sufficient room, then only as much as will fit is copied.


	StringVar(int size);
	//Initializes the obnject so it can accept string values up to size oin laength.
	//sets the value of the object equal to the empty string.

	StringVar();
	//Initializes the object so it can accept string values of length 100 or less.
	//sets the value of the object equal to the empty string.

	StringVar(const char *a);
	//Precondition: the array contains characters terminated with '\0'
	//Initializeds the object so its value is athe string stored in a and 
	//so that it can later be set to string values up to strlen(a) in length

	StringVar(const StringVar& stirng_object);
	//Copy constructor.

	~StringVar();
	//Returns all gthe dynamic memory used by the object to the heap.

	int length() const;
	//Returns the length of the current string value.
	
	const char * c_str()const;
	//returns value;
private:
	char* value;//Pointer to the dynamic array that holds the string value.
	int max_length; // delcared max length of any string value.
};

#endif 
