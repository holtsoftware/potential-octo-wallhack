// Day 1Dlg.h : header file
//

#if !defined(AFX_DAY1DLG_H__09BEF149_14A9_46CF_893A_716F7D1AA371__INCLUDED_)
#define AFX_DAY1DLG_H__09BEF149_14A9_46CF_893A_716F7D1AA371__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay1Dlg dialog

class CDay1Dlg : public CDialog
{
// Construction
public:
	CDay1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay1Dlg)
	enum { IDD = IDD_DAY1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHello();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY1DLG_H__09BEF149_14A9_46CF_893A_716F7D1AA371__INCLUDED_)
