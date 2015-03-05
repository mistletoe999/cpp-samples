// InvalidOptionException.hpp
// Defines the InvalidOptionException class derived from OptionException
// The exception is thrown when the option type is not
// among the types defined in OPTIONPRICING::OptionType enum type

#ifndef INVALID_OPTION_EXCEPTION_HPP_
#define INVALID_OPTION_EXCEPTION_HPP_

#include "OptionException.hpp"
#include <iostream>
#include <string>

namespace OPTIONPRICING
{
	namespace EXCEPTIONS
	{
		class InvalidOptionException : public OptionException
		{
		private:
			int m_index;
		public:
			InvalidOptionException();			// Default Constructor
			InvalidOptionException(const int index);	// Constructor with index value
			InvalidOptionException(const InvalidOptionException& source);	// Copy Constructor

			virtual ~InvalidOptionException();			// Destructor

			InvalidOptionException& operator = (const InvalidOptionException& source);	// Assignment Operator
			std::string GetMessage();		// Displays the exception message
		};
	}
}

#endif //INVALID_OPTION_EXCEPTION_HPP_
