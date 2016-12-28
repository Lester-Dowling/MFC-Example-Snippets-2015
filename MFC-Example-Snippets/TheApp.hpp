#pragma once
#include "targetver.h"
#include <cstddef>
#include <cstdint>
#include <tchar.h>
#include <afx.h>
#include <afxwin.h>
#include <afxdisp.h>
#include <afxwinappex.h>
#undef min
#undef max

class TheApp : public CWinApp
{
public:

    TheApp() {}

public: // Overrides ----------------------------------------------------------

    BOOL InitInstance() override;
    int ExitInstance() override;

public: // Messages -----------------------------------------------------------

    DECLARE_MESSAGE_MAP();
};

extern TheApp theApp;
