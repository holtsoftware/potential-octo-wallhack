// Ele.h: interface for the Ele class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELE_H__7A972528_E570_11D3_928D_DCB583C21533__INCLUDED_)
#define AFX_ELE_H__7A972528_E570_11D3_928D_DCB583C21533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum doorpasition{Close,Open};

class Ele  
{
public:
	Ele();
	Ele(const int);
	Ele(const int,const int);
	void opendoor();
	void closedoor();
	int getcurfloor();
	void gotofloor(const int =0);
	virtual ~Ele();
private:
	doorpasition door;
	int numfloors;	
	int curfloor;
};

#endif // !defined(AFX_ELE_H__7A972528_E570_11D3_928D_DCB583C21533__INCLUDED_)
