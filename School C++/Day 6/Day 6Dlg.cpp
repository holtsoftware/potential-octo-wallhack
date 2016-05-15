// Day 6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Day 6.h"
#include "Day 6Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay6Dlg dialog

CDay6Dlg::CDay6Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDay6Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDay6Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDay6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDay6Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDay6Dlg, CDialog)
	//{{AFX_MSG_MAP(CDay6Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_COMMAND(IDM_FILE_HELLO, OnFileHello)
	ON_COMMAND(IDM_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(IDM_FILE_EXIT, OnExit)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay6Dlg message handlers

BOOL CDay6Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDay6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDay6Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDay6Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDay6Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here

	/////////////////////
	//My code starts here
	/////////////////////

	//Exit 
	OnOK();

	/////////////////////
	//My code ends here
	/////////////////////
	
}

void CDay6Dlg::OnFileHello() 
{
	// TODO: Add your command handler code here
	
	/////////////////////
	//My code starts here
	/////////////////////

	// Display a message for the user
	MessageBox("Hello there","Hello");

	/////////////////////
	//My code ends here
	/////////////////////
}

void CDay6Dlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here

	/////////////////////
	//My code starts here
	/////////////////////
	
	// Declate an instance of the About window
	CAboutDlg dlgAbout;

	// Show the about window
	dlgAbout.DoModal();

	/////////////////////
	//My code ends here
	/////////////////////
}

void CDay6Dlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here

	/////////////////////
	//My code starts here
	/////////////////////

	// Declare local variables
	CMenu *m_lMenu;		// A pointer to the menu
	CPoint m_pPoint;	// A copy of the mouse position

	// Copy the mouse position to a local variable
	m_pPoint=point;
	// Get a pointer to the window menu
	m_lMenu =GetMenu();
	// Get a pointer to the first submenu
	m_lMenu=m_lMenu->GetSubMenu(0);
	// Show the popup Menu
	m_lMenu->TrackPopupMenu(TPM_LEFTALIGN+TPM_LEFTBUTTON,m_pPoint.x,m_pPoint.y,this,NULL);

	/////////////////////
	//My code ends here
	/////////////////////
	
}
