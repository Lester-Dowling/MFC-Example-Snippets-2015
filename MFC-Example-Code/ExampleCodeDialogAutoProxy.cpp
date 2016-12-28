#include "pch-MFC-Example-Code.hpp"
#include "TheApp.hpp"
#include "ExampleCodeDialogAutoProxy.hpp"
#include "ExampleCodeDialog.hpp"
#include "MFCExampleCode_h.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(ExampleCodeDialogAutoProxy, CCmdTarget);


BEGIN_MESSAGE_MAP(ExampleCodeDialogAutoProxy, CCmdTarget)
END_MESSAGE_MAP();


BEGIN_DISPATCH_MAP(ExampleCodeDialogAutoProxy, CCmdTarget)
END_DISPATCH_MAP();


BEGIN_INTERFACE_MAP(ExampleCodeDialogAutoProxy, CCmdTarget)
	INTERFACE_PART(ExampleCodeDialogAutoProxy, DIID_IMFCExampleCode, Dispatch)
END_INTERFACE_MAP();


IMPLEMENT_OLECREATE2(ExampleCodeDialogAutoProxy, "MFCExampleCode.Application", CLSID_MFCExampleCode);


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
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
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
