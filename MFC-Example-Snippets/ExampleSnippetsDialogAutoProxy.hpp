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
class ExampleSnippetsDialog;


class ExampleSnippetsDialogAutoProxy : public CCmdTarget
{

protected: // Ctors et al -----------------------------------------------------

    ExampleSnippetsDialogAutoProxy();
    virtual ~ExampleSnippetsDialogAutoProxy();
    DECLARE_DYNCREATE(ExampleSnippetsDialogAutoProxy)

    public: // State --------------------------------------------------------------

    ExampleSnippetsDialog* m_pDialog;

public: // Overrides ----------------------------------------------------------

    void OnFinalRelease() override;

public: // Messages -----------------------------------------------------------

    DECLARE_MESSAGE_MAP();
    DECLARE_OLECREATE(ExampleSnippetsDialogAutoProxy);
    DECLARE_DISPATCH_MAP();
    DECLARE_INTERFACE_MAP();
};
