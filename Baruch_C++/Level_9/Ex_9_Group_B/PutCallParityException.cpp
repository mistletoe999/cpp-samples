// PutCallParityException.cpp
// Implements the PutCallParityException class
// defined in PutCallParityException.hpp

#include "PutCallParityException.hpp"

namespace OPTIONPRICING
{
	namespace EXCEPTIONS
	{
		// Default Constructor
		PutCallParityException::PutCallParityException() : OptionException(), m_index(-1) {}

		// Constructor with index
		PutCallParityException::PutCallParityException(const int index) : OptionException(), m_index(index) {};

		// Copy Constructor
		PutCallParityException::PutCallParityException(const PutCallParityException& source) : OptionException(source), m_index(source.m_index) {};

		// Destructor
		PutCallParityException::~PutCallParityException() {}

		// Assignment Operator
		PutCallParityException& PutCallParityException::operator = (const PutCallParityException& source)
		{
			if (this == &source)
			{
				return *this;
			}

			// Nothing to copy in the base class. Hence, no need to call the
			// base class assignment operator

			m_index = source.m_index;

			return *this;
		}

		std::string PutCallParityException::GetMessage()
		{
			if (m_index == -1)
			{
				return "Invalid Option Type In Put Call Parity!!";
			}
			else
			{
				return "Undefined Exception";
			}
		}
	}
}