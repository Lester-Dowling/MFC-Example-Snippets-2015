
// ExampleCodeDialogAutoProxy.cpp : implementation file
//

#include "stdafx.h"
#include "MFC-Example-Code.h"
#include "ExampleCodeDialogAutoProxy.hpp"
#include "ExampleCodeDialog.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ExampleCodeDialogAutoProxy

IMPLEMENT_DYNCREATE(ExampleCodeDialogAutoProxy, CCmdTarget)

ExampleCodeDialogAutoProxy::ExampleCodeDialogAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(ExampleCodeDialog, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(ExampleCodeDialog)))
		{
			m_pDialog = reinterpret_cast<ExampleCodeDialog*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

ExampleCodeDialogAutoProxy::~ExampleCodeDialogAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void ExampleCodeDialogAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(ExampleCodeDialogAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(ExampleCodeDialogAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_IMFCExampleCode to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {FFD422F2-4B62-4D59-B35A-8CACEE5806CB}
static const IID IID_IMFCExampleCode =
{ 0xFFD422F2, 0x4B62, 0x4D59, { 0xB3, 0x5A, 0x8C, 0xAC, 0xEE, 0x58, 0x6, 0xCB } };

BEGIN_INTERFACE_MAP(ExampleCodeDialogAutoProxy, CCmdTarget)
	INTERFACE_PART(ExampleCodeDialogAutoProxy, IID_IMFCExampleCode, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {E858A01C-0C76-41E6-A375-C1626C6E0F8C}
IMPLEMENT_OLECREATE2(ExampleCodeDialogAutoProxy, "MFCExampleCode.Application", 0xe858a01c, 0xc76, 0x41e6, 0xa3, 0x75, 0xc1, 0x62, 0x6c, 0x6e, 0xf, 0x8c)


// ExampleCodeDialogAutoProxy message handlers
