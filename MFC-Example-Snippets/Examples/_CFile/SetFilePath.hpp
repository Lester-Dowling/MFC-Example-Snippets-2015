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
		 *  Examples::_CFile::SetFilePath
		 *
		 *  Copied from:
		 *      https://msdn.microsoft.com/en-us/library/60fh2b6f.aspx
		 *
		 */
		class SetFilePath : public Abstract_Base::Runnable
		{

		public: // HTML -------------------------------------------------------

			/**
			 *  Examples::_CFile::SetFilePath::id()
			 *
			 *  A tag for ID elements.
			 */
			static const wchar_t* id() { return L"Examples::_CFile::SetFilePath"; }

			/**
			 *  Examples::_CFile::SetFilePath::ds()
			 *
			 *  A short descriptive label.
			 */
			static const wchar_t* ds() { return L"Set File Path"; }

		public: // Overrides ----------------------------------------------------------

			/**
			 *  Run the example.
			 */
			void run() override;

		};
	}
}
