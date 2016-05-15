// Day 6Dlg.h : header file
//

#if !defined(AFX_DAY6DLG_H__1F8CB054_A679_48F2_97CA_3065585F816B__INCLUDED_)
#define AFX_DAY6DLG_H__1F8CB054_A679_48F2_97CA_3065585F816B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay6Dlg dialog

class CDay6Dlg : public CDialog
{
// Construction
public:
	CDay6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay6Dlg)
	enum { IDD = IDD_DAY6_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnFileHello();
	afx_msg void OnHelpAbout();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY6DLG_H__1F8CB054_A679_48F2_97CA_3065585F816B__INCLUDED_)
