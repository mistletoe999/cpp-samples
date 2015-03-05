// StackEmptyException.hpp:
// Defines the StackEmptyException derived class, derived from StackException base class
// Used to throw an exception when the stack's array container is empty and there are
// no records to Pull

#ifndef STACK_EMPTY_EXCEPTION_HPP_
#define STACK_EMPTY_EXCEPTION_HPP_

#include "StackException.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>
#include <string>
using namespace std;

class StackEmptyException : public StackException
{
private:
	int m_index;
public:
	StackEmptyException();									// Default Constructor
	StackEmptyException(int index);							// Constructor with index
	StackEmptyException(const StackEmptyException& see);	// Copy Constructor

	virtual ~StackEmptyException();

	StackEmptyException& operator = (const StackEmptyException& source);	// Assignment Operator
	string GetMessage();		// Displays the exception message

};



#endif // STACK_EMPTY_EXCEPTION_HPP_

