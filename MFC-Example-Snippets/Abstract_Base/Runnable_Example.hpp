#pragma once
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>
#include <string>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

/**
 *  Namespace Abstract_Base is for abstract base classes.
 */
namespace Abstract_Base {

	/**
	 *  Abstract_Base::Runnable_Example
	 *
	 *  Abstract base class for runnable examples.
	 */
    class Runnable_Example : public CObject
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
        virtual ~Runnable_Example() {}
    };
}

/**
 *  A convenient macro for text output in classes derived from Abstract_Base::Runnable_Example.
 */
#define TEXT_OUT(msg)                           \
    do {                                        \
        std::wostringstream oss;                \
        oss << msg;                             \
        m_text_output(oss.str());               \
    } while(false)

/**
 *  Text output of an blank line.
 */
#define TEXT_OUT_BLANKLINE                      \
    do {                                        \
        std::wostringstream oss;                \
        oss << std::endl;                       \
        m_text_output(oss.str());               \
    } while(false)
