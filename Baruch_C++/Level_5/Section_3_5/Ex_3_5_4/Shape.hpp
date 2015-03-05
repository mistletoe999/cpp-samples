// Shape.hpp: Contains the definition for Shape class
// Shape class is the Base class for Point, Line and Circle classes
// EDIT: Added a Draw function overridden in the derived classes

#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

namespace KAPIL
{
	namespace CAD
	{
		class Shape {
		private:
			int m_id; // ID number for the shape. Generated Randomly
		public:
			// Constructors
			Shape(); // Default Constructor
			Shape(const Shape& shape); // Copy Constructor

			// Destructor
			virtual ~Shape(); // Virtual Destructor

			// Other member Functions
			int ID(); // Getter function for m_id
			virtual string ToString() const;	// Gives a string representation of the Shape as ID: 123"
			virtual void Draw() const = 0;					// Draw function: Overridden in the derived classes


			// Operators
			Shape& operator=(const Shape& source); // Assignment Operator
		};
	}
}

#endif // SHAPE_HPP_