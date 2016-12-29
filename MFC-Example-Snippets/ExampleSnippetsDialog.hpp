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
#include <boost/bind.hpp>
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

	HRESULT On_CEvent_Trivial_Usage(IHTMLElement *pElement);
	HRESULT On_CEvent_Calculate_Prime_Numbers(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

protected: // Implementation --------------------------------------------------

	BOOL CanExit();
	ExampleSnippetsDialogAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	/**
	 *  The text stream which is written to the output pane.
	 */
	std::wostringstream *m_text_out_stream;
	void write_text_out_stream();

	/**
	 *  The slot to collect text output from examples.
	 */
	boost::signals2::connection  m_text_out_connection;
	/*slot*/ void write_text_out(std::wstring text_out);

public: // Messages -----------------------------------------------------------

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP();
	DECLARE_DHTML_EVENT_MAP()
};
