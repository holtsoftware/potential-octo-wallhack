#ifndef _LMATRIX_H_
#define _LMATRIX_H_

#include <lvector.h>

template<class T>
class lmatrix
{
public:
	//constructors/destructor
	lmatrix();					//default size 0X0
	lmatrix(int,int);			//size rows x cols
	lmatrix(int,int,const T &);	//all entries == fill value
	lmatrix(const lmatrix<T> &);//copy constructor
	~lmatrix();//destructor

	//assignment
	const lmatrix<T> & operator=(const lmatrix &);

	//accessors
	int numrows() const;	//number of rows
	int numcols() const;	//number of colums

	//indexing
	const lvector<T> & operator[](int k) const;	//range-checked indexing
	lvector<T> & operator[](int K);				//range-checked indexing

	//modifiers
	void resize(int,int);	//resizes matrix to int x int
	
private:
	
	int myrows;						//# of rows(capacity)
	int mycols;						//# of cols(capacity)
	lvector<lvector<T>> mymatrix;	//the matrix of items
}

#include "lmatrix.cpp"

#endif