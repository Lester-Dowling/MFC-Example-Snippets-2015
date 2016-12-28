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
    void OnOK() override;
    void OnCancel() override;

protected: // Events ----------------------------------------------------------

    HRESULT On_Trivial_Usage_of_CEvent(IHTMLElement *pElement);
    HRESULT On_Calculate_Prime_Numbers_via_CEvent(IHTMLElement *pElement);
    HRESULT OnButtonCancel(IHTMLElement *pElement);

protected: // Implementation --------------------------------------------------

    ExampleSnippetsDialogAutoProxy* m_pAutoProxy;
    HICON m_hIcon;
    BOOL CanExit();

public: // Messages -----------------------------------------------------------

    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnClose();
    DECLARE_MESSAGE_MAP();
    DECLARE_DHTML_EVENT_MAP()
};
