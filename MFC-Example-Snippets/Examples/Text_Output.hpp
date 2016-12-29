#pragma once
#include <string>
#include <boost/signals2.hpp>

namespace Examples {

	/**
	 *  A typedef for the signal to emit text output from an example.
	 */
	typedef boost::signals2::signal<void(std::wstring)> text_output_signal_t;

	/**
	 *  The type of function which responds to the text output signal.
	 */
	typedef text_output_signal_t::slot_function_type text_output_slot_t;

}
