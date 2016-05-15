// Day3.h : main header file for the DAY3 application
//

#if !defined(AFX_DAY3_H__82E11FA9_2C25_4323_BFAE_6806F7BB9595__INCLUDED_)
#define AFX_DAY3_H__82E11FA9_2C25_4323_BFAE_6806F7BB9595__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay3App:
// See Day3.cpp for the implementation of this class
//

class CDay3App : public CWinApp
{
public:
	CDay3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDay3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY3_H__82E11FA9_2C25_4323_BFAE_6806F7BB9595__INCLUDED_)
