// CheckSmaller.cpp
// Implements the CheckSmaller functor defined in CheckSmaller.hpp

#ifndef CHECK_SMALLER_CPP_
#define CHECK_SMALLER_CPP_

#include "CheckSmaller.hpp"

// Default Constructor
template <typename T>
CheckSmaller<T>::CheckSmaller() : m_val(0) {}
// Let's say that by default it check whether the value is negative or not in () operator

// Constructor with value parameter
template <typename T>
CheckSmaller<T>::CheckSmaller(T val) : m_val(val) {}

// Copy Constructor
template <typename T>
CheckSmaller<T>::CheckSmaller(const CheckSmaller<T>& source) : m_val(source.m_val) {}

// Destructor
template <typename T>
CheckSmaller<T>::~CheckSmaller() {}

// Assignent Operator
template <typename T>
CheckSmaller<T>& CheckSmaller<T>::operator=(const CheckSmaller<T>& source)
{
	if (this == &source)
	{
		return *this;
	}

	m_val = source.m_val;
	return *this;
}

template <typename T>
bool CheckSmaller<T>::operator() (const T& toCheck) const
{
	return (toCheck < m_val);
}

#endif // CHECK_SMALLER_CPP_
