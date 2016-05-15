// Day 6.h : main header file for the DAY 6 application
//

#if !defined(AFX_DAY6_H__A2BE2BAC_A219_4C6A_BE5A_A80B14A7B1DC__INCLUDED_)
#define AFX_DAY6_H__A2BE2BAC_A219_4C6A_BE5A_A80B14A7B1DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay6App:
// See Day 6.cpp for the implementation of this class
//

class CDay6App : public CWinApp
{
public:
	CDay6App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay6App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDay6App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY6_H__A2BE2BAC_A219_4C6A_BE5A_A80B14A7B1DC__INCLUDED_)
