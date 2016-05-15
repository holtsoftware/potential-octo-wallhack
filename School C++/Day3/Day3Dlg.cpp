// Day3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Day3.h"
#include "Day3Dlg.h"

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
// CDay3Dlg dialog

CDay3Dlg::CDay3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDay3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDay3Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDay3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDay3Dlg)
	DDX_Control(pDX, IDC_COLORDIALOG, m_cColorDialog);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDay3Dlg, CDialog)
	//{{AFX_MSG_MAP(CDay3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_WM_SETCURSOR()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay3Dlg message handlers

BOOL CDay3Dlg::OnInitDialog()
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
	m_iToDo=2;
	
	m_bCursor=FALSE;

	lpen.CreatePen(PS_SOLID,1,RGB(0,0,0));

	m_iColorMnu=0;//Wight

	m_bInSubMnu=false;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDay3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDay3Dlg::OnPaint() 
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
HCURSOR CDay3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDay3Dlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if((nFlags & MK_LBUTTON)==MK_LBUTTON)
	{
		CClientDC dc(this);

		dc.SelectObject(&lpen);


		dc.MoveTo(PrevPoint);
		dc.LineTo(point);

		PrevPoint=point;
	}
		
	CDialog::OnMouseMove(nFlags, point);
}

BOOL CDay3Dlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	RECT *pt;
	pt=new RECT;
	
	pt->top=0;
	pt->left=0;
	pt->bottom=20;
	pt->right=60;
	
	dc.SetBkColor(RGB(10,255,50));
	
	if(m_bInSubMnu)
	{

		switch(m_iToDo)
		{
		case 0:
			pt->left=60;
			pt->right=60+60;
			if(zDelta>0)
			{
				if(m_iColorMnu+1>4)
				{
					m_iColorMnu=0;
				}
				else
				{
					m_iColorMnu++;
				}
			}
			else
			{
				if(m_iColorMnu-1<0)
				{
					m_iColorMnu=4;
				}
				else
				{
					m_iColorMnu--;
				}
			}
			switch(m_iColorMnu)
			{
			case 0:
				dc.DrawText("..          ",pt,DT_LEFT);
				break;
			case 1:
				dc.DrawText("Whight",pt,DT_LEFT);
				break;
			case 2:
				dc.DrawText("Black   ",pt,DT_LEFT);
				break;
			case 3:
				dc.DrawText("Yellow  ",pt,DT_LEFT);
				break;
			case 4:
				dc.DrawText("Custom  ",pt,DT_LEFT);
				break;
			default:
				MessageBox("ERROR");
				break;
			};
			break;
		default:
			break;
		};
	}
	else
	{	

		if(zDelta>0)
		{
			if(m_iToDo+1>2)
			{
				m_iToDo=0;
			}
			else
			{
				m_iToDo++;
			}
		}
		else
		{
			if(m_iToDo-1<0)
			{
				m_iToDo=2;
			}
			else
			{
				m_iToDo--;
			}
		}

		switch(m_iToDo)
		{
		case 1:
			dc.DrawText("EXIT ",pt,DT_LEFT);
			break;
		case 0:
			dc.DrawText("Color",pt,DT_LEFT);
			break;
		default:
			break;
		};
	}

	delete pt;
	
	return CDialog::OnMouseWheel(nFlags, zDelta, point);
}

void CDay3Dlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	//Set the current point as the starting point
	PrevPoint=point;

	CDialog::OnLButtonDown(nFlags, point);
}

void CDay3Dlg::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_iToDo==1)
	{
		OnOK();
	}
	
	CDialog::OnRButtonDblClk(nFlags, point);
}

void CDay3Dlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	char isChar=char(nChar);
	HCURSOR lhCursor;
	
	m_bCursor=TRUE;

	switch(isChar)
	{
	case 'A':
		lhCursor=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		//Set the screen cursor
		SetCursor(lhCursor);
		break;

	case 'B':
		lhCursor=AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
		//Set the screen cursor
		SetCursor(lhCursor);
		break;

	case 'C':
		lhCursor=AfxGetApp()->LoadStandardCursor(IDC_WAIT);
		//Set the screen cursor
		SetCursor(lhCursor);
		break;

	case 'X':
		lhCursor=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		//Set the screen cursor
		SetCursor(lhCursor);
		OnOK();
		m_bCursor=TRUE;
		break;
	default:
		break;
	};
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CDay3Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bCursor)
		return TRUE;
	else
		
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CDay3Dlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(m_bInSubMnu)
	{	
		switch(m_iToDo)
		{
		case 0:
			switch(m_iColorMnu)
			{
				case 0:
					m_bInSubMnu=false;
					break;
				case 1:
					lpen.DeleteObject();
					lpen.CreatePen(PS_SOLID,1,RGB(255,255,255));
					break;
				case 2:
					lpen.DeleteObject();
					lpen.CreatePen(PS_SOLID,1,RGB(0,0,0));
					break;
				case 3:
					lpen.DeleteObject();
					lpen.CreatePen(PS_SOLID,1,RGB(255,255,0));
					break;
				case 4:
					m_cColorDialog.ShowColor();
					lpen.DeleteObject();
					lpen.CreatePen(PS_SOLID,1,m_cColorDialog.GetColor());
					break;
				default:
					lpen.DeleteObject();
					lpen.CreatePen(PS_SOLID,1,RGB(0,0,0));
					break;
			};
			break;
		default:
			break;
		};
	}
	else
	{
		m_bInSubMnu=true;
	}
	

	CDialog::OnRButtonDown(nFlags, point);
}
