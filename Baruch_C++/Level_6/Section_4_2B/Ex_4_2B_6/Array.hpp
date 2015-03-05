// ARRAY.hpp: Contains the definition for template class Array
// in Containers namespace of KAPIL namespace
// It is a template Array class which implements
// a dynamic array container

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

namespace KAPIL
{
	namespace Containers
	{
		template <typename T>
		class Array
		{
		private:
			T * m_data;					// Pointer to the initial element
			unsigned int m_size;		// Size of the array
			static unsigned int m_defaultSize; // Default size of the Array class
		public:
			// Constructors
			Array();					// Default Constructor
			Array(unsigned int size);	// Constructor with size as the parameter
			Array(const Array<T>& arr);	// Copy Constructor

			// Desctructor
			virtual ~Array();					// Destructor

			// Member Functions
			unsigned int Size() const;		// Returns the array size
			void SetElement(unsigned int index, const T& obj); // Sets m_data[index] to p
			T& GetElement(unsigned int index) const; // Gets the refernce to m_data[index]
			static unsigned int DefaultSize(); // Gets the default size data member 
			// m_defaultSize 
			static void DefaultSize(unsigned int size); // Sets the default size parameter 
			// m_defaultSize


			// Operators
			Array<T>& operator=(const Array<T>& source); // Assignment Operator	
			T& operator [] (int index);	// Square bracket index operator  
			const T& operator [] (int index) const; // Square bracket with index operator (const reference and const output): 
		};
	}
}

// If used, no need to include the cpp file in the 
// main program

#ifndef ARRAY_CPP_
#include "Array.cpp" 
#endif // ARRAY_CPP_

#endif // ARRAY_HPP_