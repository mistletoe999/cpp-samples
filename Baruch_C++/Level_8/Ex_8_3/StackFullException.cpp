// StackFullException.cpp:
// implements the StackFullException class defined in StackFullException.hpp

#include "StackFullException.hpp"

// Default Constructor
StackFullException::StackFullException() : StackException(), m_index(-1) {}

// Constructor with index value
StackFullException::StackFullException(int index) : StackException(), m_index(index) {}

// Copy Constructor
StackFullException::StackFullException(const StackFullException& sfe) : StackException(sfe), m_index(sfe.m_index) {}

// Destructor
StackFullException::~StackFullException() {}

// Assignment Operator
StackFullException& StackFullException::operator=(const StackFullException& source)
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
string StackFullException::GetMessage()
{
	if (m_index == -1)
	{
		return "STACK OVERFLOW!! Stack container is full";
	}
	else
	{
		return "Undefined Exception";
	}
}