// StackFullException.hpp:
// Defines the StackFullException derived class, derived from StackException base class
// Used to throw an exception when the stack's array container is full

#ifndef STACK_FULL_EXCEPTION_HPP_
#define STACK_FULL_EXCEPTION_HPP_

#include "StackException.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>
#include <string>
using namespace std;

class StackFullException : public StackException 
{
private:
	int m_index;
public:
	StackFullException();									// Default Constructor
	StackFullException(int index);							// Constructor with index
	StackFullException(const StackFullException& sfe);	// Copy Constructor

	virtual ~StackFullException();

	StackFullException& operator = (const StackFullException& source);	// Assignment Operator
	string GetMessage();		// Displays the exception message

};



#endif // STACK_FULL_EXCEPTION_HPP_

