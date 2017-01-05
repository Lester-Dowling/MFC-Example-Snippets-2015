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
#include "CRuntimeClass-Support.hpp"

namespace Examples {

    namespace _CArchive {

        /**
         *  Examples::_CArchive::Store_and_Load
         *
         *  Copied from:
         *
         *
         */
        class Store_and_Load : public Abstract_Base::Runnable_Example
        {
            DECLARE_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE;

        public: // HTML -------------------------------------------------------

            /**
             *  Examples::_CArchive::Store_and_Load::ds()
             *
             *  A short descriptive label.
             */
            static const wchar_t* ds() { return L"Store and Load"; }

        public: // Overrides ----------------------------------------------------------

            /**
             *  Run the example.
             */
            void run() override;

        };
    }
}
