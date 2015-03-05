// NumericArray.hpp
// Contains the definition for NumericArray derived class

#ifndef NUMERIC_ARRAY_HPP_
#define NUMERIC_ARRAY_HPP_

#include "Array.hpp"
using namespace std;

namespace KAPIL
{
	namespace Containers
	{
		template <typename T>
		class NumericArray : public Array<T> {
		private:
		
		public:
			NumericArray();									// Default Constructor
			NumericArray(unsigned int size);				// Constructor with size parameter
			NumericArray(const NumericArray<T>& source);	// Copy Constructor
			virtual ~NumericArray();						// Destructor

			double DotProduct(const NumericArray<T>& arr) const;			// Dotproduct function
			NumericArray<T> operator + (const NumericArray<T>& arr) const;	// + operator
			NumericArray<T> operator * (const double factor) const;			// Scale * operator : double factor
			NumericArray<T> operator * (const int factor) const;			// Scale * operator : int factor
			NumericArray<T>& operator = (const NumericArray<T>& source);	// Assignment Operator
		};
	}
}

#ifndef NUMERIC_ARRAY_CPP_
#include "NumericArray.cpp" 
#endif // NUMERIC_ARRAY_CPP_

#endif // NUMERIC_ARRAY_HPP_