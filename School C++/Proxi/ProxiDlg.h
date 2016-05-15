// ProxiDlg.h : header file
//

#if !defined(AFX_PROXIDLG_H__F6F2753B_BC31_4BF1_8547_45D26305D487__INCLUDED_)
#define AFX_PROXIDLG_H__F6F2753B_BC31_4BF1_8547_45D26305D487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CProxiDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CProxiDlg dialog

class CProxiDlg : public CDialog
{
	DECLARE_DYNAMIC(CProxiDlg);
	friend class CProxiDlgAutoProxy;

// Construction
public:
	CProxiDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CProxiDlg();

// Dialog Data
	//{{AFX_DATA(CProxiDlg)
	enum { IDD = IDD_PROXI_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProxiDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CProxiDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CProxiDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnCmdbind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CAsyncSocket m_sMySocket;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROXIDLG_H__F6F2753B_BC31_4BF1_8547_45D26305D487__INCLUDED_)
