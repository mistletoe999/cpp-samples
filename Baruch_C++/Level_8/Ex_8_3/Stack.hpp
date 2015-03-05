// Stack.hpp: Defines the template Stack Container class

#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>
#include "Array.hpp"
using namespace std;

namespace KAPIL
{
	namespace Containers
	{
		template <typename T, unsigned int size>
		class Stack
		{
		private:
			Array<T> m_array;						
			unsigned int m_current;								// Points to the current index where element can be added
			// Default m_current = 0 initially
		public:
			// Constructors
			Stack();											// Default Constructor
			//Stack(unsigned int current);						// Constructor with new current position 
			Stack(const Stack<T, size>& source);						// Copy Constructor
			// Destructors
			virtual ~Stack();									// Destructor

			// General Member Functions
			void Push(const T& obj);							// Store the element at the current position
			T& Pull();											// Remove the element from the current position
																// and decrease the top of the stack by 1

			// Operator Overloading
			Stack<T, size>& operator = (const Stack<T, size>& source);	// Assignment Operator

		};

	}
}

#ifndef STACK_CPP_
#include "Stack.cpp"
#endif // STACK_CPP_

#endif // STACK_HPP_