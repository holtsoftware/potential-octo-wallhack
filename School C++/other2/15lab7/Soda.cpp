// Soda.h: interface for the Soda class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SODA_H__EBF28046_E54F_11D3_A41E_00001C3A6B56__INCLUDED_)
#define AFX_SODA_H__EBF28046_E54F_11D3_A41E_00001C3A6B56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

static const int brands=5;
static const char *brandname[brands]={"PepC++","Spload","Star","Genaral","S598"};
class Soda  
{
public:
	Soda();
	void addmoney(int cents);
	void returnmoney();
	void dispensedrink();
	virtual ~Soda();
private:
	int drinkprice;
	int numdrinks[brands];
	double totalmoney;
	int lastdiposit;
};

#endif // !defined(AFX_SODA_H__EBF28046_E54F_11D3_A41E_00001C3A6B56__INCLUDED_)
