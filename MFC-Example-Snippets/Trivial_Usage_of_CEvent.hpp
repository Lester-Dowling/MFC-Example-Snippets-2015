#pragma once
#include "targetver.h"
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>
#include <atlbase.h>
#include <atlstr.h>
#include <afxdisp.h>
#include <afxdialogex.h>
#include <afxdhtml.h>
#undef min
#undef max
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include <iostream>

namespace Example {

    /**
     *  Example::Trivial_Usage_of_CEvent
     *
     *  Copied from:
     *      https://msdn.microsoft.com/en-us/library/efk30beh.aspx
     *
     */
    class Trivial_Usage_of_CEvent
    {

    public:

        // The following demonstrates trivial usage of the CEvent class.
        // A CEvent object is created and passed as a parameter to another
        // thread.  The other thread will wait for the event to be signaled
        // and then exit

        /**
         *  Example::Trivial_Usage_of_CEvent::MyThreadProc
         */
        static UINT __cdecl MyThreadProc(LPVOID lpParameter);


        /**
         *  Example::Trivial_Usage_of_CEvent::run
         *
         *  Run the CEvent test.
         */
        static void run();

    };
}
