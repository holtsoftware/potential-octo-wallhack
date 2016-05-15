// Day3Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "commondialog.h"
//}}AFX_INCLUDES

#if !defined(AFX_DAY3DLG_H__5F401FBC_611F_4A27_8EDF_38F03394F3A4__INCLUDED_)
#define AFX_DAY3DLG_H__5F401FBC_611F_4A27_8EDF_38F03394F3A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDay3Dlg dialog

class CDay3Dlg : public CDialog
{
// Construction
public:
	CDay3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDay3Dlg)
	enum { IDD = IDD_DAY3_DIALOG };
	CCommonDialog1	m_cColorDialog;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDay3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iColorMnu;
	bool m_bInSubMnu;
	BOOL m_bCursor;
	int m_iToDo;
	CPoint PrevPoint;
	CPen lpen;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY3DLG_H__5F401FBC_611F_4A27_8EDF_38F03394F3A4__INCLUDED_)
