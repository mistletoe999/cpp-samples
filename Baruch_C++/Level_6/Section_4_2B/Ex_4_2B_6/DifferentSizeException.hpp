// DifferentSizeException.hpp: Defines the different size exception

#ifndef DIFFERENT_SIZE_EXCEPTION_HPP_
#define DIFFERENT_SIZE_EXCEPTION_HPP_

#include "ArrayException.hpp"

class DifferentSizeException : public ArrayException {
private:
	int m_index;
public:
	DifferentSizeException(); // Default Constructor
	DifferentSizeException(int index); // Constructor with integer argument
	DifferentSizeException(const DifferentSizeException& dse); // Copy Constructor
	virtual ~DifferentSizeException(); // Destructor

	DifferentSizeException& operator=(const DifferentSizeException& source); // Assignment Operator

	// Other member functions
	string GetMessage();
};

#endif // DIFFERENT_SIZE_EXCEPTION_HPP_