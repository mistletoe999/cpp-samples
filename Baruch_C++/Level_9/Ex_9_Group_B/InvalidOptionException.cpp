// InvalidOptionException.cpp
// Implements the InvalidOptionException class
// defined in InvalidOptionException.hpp

#include "InvalidOptionException.hpp"

namespace OPTIONPRICING
{
	namespace EXCEPTIONS
	{
		// Default Constructor
		InvalidOptionException::InvalidOptionException() : OptionException(), m_index(-1) {}

		// Constructor with index
		InvalidOptionException::InvalidOptionException(const int index) : OptionException(), m_index(index) {};

		// Copy Constructor
		InvalidOptionException::InvalidOptionException(const InvalidOptionException& source) : OptionException(source), m_index(source.m_index) {};

		// Destructor
		InvalidOptionException::~InvalidOptionException() {}

		// Assignment Operator
		InvalidOptionException& InvalidOptionException::operator = (const InvalidOptionException& source)
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

		std::string InvalidOptionException::GetMessage()
		{
			if (m_index == -1)
			{
				return "INVALID OPTION!! Option is not defined";
			}
			else
			{
				return "Undefined Exception";
			}
		}
	}
}