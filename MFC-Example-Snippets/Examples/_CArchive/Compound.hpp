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
		 *  Examples::_CArchive::Compound
		 *
		 *  Copied from:
		 *
		 *  Serializing an Object:
		 *  
		 *  Storing and Loading CObjects via an Archive
		 *
		 */
		class Compound : public Abstract_Base::Runnable_Example
		{
			DECLARE_CRUNTIMECLASS_SUPPORT_DYNAMIC_CREATE;

		public: // HTML -------------------------------------------------------

			/**
			 *  Examples::_CArchive::Compound::ds()
			 *
			 *  A short descriptive label.
			 */
			static const wchar_t* ds() { return L"Compound Part"; }

		public: // Overrides ----------------------------------------------------------

			/**
			 *  Run the example.
			 */
			void run() override;

		};
	}
}
