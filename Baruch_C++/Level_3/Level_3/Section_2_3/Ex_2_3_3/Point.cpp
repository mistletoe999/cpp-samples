// Point.cpp: Implements the Point class defined in Point.hpp

#include "Point.hpp"

Point::Point() { // Default Constructor
	m_x = m_y = 0.0;
}

Point::Point(double x, double y) { // Initialize with x and y values
	m_x = x;
	m_y = y;
}

Point::Point(const Point& point) { // Copy Constructor
	m_x = point.X();
	m_y = point.Y();
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

string Point::ToString() const { // Outputs a string to demonstrate the point as "Point(m_x, m_y)"
	stringstream pointStream; // Start reading input into a stringstream
	pointStream << "Point(" << m_x << "," << m_y << ")"; // Add string to pointStream
	return(pointStream.str()); // Output the string using the str() member function
}

double Point::Distance() const { // Returns the distance from the origin (0, 0)
	return(sqrt(m_x*m_x + m_y*m_y));
}

double Point::Distance(const Point& point) const { // Returns the distance from Point point
	double distance = sqrt((m_x - point.X())*(m_x - point.X())
		+ (m_y - point.Y())*(m_y - point.Y()));
	return distance;
}

