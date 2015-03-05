#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"

OutOfBoundsException::OutOfBoundsException() : ArrayException(), m_index(-1) {} // Default Constructor


OutOfBoundsException::OutOfBoundsException(int index) : ArrayException(), m_index(index) {} // Constructor with integer index argument

OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException& obe) : ArrayException(obe), m_index(obe.m_index) {}  // Copy Constructor

// Destructor 
OutOfBoundsException::~OutOfBoundsException() {}

// Assignment Operator
OutOfBoundsException& OutOfBoundsException::operator=(const OutOfBoundsException& source)
{
	if (this == &source) { return *this; }  // Self Assignment Check}
	// Nothing to copy for the Base class
	m_index = source.m_index; // Copy data
	return *this; // return reference to the currenct object
}


// Other member functions
string OutOfBoundsException::GetMessage() 
{
	if (m_index == -1) {
		return "ERROR! OutOfBoundsException: Array is out of bounds";
	}
}