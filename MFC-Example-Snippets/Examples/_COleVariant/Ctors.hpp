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
#include "Abstract_Base/Runnable.hpp"

namespace Examples {

	namespace _COleVariant {

		/**
		 *  Examples::_COleVariant::Ctors
		 *
		 *  Inspired by:
		 *      https://msdn.microsoft.com/en-us/library/4xd0wkhw.aspx
		 *
		 */
		class Ctors : public Abstract_Base::Runnable
		{

		public: // HTML -------------------------------------------------------

			/**
			 *  Examples::_COleVariant::Ctors::id()
			 *
			 *  A tag for ID elements.
			 */
			static const wchar_t* id() { return L"Examples::_COleVariant::Ctors"; }

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
