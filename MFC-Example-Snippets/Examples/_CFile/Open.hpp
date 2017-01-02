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
#include "Abstract_Base/Runnable.hpp"

namespace Examples {

	namespace _CFile {

		/**
		 *  Examples::_CFile::Open
		 *
		 *  Copied from:
		 *      https://msdn.microsoft.com/en-us/library/60fh2b6f.aspx
		 *
		 */
		class Open : public Abstract_Base::Runnable
		{

		public: // HTML -------------------------------------------------------

			/**
			 *  Examples::_CFile::Open::id()
			 *
			 *  A tag for ID elements.
			 */
			static const wchar_t* id() { return L"Examples::_CFile::Open"; }

			/**
			 *  Examples::_CFile::Open::ds()
			 *
			 *  A short descriptive label.
			 */
			static const wchar_t* ds() { return L"Open File Read-only"; }

		public: // Overrides ----------------------------------------------------------

			/**
			 *  Run the example.
			 */
			void run() override;

		};
	}
}
