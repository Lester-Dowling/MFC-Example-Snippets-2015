#include "pch-MFC-Example-Snippets.hpp"
#include "TheApp.hpp"
#include "ExampleSnippetsDialog.hpp"
#include "ExampleSnippetsDialogAutoProxy.hpp"
#include "AboutDlg.hpp"
#include "Examples/_CEvent/Trivial_Usage.hpp"
#include "Examples/_CEvent/Calculate_Prime_Numbers.hpp"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNAMIC(ExampleSnippetsDialog, CDHtmlDialog);


BEGIN_MESSAGE_MAP(ExampleSnippetsDialog, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
END_MESSAGE_MAP();


BEGIN_DHTML_EVENT_MAP(ExampleSnippetsDialog)
	DHTML_EVENT_ONCLICK(L"Examples::_CEvent::Trivial_Usage", On_CEvent_Trivial_Usage)
	DHTML_EVENT_ONCLICK(L"Examples::_CEvent::Calculate_Prime_Numbers", On_CEvent_Calculate_Prime_Numbers)
	DHTML_EVENT_ONCLICK(L"ButtonCancel", OnButtonCancel)
END_DHTML_EVENT_MAP();



void ExampleSnippetsDialog::write_text_out(std::wstring text_out)
{
	*m_text_out_stream << "<p>" << text_out << "</p>" << std::endl;
	write_text_out_stream();
}



void ExampleSnippetsDialog::write_text_out_stream()
{

	IHTMLElement* pElement = NULL;
	if (GetElement(_T("text-out"), &pElement) == S_OK && pElement != NULL)
	{
		// Get element html
		BSTR html = SysAllocString(_T(""));
		// pElement->get_outerHTML(&html);
		pElement->get_innerHTML(&html);

		// Update element html
		//CString updatedHTML;
		// updatedHTML.Format(_T("<div ID=\"text-out\" >&nbsp; %s </div>"), _T("Okay, done."));
		//updatedHTML.Format(L"&nbsp; %s", L"Okay, all done.");
		BSTR updatedHTML = ::SysAllocString(m_text_out_stream->str().c_str());
		pElement->put_innerHTML(updatedHTML);

	}
}



HRESULT ExampleSnippetsDialog::On_CEvent_Trivial_Usage(IHTMLElement*)
{
	m_text_out_stream = new std::wostringstream;
	Examples::_CEvent::Trivial_Usage example;
	m_text_out_connection = example.connect(boost::bind(&ExampleSnippetsDialog::write_text_out, this, _1));

	example.run();

	*m_text_out_stream << "<p>Finished: " << __FUNCTION__ << "</p>"; write_text_out_stream();
	example.disconnect(m_text_out_connection);
	delete m_text_out_stream; m_text_out_stream = nullptr;
	return S_OK;
}



HRESULT ExampleSnippetsDialog::On_CEvent_Calculate_Prime_Numbers(IHTMLElement*)
{
	m_text_out_stream = new std::wostringstream;
	Examples::_CEvent::Calculate_Prime_Numbers example{ m_text_out_stream };
	m_text_out_connection = example.connect(boost::bind(&ExampleSnippetsDialog::write_text_out, this, _1));

	example.run();

	*m_text_out_stream << "<p>Finished: " << __FUNCTION__ << "</p>"; write_text_out_stream();
	example.disconnect(m_text_out_connection);
	delete m_text_out_stream; m_text_out_stream = nullptr;
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

	// TODO: Add extra initialization here

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
