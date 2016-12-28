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
class ExampleCodeDialogAutoProxy;


class ExampleCodeDialog : public CDHtmlDialog
{
	friend class ExampleCodeDialogAutoProxy;

public: // Ctors et al --------------------------------------------------------

	ExampleCodeDialog(CWnd* pParent = nullptr);
	virtual ~ExampleCodeDialog();
	DECLARE_DYNAMIC(ExampleCodeDialog);

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

	ExampleCodeDialogAutoProxy* m_pAutoProxy;
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
