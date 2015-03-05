// OutOfBoundsException.hpp: 
// Defines the out of bounds exception class
// Derived from ArrayException class

#ifndef OUT_OF_BOUNDS_EXCEPTION_HPP_
#define OUT_OF_BOUNDS_EXCEPTION_HPP_

#include "ArrayException.hpp"

class OutOfBoundsException : public ArrayException {
private:
	int m_index;
public:
	OutOfBoundsException(); // Default Constructor
	OutOfBoundsException(int index); // Constructor with integer argument
	OutOfBoundsException(const OutOfBoundsException& obe); // Copy Constructor
	virtual ~OutOfBoundsException(); // Destructor

	OutOfBoundsException& operator=(const OutOfBoundsException& source); // Assignment Operator

	// Other member functions
	string GetMessage();
};

#endif // OUT_OF_BOUNDS_EXCEPTION_HPP_