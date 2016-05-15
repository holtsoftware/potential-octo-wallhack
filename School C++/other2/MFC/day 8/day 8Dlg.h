// day 8Dlg.h : header file
//

#if !defined(AFX_DAY8DLG_H__7DEC58B4_D03D_11D3_928D_D67E4621598D__INCLUDED_)
#define AFX_DAY8DLG_H__7DEC58B4_D03D_11D3_928D_D67E4621598D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay8Dlg dialog

class CDay8Dlg : public CDialog
{
// Construction
public:
	CDay8Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay8Dlg)
	enum { IDD = IDD_DAY8_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay8Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay8Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY8DLG_H__7DEC58B4_D03D_11D3_928D_D67E4621598D__INCLUDED_)
