// Proxi.h : main header file for the PROXI application
//

#if !defined(AFX_PROXI_H__7F5AE922_245C_4EDA_9B16_705859785F16__INCLUDED_)
#define AFX_PROXI_H__7F5AE922_245C_4EDA_9B16_705859785F16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProxiApp:
// See Proxi.cpp for the implementation of this class
//

class CProxiApp : public CWinApp
{
public:
	CProxiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProxiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProxiApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROXI_H__7F5AE922_245C_4EDA_9B16_705859785F16__INCLUDED_)
