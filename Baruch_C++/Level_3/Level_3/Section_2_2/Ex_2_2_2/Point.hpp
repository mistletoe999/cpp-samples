// Point.hpp: Contains the definition of the Point class

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

	// Destructor
	~Point();

	// Member Functions 
	// Getter Functions
	double GetX() const;		// Get the value of X-coordinate
	double GetY() const;		// Get the value of Y-coordinate

	// Setter Functions
	void SetX(double newX);		// Set X-coordinate to new value newX
	void SetY(double newY);		// Set Y-coordinate to new value newY

	// Display Function
	string ToString() const; // Gives a string representation of a point as ""Point(m_x, m_y)"

	// Distance Functions
	double DistanceOrigin();	// Calculate the distance to the origin (0, 0).
	double Distance(Point p);	// Calculate the distance between two points.

};



#endif // POINT_HPP_