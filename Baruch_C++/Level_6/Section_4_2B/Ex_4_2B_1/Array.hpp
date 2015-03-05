// ARRAY.hpp: Contains the definition for template class Array
// in Containers namespace of KAPIL namespace
// It is a template Array class which implements
// a dynamic array container

// EDIT: Added default size data member as static

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
// Do not need to include any shape object header file
// since our class is now templatized
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
			// ***************EDIT**************
			static unsigned int m_defaultSize; // Default size of the Array class
			// *********************************
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
			// ************EDIT****************
			static unsigned int DefaultSize(); // Gets the default size data member 
			// m_defaultSize 
			static void DefaultSize(unsigned int size); // Sets the default size parameter 
			// m_defaultSize

			// ********************************

			// Operators
			Array<T>& operator=(const Array<T>& source); // Assignment Operator	
			T& operator [] (int index);	// Square bracket index operator  
			const T& operator [] (int index) const; // Square bracket with index operator (const reference and const output): 
			// Answer: We need the const version so that we call different 
			// version of the operator if we use the [] operator get the element 
			// or assign/copy the element; const version does not allow copy
		};
	}
}

// If used, no need to include the cpp file in the 
// main program

#ifndef ARRAY_CPP_
#include "Array.cpp" 
#endif // ARRAY_CPP_

// REASON: Whenever we include the Array.hpp file, the main program reads 
// the whole file from top to bottom and if the contents of
// Array.cpp file are not defined yet, they are included 
// as soon as the Array.cpp file in included within here

#endif // ARRAY_HPP_