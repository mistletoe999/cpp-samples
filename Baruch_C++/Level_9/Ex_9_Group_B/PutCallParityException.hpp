// PutCallParityException.hpp
// Defines the PutCallParityException class derived from
// OptionException abstract class

#ifndef PUT_CALL_PARITY_EXCEPTION_HPP_
#define PUT_CALL_PARITY_EXCEPTION_HPP_

#include "OptionException.hpp"

namespace OPTIONPRICING
{
	namespace EXCEPTIONS
	{
		class PutCallParityException : public OptionException
		{
		private:
			int m_index;
		public:
			PutCallParityException();			// Default Constructor
			PutCallParityException(const int index);	// Constructor with index value
			PutCallParityException(const PutCallParityException& source);	// Copy Constructor

			virtual ~PutCallParityException();			// Destructor

			PutCallParityException& operator = (const PutCallParityException& source);	// Assignment Operator
			std::string GetMessage();		// Displays the exception message
		};
	}
}

#endif