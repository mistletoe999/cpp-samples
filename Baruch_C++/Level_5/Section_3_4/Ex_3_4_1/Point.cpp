// Implements the Point class defined in Point.hpp
// EDIT: Use Colon syntax for constructors

#include "Point.hpp"

namespace KAPIL
{
	namespace CAD
	{
		Point::Point() : m_x(0.0), m_y(0.0) { // Default Constructor
			cout << "Default Point Constructor" << endl;
		}

		Point::Point(double x, double y) : m_x(x), m_y(y) { // Initialize with x and y values
			cout << "Point Constructor - Values" << endl;
		}

		Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y) { // Copy Constructor
			cout << "Point Copy Constructor" << endl;
		}

		Point::~Point() {
			cout << "Point Destructor" << endl;
			// Destructor
		}

		// Getter Functions
		double Point::X() const // Returns the value of X-coordinate
		{
			return m_x;
		}

		double Point::Y() const // Returns the value of Y-coordinate
		{
			return m_y;
		}

		// Setter Functions
		void Point::X(double newX) // Sets the value of X-coordinate to newX
		{
			m_x = newX;
		}

		void Point::Y(double newY) // Sets the value of Y-coordinate to newX
		{
			m_y = newY;
		}

		// Display Function
		string Point::ToString() const { // Outputs a string to demonstrate the point as "Point(m_x, m_y)"
			stringstream pointStream; // Start reading input into a stringstream
			pointStream << "(" << m_x << "," << m_y << ")"; // Add string to pointStream
			return(pointStream.str()); // Output the string using the str() member function
		}

		// Distance Functions
		double Point::Distance() const { // Returns the distance from the origin (0, 0)
			return(sqrt(m_x*m_x + m_y*m_y));
		}

		double Point::Distance(const Point& point) const { // Returns the distance from Point point
			double distance = sqrt((m_x - point.m_x)*(m_x - point.m_x)
				+ (m_y - point.m_y)*(m_y - point.m_y));
			return distance;
		}

		// Operator Overloading:
		// Operator overloading using member functions

		// Unary '-' operator
		Point Point::operator - () const { // Negate the coordinates.
			return Point(-m_x, -m_y);
		}

		// Scale operator '*'
		Point Point::operator * (double factor) const {	// Scale the coordinates.
			return Point(factor*m_x, factor*m_y);
		}

		// Addition operator to add a Point to Point
		Point Point::operator + (const Point& p) const {	// Add coordinates.
			return Point(m_x + p.m_x, m_y + p.m_y);
		}

		// Equality Operators
		bool Point::operator == (const Point& p) const {	// Equally compare operator.
			return (m_x == p.m_x && m_y == p.m_y);
		}

		// Assignment Operator
		Point& Point::operator = (const Point& source)	{ // Assignment operator.
			cout << "Point Assignment Operator" << endl;
			// Self Assignment Check:
			if (this == &source) {
				return *this;
			}

			// Copy values
			m_x = source.m_x;
			m_y = source.m_y;

			// Return the reference to the current object
			return *this;
		}

		// Scale and assign
		Point& Point::operator *= (double factor) { // Scale the coordinates & assign.
			m_x *= factor;
			m_y *= factor;
			return (*this);
		}

		// ostream operator: As a friend function, "operator<<" can access 
		// private members of Point p.
		ostream& operator << (ostream& os, const Point& p) { // Send to ostream.
			os << "(" << p.m_x << "," << p.m_y << ")";
			return os;
		}
	}

}

