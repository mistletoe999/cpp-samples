// Point.hpp: Contains the definition for the Point class

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
	void X(double newX) { m_x = newX; };		// Set X-coordinate to new value newX: Default Inline
	void Y(double newY) { m_y = newY; };		// Set Y-coordinate to new value newY: Default Inline

	// Other Functions
	string ToString() const; // Gives a string representation of a point as ""Point(m_x, m_y)"

	// Distance Functions
	double Distance() const; // Calculate the distance to the origin (0, 0).
	// EDIT FROM Question 1: Distance is calculated using pass by reference
	double Distance(const Point& point) const; // Calculate the distance between two points.

};

// Getter Functions
inline double Point::X() const { return m_x; } // Returns the value of X-coordinate: Inline function
inline double Point::Y() const { return m_y; } // Returns the value of Y-coordinate: Inline function

#endif // POINT_HPP_