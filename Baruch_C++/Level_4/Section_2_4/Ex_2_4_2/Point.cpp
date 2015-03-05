// Implements the Point class defined in Point.hpp
// EDIT: Added ostream operator as global function

#include "Point.hpp"

Point::Point() { // Default Constructor
	m_x = m_y = 0.0;
}

Point::Point(double x, double y) { // Initialize with x and y values
	m_x = x;
	m_y = y;
}

Point::Point(const Point& point) { // Copy Constructor
	m_x = point.m_x;
	m_y = point.m_y;
}

Point::~Point() {
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

//=========================================================================================
// MODIFICATION FROM SECTION 2.3

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
	*this = *this * 2; // Defined the * scale operator before
	return (*this);
}

// ostream operator
ostream& operator << (ostream& os, const Point& p) { // Send to ostream.
	os << p.ToString();
	return os;
}