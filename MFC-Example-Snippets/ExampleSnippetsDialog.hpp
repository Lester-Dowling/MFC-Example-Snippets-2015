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


    HRESULT On_CEvent_Trivial_Usage(IHTMLElement *pElement);
    HRESULT On_CEvent_Calculate_Prime_Numbers(IHTMLElement *pElement);
    HRESULT OnButtonCancel(IHTMLElement *pElement);

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
    bool more_text_out = false;
	CMutex m_text_out_mutex;

    UINT_PTR text_out_timer = 1;
    void write_text_out_stream();

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

    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnClose();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    DECLARE_MESSAGE_MAP();
    DECLARE_DHTML_EVENT_MAP()
};
