// OptionException.hpp
// Defines the OptionException Abstract class

#ifndef OPTION_EXCEPTION_HPP_
#define OPTION_EXCEPTION_HPP_

#include <string>
#include <iostream>

namespace OPTIONPRICING
{
	namespace EXCEPTIONS
	{
		class OptionException {
		private:
		public:
			OptionException();												// Default Constructor
			OptionException(const OptionException& source);					// Copy Constructor
			virtual ~OptionException();										// Desctructor
			OptionException& operator = (const OptionException& source);	// Assignment Operator

			virtual std::string GetMessage() = 0;							// Abstract GetMessage function
		};
	}
}

#endif