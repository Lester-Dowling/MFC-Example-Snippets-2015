#include "pch-MFC-Example-Snippets.hpp"
#include "TheApp.hpp"
#include "ExampleSnippetsDialogAutoProxy.hpp"
#include "ExampleSnippetsDialog.hpp"
#include "MFCExampleSnippets_h.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(ExampleSnippetsDialogAutoProxy, CCmdTarget);


BEGIN_MESSAGE_MAP(ExampleSnippetsDialogAutoProxy, CCmdTarget)
END_MESSAGE_MAP();


BEGIN_DISPATCH_MAP(ExampleSnippetsDialogAutoProxy, CCmdTarget)
END_DISPATCH_MAP();


BEGIN_INTERFACE_MAP(ExampleSnippetsDialogAutoProxy, CCmdTarget)
{
	&DIID_IMFCExampleSnippets, offsetof(ExampleSnippetsDialogAutoProxy, m_xDispatch)
},
END_INTERFACE_MAP();


IMPLEMENT_OLECREATE2(ExampleSnippetsDialogAutoProxy, "MFCExampleSnippets.Application", CLSID_MFCExampleSnippets);


ExampleSnippetsDialogAutoProxy::ExampleSnippetsDialogAutoProxy()
{
	EnableAutomation();

	// To keep the application running as long as an automation
	//  object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(ExampleSnippetsDialog, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(ExampleSnippetsDialog)))
		{
			m_pDialog = reinterpret_cast<ExampleSnippetsDialog*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}



ExampleSnippetsDialogAutoProxy::~ExampleSnippetsDialogAutoProxy()
{
	// To terminate the application when all objects created with
	//  with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}



void ExampleSnippetsDialogAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}
