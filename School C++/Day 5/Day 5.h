// Day 5.h : main header file for the DAY 5 application
//

#if !defined(AFX_DAY5_H__06767F5D_03FD_49E8_83FF_C72CD3F42D81__INCLUDED_)
#define AFX_DAY5_H__06767F5D_03FD_49E8_83FF_C72CD3F42D81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDay5App:
// See Day 5.cpp for the implementation of this class
//

class CDay5App : public CWinApp
{
public:
	CDay5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDay5App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY5_H__06767F5D_03FD_49E8_83FF_C72CD3F42D81__INCLUDED_)
