
// ExampleCodeDialog.hpp : header file
//

#pragma once

class ExampleCodeDialogAutoProxy;


// ExampleCodeDialog dialog
class ExampleCodeDialog : public CDHtmlDialog
{
	DECLARE_DYNAMIC(ExampleCodeDialog);
	friend class ExampleCodeDialogAutoProxy;

// Construction
public:
	ExampleCodeDialog(CWnd* pParent = NULL);	// standard constructor
	virtual ~ExampleCodeDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCEXAMPLECODE_DIALOG, IDH = IDR_HTML_MFCEXAMPLECODE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// Implementation
protected:
	ExampleCodeDialogAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
};
