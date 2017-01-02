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
#include "Abstract_Base/Runnable_Example.hpp"
#include "CRuntimeClass-Support.hpp"

namespace Examples {

	namespace _COleVariant {

		/**
		 *  Examples::_COleVariant::Ctors
		 *
		 *  Inspired by:
		 *      https://msdn.microsoft.com/en-us/library/4xd0wkhw.aspx
		 *
		 */
		class Ctors : public Abstract_Base::Runnable_Example
		{
			DECLARE_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE;

		public: // HTML -------------------------------------------------------

			/**
			 *  Examples::_COleVariant::Ctors::ds()
			 *
			 *  A short descriptive label.
			 */
			static const wchar_t* ds() { return L"Constructors"; }

		public: // Overrides ----------------------------------------------------------

			/**
			 *  Run the example.
			 */
			void run() override;

		};
	}
}
