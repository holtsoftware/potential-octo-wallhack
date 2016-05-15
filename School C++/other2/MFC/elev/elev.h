// elev.h : main header file for the ELEV application
//

#if !defined(AFX_ELEV_H__7A972530_E570_11D3_928D_DCB583C21533__INCLUDED_)
#define AFX_ELEV_H__7A972530_E570_11D3_928D_DCB583C21533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CElevApp:
// See elev.cpp for the implementation of this class
//

class CElevApp : public CWinApp
{
public:
	CElevApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElevApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CElevApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELEV_H__7A972530_E570_11D3_928D_DCB583C21533__INCLUDED_)
