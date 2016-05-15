// news.h : main header file for the NEWS application
//

#if !defined(AFX_NEWS_H__193A8FC4_9ED4_11D3_928E_98AB44E82C2A__INCLUDED_)
#define AFX_NEWS_H__193A8FC4_9ED4_11D3_928E_98AB44E82C2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNewsApp:
// See news.cpp for the implementation of this class
//

class CNewsApp : public CWinApp
{
public:
	CNewsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNewsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWS_H__193A8FC4_9ED4_11D3_928E_98AB44E82C2A__INCLUDED_)
