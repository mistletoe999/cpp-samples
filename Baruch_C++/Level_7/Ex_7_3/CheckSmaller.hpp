// CheckSmaller.hpp
// Defines the CheckSmaller functor

#ifndef CHECK_SMALLER_HPP_
#define CHECK_SMALLER_HPP_

template <typename T>
class CheckSmaller
{
private:
	T m_val;
public:
	CheckSmaller(); // Default Constructor
	CheckSmaller(T val);	// Constructor with val parameter
	CheckSmaller(const CheckSmaller<T>& source);	// Copy Constructor
	~CheckSmaller();	// Destructor

	// Operators
	CheckSmaller<T>& operator=(const CheckSmaller<T>& source);	// Assignment Operator
	bool operator()(const T& toCheck) const;	// Overloaded () operators
};



#ifndef CHECK_SMALLER_CPP_
#include "CheckSmaller.cpp"
#endif

#endif // CHECK_SMALLER_HPP_