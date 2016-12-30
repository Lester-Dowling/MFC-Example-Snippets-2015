#pragma once
#include <string>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>


namespace Interface {

    class Runnable
    {
    public: // Methods --------------------------------------------------------

        virtual void run() = 0;


    protected: // Text Output Signal ------------------------------------------

        typedef boost::signals2::signal<void(std::wstring)> text_output_signal_t;

        /**
         *  The type of function which responds to the text output signal.
         */
        typedef text_output_signal_t::slot_function_type text_output_slot_t;

        /**
         *  The signal to send text to output.
         */
        text_output_signal_t m_text_output;

    public: // Text Output Signal Connection Methods --------------------------

        virtual boost::signals2::connection connect(text_output_slot_t subscriber)
        {
            return m_text_output.connect(subscriber);
        }


        virtual void disconnect(boost::signals2::connection& subscriber)
        {
            subscriber.disconnect();
        }


	public: // ----------------------------------------------------------------
        virtual ~Runnable() {}
    };
}
