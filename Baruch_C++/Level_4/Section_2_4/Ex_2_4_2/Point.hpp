// Point.hpp: Contains the definition for the Point class
// EDIT: Added ostream operator as global function

#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class Point {
private:
	double m_x;					// X-coordinate
	double m_y;					// Y-coordinate

public:
	// Constructors
	Point();					// Default Constructor
	Point(double x, double y);	// Initialize with x and y values
	Point(const Point& point);	// Copy Constructor

	// Destructor
	~Point();

	// Getter Functions
	double X() const;		// Get the value of X-coordinate
	double Y() const;		// Get the value of Y-coordinate

	// Setter Functions
	void X(double newX);		// Set X-coordinate to new value newX
	void Y(double newY);		// Set Y-coordinate to new value newY

	// Other Functions
	string ToString() const; // Gives a string representation of a point as ""Point(m_x, m_y)"

	// Distance Functions
	double Distance() const; // Calculate the distance to the origin (0, 0).
	double Distance(const Point& point) const; // Calculate the distance between two points.

	//=========================================================================================
	// MODIFICATION FROM SECTION 2.3

	// Operator Overloading:
	// Operator overloading using member functions
	Point operator - () const;					// Negate the coordinates.
	Point operator * (double factor) const;		// Scale the coordinates.
	Point operator + (const Point& p) const;	// Add coordinates.
	bool operator == (const Point& p) const;	// Equally compare operator.
	Point& operator = (const Point& source);	// Assignment operator.
	Point& operator *= (double factor);			// Scale the coordinates & assign.

};

// Operator Overloading: ostream operator
ostream& operator << (ostream& os, const Point& p); // Send to ostream.

#endif // POINT_HPP_