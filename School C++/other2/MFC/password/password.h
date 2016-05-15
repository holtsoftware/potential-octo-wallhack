// password.h : main header file for the PASSWORD application
//

#if !defined(AFX_PASSWORD_H__7DEC58A4_D03D_11D3_928D_D67E4621598D__INCLUDED_)
#define AFX_PASSWORD_H__7DEC58A4_D03D_11D3_928D_D67E4621598D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPasswordApp:
// See password.cpp for the implementation of this class
//

class CPasswordApp : public CWinApp
{
public:
	CPasswordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPasswordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPasswordApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORD_H__7DEC58A4_D03D_11D3_928D_D67E4621598D__INCLUDED_)
