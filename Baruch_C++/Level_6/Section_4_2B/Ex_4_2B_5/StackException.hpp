// StackException.hpp: Defines in the StackException base class

#ifndef STACK_EXCEPTION_HPP_
#define STACK_EXCEPTION_HPP_


#include <iostream>
#include <string>
using namespace std;

class StackException
{
private:
public:
	StackException();											// Default Constructor
	StackException(const StackException& stackException);		// Copy Constructor
	virtual ~StackException();									// Destructor
	StackException& operator = (const StackException& source);	// Assignment Operator

	virtual string GetMessage() = 0;							// Abstract GetMessage function
	// Displays the message of the exception

};


#endif //STACK_EXCEPTION_HPP_