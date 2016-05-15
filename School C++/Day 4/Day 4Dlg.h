// Day 4Dlg.h : header file
//

#if !defined(AFX_DAY4DLG_H__9A1E2DCC_1F9C_4193_A231_C96944E9B3C1__INCLUDED_)
#define AFX_DAY4DLG_H__9A1E2DCC_1F9C_4193_A231_C96944E9B3C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay4Dlg dialog

class CDay4Dlg : public CDialog
{
// Construction
public:
	CDay4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay4Dlg)
	enum { IDD = IDD_DAY4_DIALOG };
	CButton	m_cStopTime;
	CButton	m_cStartTime;
	CString	m_sTime;
	CString	m_sCount;
	int		m_iInterval;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChangeInterval();
	afx_msg void OnStarttimer();
	afx_msg void OnStoptimer();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iCount;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY4DLG_H__9A1E2DCC_1F9C_4193_A231_C96944E9B3C1__INCLUDED_)
