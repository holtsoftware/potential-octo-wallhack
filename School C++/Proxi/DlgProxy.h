// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__C159C6F8_FBF6_4308_8321_DAAEAC3F6D52__INCLUDED_)
#define AFX_DLGPROXY_H__C159C6F8_FBF6_4308_8321_DAAEAC3F6D52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CProxiDlg;

/////////////////////////////////////////////////////////////////////////////
// CProxiDlgAutoProxy command target

class CProxiDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CProxiDlgAutoProxy)

	CProxiDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CProxiDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProxiDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CProxiDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CProxiDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CProxiDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CProxiDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__C159C6F8_FBF6_4308_8321_DAAEAC3F6D52__INCLUDED_)
