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
#include "Interface/Runnable.hpp"

namespace Examples {

    namespace _CEvent {

        /**
         *  Examples::_CEvent::Trivial_Usage
         *
         *  Copied from:
         *      https://msdn.microsoft.com/en-us/library/efk30beh.aspx
         *
         *  The following demonstrates trivial usage of the CEvent class.
         *  A CEvent object is created and passed as a parameter to another
         *  thread.  The other thread will wait for the event to be signaled
         *  and then exit
         */
        class Trivial_Usage : public Interface::Runnable
        {

        public: // Methods ----------------------------------------------------

            /**
             *  Controlling thread proc for the example.
             */
            static UINT __cdecl MyThreadProc(LPVOID lpParameter);

        public: // Overrides --------------------------------------------------

            /**
             *  Run the example.
             */
            void run() override;

        };
    }
}
