// Point.cpp: Implements the Point class defined in Point.hpp

#include "Point.hpp"

Point::Point() { // Default Constructor
	m_x = m_y = 0.0;
	cout << "Calling Constructor.." << endl;
}

Point::Point(double x, double y) { // Initialize with x and y values
	m_x = x;
	m_y = y;
	cout << "Calling Constructor.." << endl;
}

Point::Point(const Point& point) { // Copy Constructor
	m_x = point.GetX();
	m_y = point.GetY();
	cout << "Calling Copy Constructor.." << endl;
}

Point::~Point() {
	// Destructor
	cout << "Calling Destructor.." << endl;
}


// Getter Functions
double Point::GetX() const // Returns the value of X-coordinate
{
	return m_x;
}

double Point::GetY() const // Returns the value of Y-coordinate
{
	return m_y;
}

// Setter Functions
void Point::SetX(double newX) // Sets the value of X-coordinate to newX
{
	m_x = newX;
}

void Point::SetY(double newY) // Sets the value of Y-coordinate to newX
{
	m_y = newY;
}

// Display function
string Point::ToString() const { // Outputs a string to demonstrate the point as "Point(m_x, m_y)"
	stringstream pointStream; // Start reading input into a stringstream
	pointStream << "Point(" << m_x << "," << m_y << ")"; // Add string to pointStream
	return(pointStream.str()); // Output the string using the str() member function
}

// Distance functions
double Point::DistanceOrigin() { // Returns the distance from the origin (0, 0)
	return(sqrt(m_x*m_x + m_y*m_y));
}


// Distance from another Point object now takes a referenc
double Point::Distance(const Point& point) { // Returns the distance from Point point
	double distance = sqrt((m_x - point.GetX())*(m_x - point.GetX())
		+ (m_y - point.GetY())*(m_y - point.GetY()));
	// point.SetX(12.0); Causes compiler error
	cout << "Returning distance.." << endl;
	return distance;
}

