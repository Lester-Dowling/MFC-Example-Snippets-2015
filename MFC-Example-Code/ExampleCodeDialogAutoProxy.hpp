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
class ExampleCodeDialog;


class ExampleCodeDialogAutoProxy : public CCmdTarget
{

protected: // Ctors et al -----------------------------------------------------

	ExampleCodeDialogAutoProxy();
	virtual ~ExampleCodeDialogAutoProxy();
	DECLARE_DYNCREATE(ExampleCodeDialogAutoProxy)

public: // State --------------------------------------------------------------

	ExampleCodeDialog* m_pDialog;

public: // Overrides ----------------------------------------------------------

	void OnFinalRelease() override;

public: // Messages -----------------------------------------------------------

	DECLARE_MESSAGE_MAP();
	DECLARE_OLECREATE(ExampleCodeDialogAutoProxy);
	DECLARE_DISPATCH_MAP();
	DECLARE_INTERFACE_MAP();
};

