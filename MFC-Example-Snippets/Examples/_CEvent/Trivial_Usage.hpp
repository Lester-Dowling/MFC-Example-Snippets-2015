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
#include <boost/signals2.hpp>
#include <boost/bind.hpp>
#include "Examples/Text_Output.hpp"

namespace Examples {

	namespace _CEvent {

		/**
		 *  Examples::_CEvent::Trivial_Usage
		 *
		 *  Copied from:
		 *      https://msdn.microsoft.com/en-us/library/efk30beh.aspx
		 *
		 *  The following demonstrates trivial usage of the CEvent class.
		 *  A CEvent object is created and passed as a parameter to another
		 *  thread.  The other thread will wait for the event to be signaled
		 *  and then exit
		 */
		class Trivial_Usage
		{

		public: // Methods ----------------------------------------------------

			/**
			 *  Examples::Trivial_Usage::MyThreadProc
			 */
			static UINT __cdecl MyThreadProc(LPVOID lpParameter);


			/**
			 *  Examples::Trivial_Usage::run
			 *
			 *  Run the example.
			 */
			void run();


		private: // Text Output Signal ----------------------------------------

			typedef boost::signals2::connection connection_t;
			Examples::text_output_signal_t m_text_output;

		public: // Text Output Signal Connection Methods ----------------------

			connection_t connect(Examples::text_output_slot_t subscriber)
			{
				return m_text_output.connect(subscriber);
			}


			void disconnect(connection_t subscriber)
			{
				subscriber.disconnect();
			}

		};
	}
}
