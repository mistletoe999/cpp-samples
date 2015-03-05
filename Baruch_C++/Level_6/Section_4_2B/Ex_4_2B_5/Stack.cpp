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
		template <typename T>
		Stack<T>::Stack() : m_current(0) {} // Default Constrcutor
		// Calls the default constructor of Array
		// Should create an array with space for 5 objects

		// Constructor with size parameter
		template <typename T>
		Stack<T>::Stack(unsigned int size) : m_current(0), m_array(Array<T>(size)) {}


		// Copy Constructor
		template <typename T>
		Stack<T>::Stack(const Stack<T>& source) : m_current(source.m_current), m_array(source.m_array) {} 

		template <typename T>
		Stack<T>::~Stack() { m_current = 0; }

		template <typename T>
		void Stack<T>::Push(const T& obj)
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

		template <typename T>
		T& Stack<T>::Pull()
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

		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)
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