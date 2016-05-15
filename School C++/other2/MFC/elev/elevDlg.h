// elevDlg.h : header file
//

#if !defined(AFX_ELEVDLG_H__7A972532_E570_11D3_928D_DCB583C21533__INCLUDED_)
#define AFX_ELEVDLG_H__7A972532_E570_11D3_928D_DCB583C21533__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CElevDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CElevDlg dialog

class CElevDlg : public CDialog
{
	DECLARE_DYNAMIC(CElevDlg);
	friend class CElevDlgAutoProxy;

// Construction
public:
	CElevDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CElevDlg();

// Dialog Data
	//{{AFX_DATA(CElevDlg)
	enum { IDD = IDD_ELEV_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CElevDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CElevDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CElevDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ELEVDLG_H__7A972532_E570_11D3_928D_DCB583C21533__INCLUDED_)
