#pragma once
#include "targetver.h"

#include <afx.h>                            // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afx.h
#include <afxwin.h>                         // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxwin.h
#include <afxext.h>                         // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxext.h
#include <atlbase.h>                        // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\atlbase.h
#include <atlstr.h>                         // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\atlstr.h
#include <afxdisp.h>                        // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdisp.h
#include <afxdtctl.h>                       // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdtctl.h
#include <afxcmn.h>                         // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxcmn.h
#include <afxcontrolbars.h>                 // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxcontrolbars.h
#include <afxsock.h>                        // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxsock.h
#include <afxdialogex.h>                    // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdialogex.h
#include <afxdhtml.h>                       // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\include\afxdhtml.h

#include <WindowsX.h>                       // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\shared\windowsx.h
#include <strsafe.h>                        // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\shared\strsafe.h
#include <combaseapi.h>                     // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\um\combaseapi.h
#include <CommDlg.h>                        // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\um\commdlg.h
#include <Stringapiset.h>                   // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\um\stringapiset.h
#include <xpsobjectmodel_1.h>               // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\um\xpsobjectmodel_1.h
#include <DocumentTarget.h>                 // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\um\DocumentTarget.h
#include <wininet.h>                        // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\um\WinInet.h

#ifndef NDEBUG
#include <crtdbg.h>                         // C:\Program Files (x86)\Windows Kits\10\Include\10.0.14393.0\ucrt\crtdbg.h
#endif
#undef min
#undef max

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#include <cassert>                          // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\cassert
#include <cstddef>                          // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\cstddef
#include <cstdint>                          // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\cstdint
#include <ctime>                            // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\ctime
#include <cstdio>                           // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\cstdio
#include <cstdlib>                          // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\cstdlib

#include <string>                           // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\string
#include <functional>                       // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\functional
#include <algorithm>                        // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\algorithm
#include <new>                              // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\new
#include <memory>                           // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\memory
#include <vector>                           // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\vector
#include <stdexcept>                        // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\stdexcept
#include <iostream>                         // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\iostream
#include <sstream>                          // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\sstream
#include <limits>                           // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\limits
#include <iterator>                         // C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\iterator
#include <initializer_list>					// C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\initializer_list
#include <boost/signals2.hpp>				// C:\boost_MSVC_2015_x64\include\boost-1_62\boost\signals2.hpp
#include <boost/bind.hpp>					// C:\boost_MSVC_2015_x64\include\boost-1_62\boost\bind.hpp


template <class Interface>
inline void SafeRelease(Interface** interfaceToRelease)
{
    if (*interfaceToRelease != nullptr)
        {
            (*interfaceToRelease)->Release();

            (*interfaceToRelease) = nullptr;
        }
}

// This macro is the same as IMPLEMENT_OLECREATE, except it passes TRUE
// for the bMultiInstance parameter to the COleObjectFactory constructor.
// We want a separate instance of this application to be launched for
// each automation proxy object requested by automation controllers.
#ifndef IMPLEMENT_OLECREATE2
#define IMPLEMENT_OLECREATE2(class_name, external_name, app_clsid)      \
    const AFX_DATADEF GUID class_name::guid = app_clsid;                \
    AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
        RUNTIME_CLASS(class_name), TRUE, _T(external_name));
#endif // IMPLEMENT_OLECREATE2
