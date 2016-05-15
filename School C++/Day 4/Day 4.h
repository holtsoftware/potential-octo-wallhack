// Day 4.h : main header file for the DAY 4 application
//

#if !defined(AFX_DAY4_H__37C8D5E2_7D1D_4410_8DE7_A9C8E9F94CD7__INCLUDED_)
#define AFX_DAY4_H__37C8D5E2_7D1D_4410_8DE7_A9C8E9F94CD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay4App:
// See Day 4.cpp for the implementation of this class
//

class CDay4App : public CWinApp
{
public:
	CDay4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDay4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY4_H__37C8D5E2_7D1D_4410_8DE7_A9C8E9F94CD7__INCLUDED_)
