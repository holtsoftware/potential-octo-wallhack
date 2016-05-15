// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Proxi.h"
#include "DlgProxy.h"
#include "ProxiDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProxiDlgAutoProxy

IMPLEMENT_DYNCREATE(CProxiDlgAutoProxy, CCmdTarget)

CProxiDlgAutoProxy::CProxiDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CProxiDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CProxiDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CProxiDlgAutoProxy::~CProxiDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CProxiDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CProxiDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CProxiDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CProxiDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CProxiDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IProxi to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {4603921A-A400-4EC4-9EA7-ACDEFF4EF394}
static const IID IID_IProxi =
{ 0x4603921a, 0xa400, 0x4ec4, { 0x9e, 0xa7, 0xac, 0xde, 0xff, 0x4e, 0xf3, 0x94 } };

BEGIN_INTERFACE_MAP(CProxiDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CProxiDlgAutoProxy, IID_IProxi, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {1AAF21D1-D390-485D-8FD2-D39D083D052D}
IMPLEMENT_OLECREATE2(CProxiDlgAutoProxy, "Proxi.Application", 0x1aaf21d1, 0xd390, 0x485d, 0x8f, 0xd2, 0xd3, 0x9d, 0x8, 0x3d, 0x5, 0x2d)

/////////////////////////////////////////////////////////////////////////////
// CProxiDlgAutoProxy message handlers
