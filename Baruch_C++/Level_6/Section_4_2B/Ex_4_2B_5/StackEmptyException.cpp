// StackEmptyException.cpp:
// implements the StackEmptyException class defined in StackEmptyException.hpp


#include "StackEmptyException.hpp"

// Default Constructor
StackEmptyException::StackEmptyException() : StackException(), m_index(-1) {}

// Constructor with index value
StackEmptyException::StackEmptyException(int index) : StackException(), m_index(index) {}

// Copy Constructor
StackEmptyException::StackEmptyException(const StackEmptyException& see) : StackException(see), m_index(see.m_index) {}

// Destructor
StackEmptyException::~StackEmptyException() {}

// Assignment Operator
StackEmptyException& StackEmptyException::operator=(const StackEmptyException& source)
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


// Get Message
string StackEmptyException::GetMessage()
{
	if (m_index == -1)
	{
		return "STACK UNDERFLOW!! Stack container is empty";
	}
	else
	{
		return "Undefined Exception";
	}
}