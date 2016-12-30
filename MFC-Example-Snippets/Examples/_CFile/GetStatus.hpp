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

    namespace _CFile {

        /**
         *  Examples::_CFile::GetStatus
         *
         *  Copied from:
         *      https://msdn.microsoft.com/en-us/library/60fh2b6f.aspx
         *
         */
        class GetStatus : public Interface::Runnable
        {

        public: // Overrides ----------------------------------------------------------

            /**
             *  Run the example.
             */
            void run() override;

        };
    }
}
