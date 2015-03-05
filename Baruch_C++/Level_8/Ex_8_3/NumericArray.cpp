// NumericAArray.cpp: Implements the NumericArray derived class
// defined in the NumericArray.hpp


#ifndef NUMERIC_ARRAY_CPP_
#define NUMERIC_ARRAY_CPP_

#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include "DifferentSizeException.hpp"

namespace KAPIL
{
	namespace Containers
	{
		// Default Constructor
		template <typename T>
		NumericArray<T>::NumericArray() : Array<T>() {} 
		
		// Constructor with size operator
		template <typename T>
		NumericArray<T>::NumericArray(unsigned int size) : Array<T>(size) {}

		// Copy Constructor
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source) {};

		// Destructor
		template <typename T>
		NumericArray<T>::~NumericArray() {}

		template <typename T>
		double NumericArray<T>::DotProduct(const NumericArray<T>& arr) const 
		{
			double product = 0;
			if (this->Size() == arr.Size())
			{
				for (int i = 0; i < this->Size(); i++)
				{
					product += (*this)[i] * arr[i];
				}
			}
			else
			{
				// Throw different size exception
				throw DifferentSizeException(-1);
			}
			return product;
		}

		// Multiplication by factor operator: double factor
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (double factor) const {	
			NumericArray<T> temp(this->Size());
			for (int i = 0; i < temp.Size(); i++) 
			{
				temp.SetElement(i, ((*this)[i])*factor);
			}
			return temp;
		}

		// Multiplication by factor operator: integer factor
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (int factor) const {
			NumericArray<T> temp(this->Size());
			for (int i = 0; i < temp.Size(); i++)
			{
				temp.SetElement(i, ((*this)[i])*factor);
			}
			return temp;
		}

		// Addition operator
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& arr) const	
		{
			
			if (this->Size() == arr.Size())
			{
				NumericArray<T> temp(this->Size());
				for (int i = 0; i < this->Size(); i++)
				{
					temp.SetElement(i, (*this)[i] + arr[i]);
				}
			}
			else
			{
				throw DifferentSizeException(-1);
			}
		}

		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source) 
		{
			// Self Assignment Check
			if (this == &source)
			{
				return *this;
			}

			Array<T>::operator=(source);

			return *this;
		}
	}
}


 
#endif // NUMERIC_ARRAY_CPP_