#pragma once
#include "targetver.h"
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>
#include <atlbase.h>
#include <atlstr.h>
#include <afxdisp.h>
#undef min
#undef max
#include <cstddef>
#include <cstdint>
#include "Abstract_Base/Runnable_Example.hpp"

#define DECLARE_RUNTIME_CLASS                           \
    public:                                             \
    static CRuntimeClass* __stdcall _GetBaseClass();    \
    static CRuntimeClass* GetThisClass();               \
    static CObject* __stdcall CreateObject();           \
    CRuntimeClass* GetRuntimeClass() const override;



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
        class Trivial_Usage : public Abstract_Base::Runnable_Example
        {
            DECLARE_RUNTIME_CLASS;

        public: // HTML -------------------------------------------------------

            /**
             *  Examples::_CEvent::Trivial_Usage::id()
             *
             *  An unique symbol for ID attributes.
             */
            static const wchar_t* id() { return L"Examples::_CEvent::Trivial_Usage"; }

            /**
             *  Examples::_CEvent::Trivial_Usage::ds()
             *
             *  A short descriptive label.
             */
            static const wchar_t* ds() { return L"Trivial Usage"; }

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
