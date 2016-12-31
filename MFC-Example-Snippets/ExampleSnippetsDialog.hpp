#pragma once
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>
#include <atlbase.h>
#include <atlstr.h>
#include <afxdisp.h>
#include <afxdtctl.h>
#include <afxdialogex.h>
#include <afxdhtml.h>
#undef min
#undef max
#include <string>
#include <boost/signals2.hpp>
#include "Interface/Runnable.hpp"
#include "Resource.h"
class ExampleSnippetsDialogAutoProxy;


class ExampleSnippetsDialog : public CDHtmlDialog
{
	friend class ExampleSnippetsDialogAutoProxy;

public: // Ctors et al --------------------------------------------------------

	ExampleSnippetsDialog(CWnd* pParent = nullptr);
	virtual ~ExampleSnippetsDialog();
	DECLARE_DYNAMIC(ExampleSnippetsDialog);

	enum { IDD = IDD_MFCEXAMPLECODE_DIALOG, IDH = IDR_HTML_MFCEXAMPLECODE_DIALOG };

protected: // Overrides -------------------------------------------------------

	void DoDataExchange(CDataExchange* pDX) override;
	BOOL OnInitDialog() override;
	void OnCancel() override;


protected: // Events ----------------------------------------------------------

	HRESULT OnButtonCancel(IHTMLElement*);
	HRESULT On_CEvent_Trivial_Usage(IHTMLElement*);
	HRESULT On_CEvent_Calculate_Prime_Numbers(IHTMLElement*);
	HRESULT On_CFile_Open(IHTMLElement*);
	HRESULT On_CFile_Write(IHTMLElement*);
	HRESULT On_CFile_GetStatus(IHTMLElement*);
	HRESULT On_CFile_SetFilePath(IHTMLElement*);
	HRESULT On_CFile_GetLength(IHTMLElement*);

public: // Accessors ----------------------------------------------------------

	Interface::Runnable * runnable() const { return m_runnable; }
	void clean_up_example();

protected: // Implementation --------------------------------------------------

	/**
	 *  Running the example
	 */
	Interface::Runnable *m_runnable = nullptr;
	CWinThread *m_pThread = nullptr;
	void run_example(Interface::Runnable *runnable);


	ExampleSnippetsDialogAutoProxy* m_pAutoProxy = nullptr;
	HICON m_hIcon;
	BOOL CanExit();

	/**
	 *  The text stream which is written to the output pane.
	 */
	std::wostringstream *m_text_out_stream = nullptr;

	/**
	 *  Coordination of text output.
	 */
	enum class MSG : UINT { more_text_out = WM_USER };
	DWORD m_ui_thread_id = 0;
	const BOOL bInitiallyOwn = FALSE;
	const BOOL bManualReset = TRUE;
	std::unique_ptr<CEvent> m_text_out_finished{ new CEvent(bInitiallyOwn, bManualReset) };
	//bool more_text_out = false;
	CMutex m_text_out_mutex;

	/**
	 *  The signal connection to collect text output from examples.
	 */
	boost::signals2::connection  m_text_out_connection;

	/**
	 *  Slot which signal from examples connects to.  This slot runs on a worker
	 *  thread, and not the UI thread.
	 */
	/*slot*/ void write_text_out(std::wstring text_out);

public: // Messages -----------------------------------------------------------

	afx_msg LRESULT OnMoreTextOut(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP();
	DECLARE_DHTML_EVENT_MAP()
};
