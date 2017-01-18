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
    namespace _CArray {

        /**
         *  Examples::_CArray::InsertAt
         *
         *  Copied from:
         *
         *
         */
        class InsertAt : public Abstract_Base::Runnable_Example
        {
            DECLARE_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE;

        public: // HTML -------------------------------------------------------

            /**
             *  Examples::_CArray::InsertAt::ds()
             *
             *  A short descriptive label.
             */
            static const wchar_t* ds() { return L"Insert Elements"; }

        public: // Overrides ----------------------------------------------------------

            /**
             *  Run the example.
             */
            void run() override;

        };
    }
}
