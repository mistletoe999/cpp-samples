// Stack.cpp: Implements the Stack template class

#ifndef STACK_CPP_
#define STACK_CPP_

#include "Stack.hpp"
#include "StackException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

namespace KAPIL
{
	namespace Containers
	{
		template <typename T, unsigned int size>
		Stack<T, size>::Stack() : m_current(0), m_array(Array<T>(size)) {} // Default Constructor

		// Copy Constructor
		template <typename T, unsigned int size>
		Stack<T, size>::Stack(const Stack<T, size>& source) : m_current(source.m_current), m_array(source.m_array) {} 

		// Destructor
		template <typename T, unsigned int size>
		Stack<T, size>::~Stack() { m_current = 0; }


		// Push function
		template <typename T, unsigned int size>
		void Stack<T, size>::Push(const T& obj)
		{
			try
			{
				m_array[m_current] = obj; // If can't be assigned, throws an OutOfBoundsException
				m_current++;
			}
			catch (ArrayException& ex)
			{
				throw StackFullException(-1);
			}
		}

		// Pull function
		template <typename T, unsigned int size>
		T& Stack<T, size>::Pull()
		{
			T output;
			try {
				output = m_array[m_current - 1]; // If can't be assigned, throws an OutOfBoundException
				--m_current;
			}
			catch (ArrayException& ex)
			{
				throw StackEmptyException(-1);
			}
			return output;
		}

		// Assignment operator
		template <typename T, unsigned int size>
		Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
		{
			if (this == &source) 
			{
				return (*this);
			}

			m_array = source.m_array;
			m_current = source.m_current;

			return (*this);
		}
	}
}


#endif // STACK_CPP_