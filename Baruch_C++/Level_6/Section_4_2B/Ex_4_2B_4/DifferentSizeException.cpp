// DifferentSizeException.cpp: Implements the different size exception

#include "ArrayException.hpp"
#include "DifferentSizeException.hpp"

DifferentSizeException::DifferentSizeException() : ArrayException(), m_index(-1) {} // Default Constructor


DifferentSizeException::DifferentSizeException(int index) : ArrayException(), m_index(index) {} // Constructor with integer index argument

DifferentSizeException::DifferentSizeException(const DifferentSizeException& dse) : ArrayException(dse), m_index(dse.m_index) {}  // Copy Constructor

// Destructor 
DifferentSizeException::~DifferentSizeException() {}

// Assignment Operator
DifferentSizeException& DifferentSizeException::operator=(const DifferentSizeException& source)
{
	if (this == &source) { return *this; }  // Self Assignment Check
	// Nothing to copy for the Base class
	m_index = source.m_index; // Copy data
	return *this; // return reference to the currenct object
}


// Other member functions
string DifferentSizeException::GetMessage()
{
	if (m_index == -1) {
		return "ERROR! DifferentSizeException: Arrays have different size";
	}
}