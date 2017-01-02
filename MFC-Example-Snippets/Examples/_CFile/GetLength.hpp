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

	namespace _CFile {

		/**
		 *  Examples::_CFile::GetLength
		 *
		 *  Copied from:
		 *      https://msdn.microsoft.com/en-us/library/60fh2b6f.aspx
		 *
		 */
		class GetLength : public Abstract_Base::Runnable_Example
		{
			DECLARE_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE;

		public: // HTML -------------------------------------------------------

			/**
			 *  Examples::_CFile::GetLength::ds()
			 *
			 *  A short descriptive label.
			 */
			static const wchar_t* ds() { return L"Get Length of File"; }

		public: // Overrides ----------------------------------------------------------

			/**
			 *  Run the example.
			 */
			void run() override;

		};
	}
}
