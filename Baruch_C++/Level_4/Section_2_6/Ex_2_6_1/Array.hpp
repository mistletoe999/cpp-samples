#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Point.hpp"
using namespace std;

namespace KAPIL
{
	namespace Containers
	{
		class Array
		{
		private:
			CAD::Point * m_data;
			unsigned int m_size;
		public:
			// Constructors
			Array();					// Default Constructor
			Array(unsigned int size);	// Constructor with size as the parameter
			Array(const Array& arr);	// Copy Constructor

			// Desctructor
			~Array();					// Destructor

			// Member Functions
			unsigned int Size() const;		// Returns the array size
			void SetElement(unsigned int index, const CAD::Point& p); // Sets m_data[index] to p
			CAD::Point& GetElement(unsigned int index) const; // Gets the refernce to m_data[index]

			// Operators
			Array& operator=(const Array& source); // Assignment Operator	
			CAD::Point& operator [] (int index);	// Square bracket index operator  
			const CAD::Point& operator [] (int index) const; // Square bracket with index operator (const reference and const output): 
			// Answer: We need the const version so that we call different 
			// version of the operator if we use the [] operator get the element 
			// or assign/copy the element; const version does not allow copy
		};



	}
}


#endif