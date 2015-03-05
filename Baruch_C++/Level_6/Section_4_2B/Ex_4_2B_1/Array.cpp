// ARRAY.cpp: Implements the Array class in Array.hpp
// Change from previous level: Array class now implemented as 
// a template class
// EDIT: Added static variable for default size

#ifndef ARRAY_CPP_
#define ARRAY_CPP_

#include "Array.hpp"
#include "Point.hpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"

namespace KAPIL
{
	namespace Containers
	{
		
		// Initialized the static default size 
		// data member to 5

		//*************EDIT*********************
		template <typename T>
		unsigned int Array<T>::m_defaultSize = 5;
		
		// Default Constructor
		template <typename T>
		Array<T>::Array()
		{
			//T def(0);
			m_size = m_defaultSize;
			m_data = new T[m_size];
		}

		// Constrcutor with size parameter
		template <typename T>
		Array<T>::Array(unsigned int size)
		{
			m_size = size;
			m_data = new T[m_size];
		}

		// Copy Constructor
		template <typename T>
		Array<T>::Array(const Array<T>& arr)
		{
			m_size = arr.m_size;
			m_data = new T[m_size];

			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = arr.m_data[i];
			}
		}

		// Destructor
		template <typename T>
		Array<T>::~Array()
		{
			delete[] m_data;		// Delete the dynamically allocated memory
			m_data = 0;				// Assign pointer to NULL
		}

		// Member Functions
		template <typename T>
		unsigned int Array<T>::Size() const
		{
			return m_size;
		}

		// Setter Function
		template <typename T>
		void Array<T>::SetElement(unsigned int index, const T& obj)
		{
			if (index >= 0 && index < m_size) {
				m_data[index] = obj;
			}
			else {
				throw OutOfBoundsException(-1);
			}
		}

		//*************EDIT*********************
		template <typename T>
		void Array<T>::DefaultSize(unsigned int size) {
			m_defaultSize = size;
		}

		// Getter Function 
		template <typename T>
		T& Array<T>::GetElement(unsigned int index) const
		{
			if (index >= 0 && index < m_size) {
				return m_data[index];
			}
			else {
				throw OutOfBoundsException(-1);
			}
		}

		//*************EDIT*********************
		template <typename T>
		unsigned int Array<T>::DefaultSize()
		{
			return m_defaultSize;
		}

		// Operators
		template <typename T>
		Array<T>& Array<T>::operator=(const Array<T>& source)
		{
			// Self Assignment Check
			if (this == &source)
			{
				return *this;
			}

			// First we need to deallocate the value m_data is currently holding
			delete[] m_data;

			// Get the size of the source array
			m_size = source.m_size;


			if (source.m_data) // Check whether source m_data is pointing to null 
			{
				// Initialize m_data again on the heap
				m_data = new T[m_size];
				// Copy elements
				for (int i = 0; i < m_size; i++)
				{
					// Copy individual elements
					m_data[i] = source.m_data[i];
				}
			}
			else {
				m_data = 0;
			}

			return *this;
		}


		// [] operator
		template <typename T>
		T& Array<T>::operator [] (int index)
		{
			if (index >= 0 && index < m_size)
			{
				return m_data[index];
			}
			else
			{
				throw OutOfBoundsException(-1);
			}
		}

		// [] operator
		template <typename T>
		const T& Array<T>::operator [] (int index) const
		{
			if (index >= 0 && index < m_size)
			{
				return m_data[index];
			}
			else
			{
				throw OutOfBoundsException(-1);
			}
		}
	}
}

#endif // ARRAY_CPP_