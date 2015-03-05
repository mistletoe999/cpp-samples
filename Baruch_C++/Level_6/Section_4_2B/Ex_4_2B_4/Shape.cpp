// Shape.cpp implements the Shape class defined in the Shape.hpp
// EDIT: Added a polymorphic Print function

#include "Shape.hpp"

namespace KAPIL 
{
	namespace CAD
	{
		// Constructors
		Shape::Shape() : m_id(rand()) {} // Default Constructor

		Shape::Shape(const Shape& shape) : m_id(shape.m_id) {} // Copy Constructor

		// Destructor
		Shape::~Shape() {} // Destructor

		// Other member functions
		int Shape::ID() { return m_id; } // Getter function for m_id

		string Shape::ToString() const  // Gives a string representation of the Shape as ID: 123"
		{
			stringstream shapeStream; // Start reading input into a stringstream
			shapeStream << "ID: " << m_id; // Add string to shapeStream
			return(shapeStream.str()); // Output the string using the str() member function
		}

		// *****Implementation not required
		//void Shape::Draw() const {} // Draw function: Overridden in the derived classes

		// EDIT: Added Print function
		void Shape::Print() const // Polymorphic Print function
		{
			cout << ToString() << endl;
		}

		// Operator Overloading
		Shape& Shape::operator=(const Shape& source) // Assignment Operator
		{
			// Self Assignment check
			if (this == &source) {
				return *this;
			}

			// Copy data members
			m_id = source.m_id;

			// Return the reference to the current object
			return *this;
		}
	}
}