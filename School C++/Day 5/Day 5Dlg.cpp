// Day 5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Day 5.h"
#include "MsgDlg.h"
#include "Day 5Dlg.h"

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
// CDay5Dlg dialog

CDay5Dlg::CDay5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDay5Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDay5Dlg)
	m_sResults = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDay5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDay5Dlg)
	DDX_Control(pDX, IDC_BWHICHOPTION, m_cWhichOption);
	DDX_Text(pDX, IDC_RESULTS, m_sResults);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDay5Dlg, CDialog)
	//{{AFX_MSG_MAP(CDay5Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_YESNOCANCEL, OnYesNoCancel)
	ON_BN_CLICKED(IDC_ABORTRETRYIGNORE, OnAbortRetryIgnore)
	ON_BN_CLICKED(IDC_FILEOPEN, OnFileOpen)
	ON_BN_CLICKED(IDC_BCUSTOMDIALOG, OnBcustomdialog)
	ON_BN_CLICKED(IDC_BWHICHOPTION, OnBwhichoption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay5Dlg message handlers

BOOL CDay5Dlg::OnInitDialog()
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

void CDay5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDay5Dlg::OnPaint() 
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
HCURSOR CDay5Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDay5Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here

	/////////////////////
	//My Code starts here
	/////////////////////

	//Exits the program
	OnOK();

	/////////////////////
	//My code ends here
	/////////////////////
	
}

void CDay5Dlg::OnYesNoCancel() 
{
	// TODO: Add your control notification handler code here

	/////////////////////
	//My code starts here
	/////////////////////

	int iResults;//This variable will capture the button selection

	//Ask the user
	iResults=MessageBox("Press the Yes, No, or Cancel button",
		"Yes, No, Cancel Dialog",
		MB_YESNOCANCEL | MB_ICONINFORMATION);

	//Determine which button the user clicked
	//Give the user a message showing which button was clicked
	switch(iResults)
	{
	case IDYES:
		m_sResults = "Yes! Yes! Yes!";
		break;
	case IDNO:
		m_sResults = "No, no, no, no, no.";
		break;
	case IDCANCEL:
		m_sResults="Sorry, canceled.";
		break;
	}
	
	//Update the dialog
	UpdateData(FALSE);

	/////////////////////
	//My code ends here
	/////////////////////
}

void CDay5Dlg::OnAbortRetryIgnore() 
{
	// TODO: Add your control notification handler code here

	/////////////////////
	//My code begins here
	/////////////////////

	int iResults;// This variable will capture the button selection

	// Ask the user
	iResults = MessageBox("Press the Abort, Retry, Ignore button","Abort, Retry, Ignore Dialog",
							MB_ABORTRETRYIGNORE | MB_ICONQUESTION);

	// Determin which button the user clicked
	// Give the user a message showing which button was clicked
	switch(iResults)
	{
	case IDABORT:
		m_sResults="Aborted.";
		break;
	case IDRETRY:
		m_sResults="Retry.";
		break;
	case IDIGNORE:
		m_sResults="Ignore.";
	}

	// Update the dialog
	UpdateData(FALSE);

	/////////////////////
	//My code ends here
	/////////////////////
	
}

void CDay5Dlg::OnFileOpen() 
{
	// TODO: Add your control notification handler code here

	/////////////////////
	//My code starts here
	/////////////////////

	CFileDialog m_ldFile(TRUE);

	// Show the file open dialog and capture the results
	if(m_ldFile.DoModal()==IDOK)
	{
		//creates the file and initalizes it to the folder path of the file
		CString file=m_ldFile.GetFolderPath();
		// shows the file name including the folder path
		m_sResults=file;
		//Update the dialog
		UpdateData(FALSE);
	}

	/////////////////////
	//My code ends here
	/////////////////////
	
}

void CDay5Dlg::OnBcustomdialog() 
{
	// TODO: Add your control notification handler code here
	
	//////////////////////
	//My code starts here
	//////////////////////

	// Show the message dialog and capture the result
	if(m_dMsgDlg.DoModal() == IDOK)
	{
		// The user checked OK, display the message the user typed in on the message dialog
		m_sResults=m_dMsgDlg.m_sMesssage;
		//Update the dialog
		UpdateData(FALSE);
		//Enable the Which Option button
		m_cWhichOption.EnableWindow(TRUE);
	}
	else
	{
		//Disable the Which option button
		m_cWhichOption.EnableWindow(FALSE);
	}

	/////////////////////
	//My code ends here
	/////////////////////
}

void CDay5Dlg::OnBwhichoption() 
{
	// TODO: Add your control notification handler code here
	
	/////////////////////
	//My code starts here
	/////////////////////

	//Determin which radio button was selected, and display
	// a message for the user to show which one was selected.
	switch(m_dMsgDlg.m_iOption)
	{
	case 0: //was it the first radio button?
		m_sResults="The first option was selected.";
		break;
	case 1: // Was it the second radio button?
		m_sResults="The Second option was selected.";
		break;
	case 2: // Was it the third radio button?
		m_sResults="The Third option was selected.";
		break;
	case 3: // Was it the fourth radio button?
		m_sResults="The fourth option was selected.";
		break;
	default: // Were none of the radio buttons selected?
		m_sResults="No option was selected.";
		break;
	}

	//Update the dialog
	UpdateData(FALSE);

	////////////////////
	//My code ends here
	////////////////////
}
