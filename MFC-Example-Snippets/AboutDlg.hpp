#pragma once
#include <afxwin.h>
#include <afxstr.h>
#include <afxdialogex.h>
#undef min
#undef max
#include "Resource.h"

class AboutDlg : public CDialogEx
{

public: // Ctors et al --------------------------------------------------------

    AboutDlg();

    enum { IDD = IDD_ABOUTBOX };

public: // Overrides ----------------------------------------------------------

    void DoDataExchange(CDataExchange* pDX) override;

public: // Messages -----------------------------------------------------------

    DECLARE_MESSAGE_MAP();
};
