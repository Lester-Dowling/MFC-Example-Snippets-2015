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
         *  Examples::_CEvent::Calculate_Prime_Numbers
         *
         *  Copied from:
         *      https://msdn.microsoft.com/en-us/library/efk30beh.aspx
         *
         *  This example builds upon the previous one.  A second thread is
         *  created to calculate prime numbers.  The main thread will signal
         *  the second thread to calulate the next prime number in the
         *  series.  The second thread signals the first after each number is
         *  calculated. Finally, after several iterations the worker thread
         *  is signaled to terminate.
         */
        class Calculate_Prime_Numbers
        {

        public: // Ctors et al ------------------------------------------------

            Calculate_Prime_Numbers(std::wostringstream *text_out_stream);

            ~Calculate_Prime_Numbers();

        public: // Methods ----------------------------------------------------

            /**
             *  Examples::Calculate_Prime_Numbers::run
             *
             *  Run the example.
             */
            void run();

        private: // Implementation --------------------------------------------

            /**
             *  Determines whether the given number is a prime number.
             */
            static BOOL IsPrime(INT ThisPrime);

            /**
             *  Calculates the next prime number in the series.
             */
            static INT NextPrime(INT ThisPrime);

            /**
             *  Worker thread responsible for calculating the next prime
             *  number in the series.
             */
            static UINT __cdecl PrimeCalcProc(LPVOID lpParameter);

        private: // State -----------------------------------------------------

            /**
             *  Notifies worker thread to calculate next prime.
             */
            CEvent* m_pCalcNext;

            /**
             *  Notifies main thread current calculation is complete.
             */
            CEvent* m_pCalcFinished;

            /**
             *  Notifies worker thread to terminate.
             */
            CEvent* m_pTerminateThread;

            /**
             *  Current calculated prime number.
             */
            INT m_iCurrentPrime;

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
