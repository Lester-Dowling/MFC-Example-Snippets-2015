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
#include <vector>
#include <boost/signals2.hpp>
#include "Abstract_Base/Runnable_Example.hpp"
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
    void impose_examples_menu();
    void OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl) override;
    void OnCancel() override;
    const DHtmlEventMapEntry* GetDHtmlEventMap() override;

protected: // Events ----------------------------------------------------------

    HRESULT On_Main_Menu(IHTMLElement*);
    HRESULT OnButtonCancel(IHTMLElement*);
    HRESULT On_Run_Example(IHTMLElement*);
    HRESULT On_Change_Class_Example(IHTMLElement * pElement);

    /**
     *  The name of the current menu displayed to the user.
     */
    std::wstring m_curr_menu_name{ L"main menu" };

    /**
     *  Listing of examples and they're grouped by class name:
     *
     *      class name --> vector of (element_id, button_label)
     */
    typedef std::pair<const wchar_t*, const wchar_t*> element_id_and_button_label;
    typedef std::vector<element_id_and_button_label> class_examples_t;
    typedef std::map<std::wstring, class_examples_t> examples_map_t;
    examples_map_t m_examples;

    /**
     *  Load all examples into the examples map.
     */
    void register_all_examples();

    /**
     *  The event map of HTML element ids onto event handlers.
     */
    std::vector<DHtmlEventMapEntry> m_dhtmlEventEntries;

    /**
     *  Assign the given handler to respond to clicks on elements with the given id.
     */
    void add_dhtml_event_onclick(const wchar_t *element_id, HRESULT(ExampleSnippetsDialog::*handler)(IHTMLElement*));

    /**
     *  The event map requires a sentinel value placed at the end position.
     */
    void append_dhtml_event_sentinel();

    /**
     *  Remove all dhtml events except for important events.
     */
    void clear_dhtml_events();

    /**
     *  Make a button to run an example.
     */
    std::wstring make_run_example_button(const wchar_t * button_id, const std::wstring& button_label);

    /**
     *  Make a button to change the examples menu to a different example class.
     */
    std::wstring make_class_example_button(const wchar_t * element_id, const std::wstring& button_label);

    std::wstring make_main_menu_button();

public: // Accessors ----------------------------------------------------------

    Abstract_Base::Runnable_Example * runnable() const { return m_runnable; }
    void clean_up_example();

protected: // Implementation --------------------------------------------------

    /**
     *  Running the example
     */
    Abstract_Base::Runnable_Example *m_runnable = nullptr;
    CWinThread *m_pThread = nullptr;
    void run_example(Abstract_Base::Runnable_Example *runnable);


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
    enum class MSG : UINT { more_text_out = WM_APP };
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

    afx_msg LRESULT On_More_Text_Out(WPARAM wParam, LPARAM lParam);
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnClose();
    DECLARE_MESSAGE_MAP();
};
