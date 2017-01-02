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
		 *  Examples::_CFile::GetStatus
		 *
		 *  Copied from:
		 *      https://msdn.microsoft.com/en-us/library/60fh2b6f.aspx
		 *
		 */
		class GetStatus : public Abstract_Base::Runnable
		{

		public: // HTML -------------------------------------------------------

			/**
			 *  Examples::_CFile::GetStatus::id()
			 *
			 *  A tag for ID elements.
			 */
			static const wchar_t* id() { return L"Examples::_CFile::GetStatus"; }

			/**
			 *  Examples::_CFile::GetStatus::ds()
			 *
			 *  A short descriptive label.
			 */
			static const wchar_t* ds() { return L"Get File Status"; }

		public: // Overrides ----------------------------------------------------------

			/**
			 *  Run the example.
			 */
			void run() override;

		};
	}
}
