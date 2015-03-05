// Implements the Circle class in Circle.hpp
// EDIT: Use Colon syntax for constructors

#include "Circle.hpp"

namespace KAPIL
{
	namespace CAD
	{
		// Constructors
		Circle::Circle() : Shape(), centre(Point(0.0, 0.0)), radius(1.0) {} // Default Constructor : Unit circle

		Circle::Circle(const Point& c, double r) : Shape(), centre(c), radius(r) {} // Constructor with center and radius parameters

		Circle::Circle(double r, const Point& c) : Shape(), centre(c), radius(r) {} // Constructor with center and radius parameters		}

		Circle::Circle(const Circle& circle) : Shape(circle), centre(circle.centre), radius(circle.radius) {} // Copy Constructor 

		// Destructor
		Circle::~Circle() { cout << "Circle Destructor" << endl; } // Destructor

		// Getter and Setter functions
		double Circle::Radius() const { // Getter function for radius
			return radius;
		}

		Point Circle::CentrePoint() const { // Getter function for centre 
			return centre;
		}

		void Circle::Radius(const double r) { // Setter function for radius
			radius = r;
		}

		void Circle::CentrePoint(const Point& c) { // Setter functon for the centre
			centre = c;
		}

		// Other member functions
		double Circle::Diameter() const { // Calculate length of the line segment
			return (radius * 2);
		}

		double Circle::Circumference() const { // Calculate the circumference 
			double pi = M_PI;
			return 2 * pi * radius;
		}

		double Circle::Area() const { // Calculate the area 
			double pi = M_PI;
			return pi * pow(radius, 2);
		}

		string Circle::ToString() const {
			stringstream circleStream; // Start reading input into a stringstream
			// EDIT: Added the ToString() function of the Shape class to display the ID as well.
			circleStream << Shape::ToString() << ": Circle with Center at " << centre.ToString() << " and Radius = "
				<< radius << "\nCircumference: " << Circumference() << "\nArea: " << Area(); // Add string to circleStream
			return(circleStream.str()); // Output the string using the str() member function
		}

		// Operator Overloading:
		Circle& Circle::operator = (const Circle& source) { // Assignment Operator
			// Self assignment check
			if (this == &source) {
				return *this;
			}

			// Copy Shape class member data
			Shape::operator=(source);

			// Copy data members
			centre = source.centre;
			radius = source.radius;

			// return a reference to the current object
			return *this;
		}

		// ostream operator: As a friend function, "operator<<" can access 
		// private members of Circle c.
		ostream& operator << (ostream& os, const Circle& c) { // Send to ostream.
			os << "Circle with Center at " << c.centre << " and Radius = "
				<< c.radius << "\nCircumference: " << c.Circumference() << "\nArea: " << c.Area();;
			return os;
		}
	}
}

