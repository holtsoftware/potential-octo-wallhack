// day 8.h : main header file for the DAY 8 application
//

#if !defined(AFX_DAY8_H__7DEC58B2_D03D_11D3_928D_D67E4621598D__INCLUDED_)
#define AFX_DAY8_H__7DEC58B2_D03D_11D3_928D_D67E4621598D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay8App:
// See day 8.cpp for the implementation of this class
//

class CDay8App : public CWinApp
{
public:
	CDay8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDay8App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY8_H__7DEC58B2_D03D_11D3_928D_D67E4621598D__INCLUDED_)
