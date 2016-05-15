// Day 5Dlg.h : header file
//

#if !defined(AFX_DAY5DLG_H__3BD6D9C7_F209_435C_B32C_67C58C4B2DD0__INCLUDED_)
#define AFX_DAY5DLG_H__3BD6D9C7_F209_435C_B32C_67C58C4B2DD0__INCLUDED_

#include "MsgDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay5Dlg dialog

class CDay5Dlg : public CDialog
{
// Construction
public:
	CDay5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay5Dlg)
	enum { IDD = IDD_DAY5_DIALOG };
	CButton	m_cWhichOption;
	CString	m_sResults;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay5Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnYesNoCancel();
	afx_msg void OnAbortRetryIgnore();
	afx_msg void OnFileOpen();
	afx_msg void OnBcustomdialog();
	afx_msg void OnBwhichoption();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMsgDlg m_dMsgDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY5DLG_H__3BD6D9C7_F209_435C_B32C_67C58C4B2DD0__INCLUDED_)
