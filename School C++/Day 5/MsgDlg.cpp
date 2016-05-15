// MsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Day 5.h"
#include "MsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg dialog


CMsgDlg::CMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMsgDlg)
	m_sMesssage = _T("");
	m_iOption = -1;
	//}}AFX_DATA_INIT
}


void CMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMsgDlg)
	DDX_Text(pDX, IDC_MESSAGE, m_sMesssage);
	DDX_Radio(pDX, IDC_OPTION1, m_iOption);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CMsgDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMsgDlg message handlers
