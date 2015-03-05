// ArrayException.hpp: Defines the abstract ArrayException class

#ifndef ARRAY_EXCEPTION_HPP_
#define ARRAY_EXCEPTION_HPP_

#include <iostream>
#include <string>

using namespace std;

class ArrayException {
private:
public:
	ArrayException(); // Default Constructor
	ArrayException(const ArrayException& arrayException); // Copy Constructpr
	virtual ~ArrayException(); // Destructor
	ArrayException& operator=(const ArrayException& source); // Assignment Operator

	// Other member functions
	virtual string GetMessage() = 0; // Abstract GetMessage function

};


#endif //ARRAY_EXCEPTION_HPP_