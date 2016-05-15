// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "elev.h"
#include "DlgProxy.h"
#include "elevDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CElevDlgAutoProxy

IMPLEMENT_DYNCREATE(CElevDlgAutoProxy, CCmdTarget)

CElevDlgAutoProxy::CElevDlgAutoProxy()
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
	ASSERT_KINDOF(CElevDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CElevDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CElevDlgAutoProxy::~CElevDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CElevDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CElevDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CElevDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CElevDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CElevDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IElev to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {7A97252D-E570-11D3-928D-DCB583C21533}
static const IID IID_IElev =
{ 0x7a97252d, 0xe570, 0x11d3, { 0x92, 0x8d, 0xdc, 0xb5, 0x83, 0xc2, 0x15, 0x33 } };

BEGIN_INTERFACE_MAP(CElevDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CElevDlgAutoProxy, IID_IElev, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {7A97252B-E570-11D3-928D-DCB583C21533}
IMPLEMENT_OLECREATE2(CElevDlgAutoProxy, "Elev.Application", 0x7a97252b, 0xe570, 0x11d3, 0x92, 0x8d, 0xdc, 0xb5, 0x83, 0xc2, 0x15, 0x33)

/////////////////////////////////////////////////////////////////////////////
// CElevDlgAutoProxy message handlers
