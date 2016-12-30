#include "pch-MFC-Example-Snippets.hpp"
#include "TheApp.hpp"
#include "ExampleSnippetsDialog.hpp"
#include "ExampleSnippetsDialogAutoProxy.hpp"
#include "AboutDlg.hpp"
#include "Examples/_CEvent/Trivial_Usage.hpp"
#include "Examples/_CEvent/Calculate_Prime_Numbers.hpp"
#include <boost/bind.hpp>
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNAMIC(ExampleSnippetsDialog, CDHtmlDialog);


BEGIN_MESSAGE_MAP(ExampleSnippetsDialog, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_TIMER()
END_MESSAGE_MAP();


BEGIN_DHTML_EVENT_MAP(ExampleSnippetsDialog)
	DHTML_EVENT_ONCLICK(L"Examples::_CEvent::Trivial_Usage", On_CEvent_Trivial_Usage)
	DHTML_EVENT_ONCLICK(L"Examples::_CEvent::Calculate_Prime_Numbers", On_CEvent_Calculate_Prime_Numbers)
	DHTML_EVENT_ONCLICK(L"ButtonCancel", OnButtonCancel)
END_DHTML_EVENT_MAP();



/*slot*/ void ExampleSnippetsDialog::write_text_out(std::wstring text_out)
{
	::Sleep(100);
	while (text_out_lock) { ::Sleep(50); }; text_out_lock = true;
	*m_text_out_stream << "<p>" << text_out << "</p>" << std::endl;
	text_out_lock = false;
	more_text_out = true;
}



void ExampleSnippetsDialog::write_text_out_stream()
{
	IHTMLElement* pElement = NULL;
	if (GetElement(_T("text-out"), &pElement) == S_OK && pElement != NULL)
	{
		// Update the text-out element with the contents of the text out stream:
		while (text_out_lock) { ::Sleep(50); }; text_out_lock = true;
		BSTR updated_text_out = ::SysAllocString(m_text_out_stream->str().c_str());
		text_out_lock = false;
		pElement->put_innerHTML(updated_text_out);
		more_text_out = false;
	}
}


static UINT __cdecl run_example_thread_proc(LPVOID lpParameter)
{
	auto dialog = reinterpret_cast<ExampleSnippetsDialog*>(lpParameter);
	if (dialog == nullptr || !dialog->IsKindOf(RUNTIME_CLASS(ExampleSnippetsDialog)))
		return 1;   // dialog is not valid  
	dialog->runnable()->run();
	// Terminate the thread:
	dialog->clean_up_example();
	::AfxEndThread(0, FALSE);
	return 0L;
}



void ExampleSnippetsDialog::run_example(Interface::Runnable *runnable)
{
	ASSERT(m_runnable == nullptr);
	ASSERT(m_pThread == nullptr);
	ASSERT(m_text_out_stream == nullptr);
	ASSERT(more_text_out == false);
	ASSERT(text_out_lock == false);
	ASSERT(runnable != nullptr);
	m_runnable = runnable;
	m_text_out_stream = new std::wostringstream;
	m_text_out_connection = m_runnable->connect(boost::bind(&ExampleSnippetsDialog::write_text_out, this, _1));
	m_pThread = AfxBeginThread(&run_example_thread_proc, this);
	//, 0, 0, CREATE_SUSPENDED, NULL);
	//m_pThread->ResumeThread();
}



void ExampleSnippetsDialog::clean_up_example()
{
	while (more_text_out || text_out_lock) { ::Sleep(50); };
	ASSERT(more_text_out == false);
	ASSERT(text_out_lock == false);
	m_runnable->disconnect(m_text_out_connection);
	std::wostringstream oss;
	oss << "Finished: " << __FUNCTION__;
	write_text_out(oss.str());
	while (more_text_out) { ::Sleep(50); };
	more_text_out = false;
	text_out_lock = false;
	delete m_text_out_stream; m_text_out_stream = nullptr;
	delete m_runnable; m_runnable = nullptr;
	m_pThread = nullptr; // Thread will auto-delete itself.
}



HRESULT ExampleSnippetsDialog::On_CEvent_Trivial_Usage(IHTMLElement*)
{
	if (m_runnable) return S_OK; // Guard against multiple concurrent examples.
	run_example(new Examples::_CEvent::Trivial_Usage);
	return S_OK;
}



HRESULT ExampleSnippetsDialog::On_CEvent_Calculate_Prime_Numbers(IHTMLElement*)
{
	if (m_runnable) return S_OK; // Guard against multiple concurrent examples.
	run_example(new Examples::_CEvent::Calculate_Prime_Numbers);
	return S_OK;
}



ExampleSnippetsDialog::ExampleSnippetsDialog(CWnd* pParent /*=nullptr*/)
	: CDHtmlDialog(IDD_MFCEXAMPLECODE_DIALOG, IDR_HTML_MFCEXAMPLECODE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = nullptr;
}



ExampleSnippetsDialog::~ExampleSnippetsDialog()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to nullptr, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != nullptr)
		m_pAutoProxy->m_pDialog = nullptr;
}



void ExampleSnippetsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}



BOOL ExampleSnippetsDialog::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);         // Set big icon
	SetIcon(m_hIcon, FALSE);        // Set small icon

	text_out_timer = this->SetTimer(text_out_timer, 100, nullptr);

	return TRUE;  // return TRUE  unless you set the focus to a control
}



void ExampleSnippetsDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		AboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}



void ExampleSnippetsDialog::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDHtmlDialog::OnPaint();
	}
}



HCURSOR ExampleSnippetsDialog::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ExampleSnippetsDialog::OnClose()
{
	if (CanExit())
		CDHtmlDialog::OnClose();
}



void ExampleSnippetsDialog::OnCancel()
{
	if (CanExit())
		CDHtmlDialog::OnCancel();
}



BOOL ExampleSnippetsDialog::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != nullptr)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}
	return TRUE;
}



HRESULT ExampleSnippetsDialog::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}



void ExampleSnippetsDialog::OnTimer(UINT_PTR)
{
	if (more_text_out)
	{
		write_text_out_stream();
	}
}
