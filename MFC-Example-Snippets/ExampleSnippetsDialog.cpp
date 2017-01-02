#include "pch-MFC-Example-Snippets.hpp"
#include "TheApp.hpp"
#include "ExampleSnippetsDialog.hpp"
#include "ExampleSnippetsDialogAutoProxy.hpp"
#include "AboutDlg.hpp"
#include "Examples/Examples.hpp"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



/**
 *  Return the HTML code for a button element.
 */
static std::wstring button_html(const wchar_t * button_id, const wchar_t * button_label)
{
	std::wostringstream woss;
	woss
		<< "<p>"
		<< "<BUTTON ID=\"" << button_id << "\">"
		<< button_label
		<< "</BUTTON>"
		<< "</p>";
	return woss.str();
}



IMPLEMENT_DYNAMIC(ExampleSnippetsDialog, CDHtmlDialog);


BEGIN_MESSAGE_MAP(ExampleSnippetsDialog, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_MESSAGE(static_cast<UINT>(MSG::more_text_out), &OnMoreTextOut)
END_MESSAGE_MAP();


BEGIN_DHTML_EVENT_MAP(ExampleSnippetsDialog)
	DHTML_EVENT_ONCLICK(Examples::_CEvent::Trivial_Usage::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(Examples::_CEvent::Calculate_Prime_Numbers::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(Examples::_CFile::Write::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(Examples::_CFile::Open::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(Examples::_CFile::GetStatus::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(Examples::_CFile::SetFilePath::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(Examples::_CFile::GetLength::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(Examples::_COleVariant::Ctors::id(), On_Run_Example)
	DHTML_EVENT_ONCLICK(L"ButtonCancel", OnButtonCancel)
END_DHTML_EVENT_MAP();



void ExampleSnippetsDialog::OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl)
{
	CDHtmlDialog::OnDocumentComplete(pDisp, szUrl);

	IHTMLElement* pElement = nullptr;
	if (GetElement(L"ButtonsToRunExamples", &pElement) == S_OK && pElement != nullptr)
	{
		// Setup the buttons to run examples:
		std::wostringstream woss;
		woss
			<< "<h1> Examples </h1>"

			<< "<h2> CEvent</h2>"
			<< button_html(Examples::_CEvent::Trivial_Usage::id(), Examples::_CEvent::Trivial_Usage::ds())
			<< button_html(Examples::_CEvent::Calculate_Prime_Numbers::id(), Examples::_CEvent::Calculate_Prime_Numbers::ds())

			<< "<h2> CFile </h2>"
			<< button_html(Examples::_CFile::Write::id(), Examples::_CFile::Write::ds())
			<< button_html(Examples::_CFile::Open::id(), Examples::_CFile::Open::ds())
			<< button_html(Examples::_CFile::GetStatus::id(), Examples::_CFile::GetStatus::ds())
			<< button_html(Examples::_CFile::SetFilePath::id(), Examples::_CFile::SetFilePath::ds())
			<< button_html(Examples::_CFile::GetLength::id(), Examples::_CFile::GetLength::ds())

			<< "<h2> COleVariant </h2>"
			<< button_html(Examples::_COleVariant::Ctors::id(), Examples::_COleVariant::Ctors::ds())
			;

		BSTR buttons_to_run_examples = ::SysAllocString(woss.str().c_str());
		pElement->put_innerHTML(buttons_to_run_examples);
	}
	else
	{
		::Beep(300, 800);
	}
}



HRESULT ExampleSnippetsDialog::On_Run_Example(IHTMLElement* pElement)
{
	if (m_runnable) return S_OK; // Guard against multiple clicks on the button.

	CComBSTR element_id;
	if (SUCCEEDED(pElement->get_id(&element_id)))
	{
		_RPTWN(_CRT_WARN, L"Got ID: %s\n", element_id);
		if (element_id == Examples::_CEvent::Trivial_Usage::id())
		{
			run_example(new Examples::_CEvent::Trivial_Usage);
			return S_OK;
		}
		if (element_id == Examples::_CEvent::Calculate_Prime_Numbers::id())
		{
			run_example(new Examples::_CEvent::Calculate_Prime_Numbers);
			return S_OK;
		}
		if (element_id == Examples::_CFile::Open::id())
		{
			run_example(new Examples::_CFile::Open);
			return S_OK;
		}
		if (element_id == Examples::_CFile::Write::id())
		{
			run_example(new Examples::_CFile::Write);
			return S_OK;
		}
		if (element_id == Examples::_CFile::GetStatus::id())
		{
			run_example(new Examples::_CFile::GetStatus);
			return S_OK;
		}
		if (element_id == Examples::_CFile::SetFilePath::id())
		{
			run_example(new Examples::_CFile::SetFilePath);
			return S_OK;
		}
		if (element_id == Examples::_CFile::GetLength::id())
		{
			run_example(new Examples::_CFile::GetLength);
			return S_OK;
		}
		if (element_id == Examples::_COleVariant::Ctors::id())
		{
			run_example(new Examples::_COleVariant::Ctors);
			return S_OK;
		}
	}
	return S_OK;
}



LRESULT ExampleSnippetsDialog::OnMoreTextOut(WPARAM wParam, LPARAM lParam)
{
	// Verify that the identity of this MSG is mine:
	if (wParam != 82 && lParam != 34) { ::Beep(500, 800); return -1; }
	// Ensure this happens on the UI thread:
	if (m_ui_thread_id == GetCurrentThreadId())
	{
		IHTMLElement* pElement = nullptr;
		if (GetElement(L"text-out", &pElement) == S_OK && pElement != nullptr)
		{
			CSingleLock text_out_lock(&m_text_out_mutex, TRUE); // Attempt to lock the mutex.
			if (!text_out_lock.IsLocked()) return -1;
			// Update the text-out element with the contents of the text out stream:
			BSTR updated_text_out = ::SysAllocString(m_text_out_stream->str().c_str());
			text_out_lock.Unlock(); // Finished with text output stream.
			//pElement->put_innerHTML(updated_text_out);
			pElement->put_innerText(updated_text_out);
			m_text_out_finished->SetEvent(); // Signal that all the current text has been sent to output.
		}
		else
		{
			::Beep(300, 1000);
		}
	}
	return 0;
}



/*slot*/ void ExampleSnippetsDialog::write_text_out(std::wstring text_out)
{
	m_text_out_finished->ResetEvent(); // Signal that there is more text to output.
	CSingleLock text_out_lock(&m_text_out_mutex, TRUE); // Attempt to lock the mutex.
	if (!text_out_lock.IsLocked()) return;
	*m_text_out_stream << text_out << std::endl;
	text_out_lock.Unlock(); // Finished with text output stream.
	ASSERT(0 < m_ui_thread_id);
	const WPARAM wParam = 82; // Arbitrary number to identify MSG::more_text_out.
	const LPARAM lParam = 34; // Arbitrary number to identify MSG::more_text_out.
	PostMessage(static_cast<UINT>(MSG::more_text_out), wParam, lParam);
	::Sleep(100); // Give the UI a brief moment to catch-up.
}



static UINT __cdecl run_example_thread_proc(LPVOID lpParameter)
{
	auto dialog = reinterpret_cast<ExampleSnippetsDialog*>(lpParameter);
	if (dialog == nullptr || !dialog->IsKindOf(RUNTIME_CLASS(ExampleSnippetsDialog)))
		return 1;   // dialog is not valid
	dialog->runnable()->run();
	dialog->clean_up_example();
	::AfxEndThread(0, TRUE); // Terminate and delete the thread.
	return 0L;
}



void ExampleSnippetsDialog::clean_up_example()
{
	m_runnable->disconnect(m_text_out_connection);
	write_text_out(L"\nFinished.");
	// Wait for the finish of text output to be signaled:
	::WaitForSingleObject(m_text_out_finished->m_hObject, INFINITE);
	m_text_out_finished->ResetEvent();
	delete m_text_out_stream; m_text_out_stream = nullptr;
	delete m_runnable; m_runnable = nullptr;
	m_pThread = nullptr; // Thread will delete itself.
}



void ExampleSnippetsDialog::run_example(Abstract_Base::Runnable_Example *runnable)
{
	ASSERT(m_runnable == nullptr);
	ASSERT(m_pThread == nullptr);
	ASSERT(m_text_out_stream == nullptr);
	//ASSERT(more_text_out == false);
	ASSERT(runnable != nullptr);
	m_runnable = runnable;
	m_text_out_stream = new std::wostringstream;
	m_text_out_connection = m_runnable->connect(boost::bind(&ExampleSnippetsDialog::write_text_out, this, _1));
	m_pThread = AfxBeginThread(&run_example_thread_proc, this);
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

	// Grab the ID of the UI thread:
	m_ui_thread_id = GetCurrentThreadId();

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
