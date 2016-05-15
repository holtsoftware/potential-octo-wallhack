// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__7A972534_E570_11D3_928D_DCB583C21533__INCLUDED_)
#define AFX_DLGPROXY_H__7A972534_E570_11D3_928D_DCB583C21533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CElevDlg;

/////////////////////////////////////////////////////////////////////////////
// CElevDlgAutoProxy command target

class CElevDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CElevDlgAutoProxy)

	CElevDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CElevDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElevDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CElevDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CElevDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CElevDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CElevDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__7A972534_E570_11D3_928D_DCB583C21533__INCLUDED_)
