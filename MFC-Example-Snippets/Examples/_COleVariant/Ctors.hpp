#pragma once
#include "targetver.h"
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>
#include <atlbase.h>
#include <atlstr.h>
#undef min
#undef max
#include <cstddef>
#include <cstdint>
#include <string>
#include "ABC/Runnable.hpp"

namespace Examples {

    namespace _COleVariant {

        /**
         *  Examples::_COleVariant::Ctors
         *
         *  Inspired by:
         *      https://msdn.microsoft.com/en-us/library/4xd0wkhw.aspx
         *
         */
        class Ctors : public ABC::Runnable
        {

        public: // Overrides ----------------------------------------------------------

            /**
             *  Run the example.
             */
            void run() override;

        };
    }
}
