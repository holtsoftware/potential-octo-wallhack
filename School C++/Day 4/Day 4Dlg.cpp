// Day 4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Day 4.h"
#include "Day 4Dlg.h"

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
// CDay4Dlg dialog

CDay4Dlg::CDay4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDay4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDay4Dlg)
	m_sTime = _T("");
	m_sCount = _T("");
	m_iInterval = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDay4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDay4Dlg)
	DDX_Control(pDX, IDC_STOPTIMER, m_cStopTime);
	DDX_Control(pDX, IDC_STARTTIMER, m_cStartTime);
	DDX_Text(pDX, IDC_STATICTIME, m_sTime);
	DDX_Text(pDX, IDC_STATICCOUNT, m_sCount);
	DDX_Text(pDX, IDC_INTERVAL, m_iInterval);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDay4Dlg, CDialog)
	//{{AFX_MSG_MAP(CDay4Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_INTERVAL, OnChangeInterval)
	ON_BN_CLICKED(IDC_STARTTIMER, OnStarttimer)
	ON_BN_CLICKED(IDC_STOPTIMER, OnStoptimer)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay4Dlg message handlers

BOOL CDay4Dlg::OnInitDialog()
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

	/////////////////////
	//MY code starts hear
	/////////////////////

	//Start the Clock Timer
	SetTimer(ID_CLOCK_TIMER,1000,NULL);

	//Update teh dialog
	UpdateData(FALSE);

	/////////////////////
	//My code ends hear
	/////////////////////
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDay4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDay4Dlg::OnPaint() 
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
HCURSOR CDay4Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDay4Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	/////////////////////
	//My code starts here
	/////////////////////

	//Get the current time
	CTime curTime=CTime::GetCurrentTime();

	switch(nIDEvent)
	{
	case ID_CLOCK_TIMER:
		//Desplay the current time
		m_sTime.Format("%d:%d:%d",curTime.GetHour(),curTime.GetMinute(),curTime.GetSecond());
		break;
	case ID_COUNT_TIMER:
		m_iCount++;
		//Formate and display the count
		m_sCount.Format("%d",m_iCount);
		break;
	};

	//Update the dialog
	UpdateData(FALSE);

	//////////////////
	//My code end here
	//////////////////
	
	CDialog::OnTimer(nIDEvent);
}

void CDay4Dlg::OnChangeInterval() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
	/////////////////////
	//My code starts here
	/////////////////////

	if(m_iInterval<1)
	{
		m_iInterval=1;
	}
	//Update the variables
	UpdateData(TRUE);

	/////////////////////
	//My code ends here
	/////////////////////
}

void CDay4Dlg::OnStarttimer() 
{
	// TODO: Add your control notification handler code here
	
	//////////////////////
	//My code starts here
	//////////////////////

	//update the variables
	UpdateData(TRUE);

	//Initialize the count
	m_iCount=0;

	//Formate teh count for displaying
	m_sCount.Format("%d",m_iCount);

	//Update teh dialog
	UpdateData(FALSE);

	//Start the timer
	SetTimer(ID_COUNT_TIMER,m_iInterval,NULL);

	//Enable teh stop timer button
	m_cStopTime.EnableWindow(TRUE);
	//Disable the start timer button
	m_cStartTime.EnableWindow(FALSE);

	///////////////////
	//MY code ends here
	///////////////////
}

void CDay4Dlg::OnStoptimer() 
{
	// TODO: Add your control notification handler code here

	/////////////////////
	//My code starts here
	/////////////////////

	//Stop the timer
	KillTimer(ID_COUNT_TIMER);

	//Enable the start timer button
	m_cStartTime.EnableWindow(TRUE);
	//Disable the stop timer button
	m_cStopTime.EnableWindow(FALSE);

	/////////////////////
	//My code ends here
	/////////////////////
	
}

void CDay4Dlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
	
}
