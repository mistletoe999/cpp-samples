// OptionException.cpp
// Implements the Option Exception class

#include "OptionException.hpp"

namespace OPTIONPRICING
{
	namespace EXCEPTIONS
	{
		OptionException::OptionException() {} // Default Constructor

		OptionException::OptionException(const OptionException& OptionException) {} // Copy Constructor

		OptionException::~OptionException() {} // Destructor

		// No member data, so nothing to assign in the assignment operator (as in Copy Constructor)	

	}
}

