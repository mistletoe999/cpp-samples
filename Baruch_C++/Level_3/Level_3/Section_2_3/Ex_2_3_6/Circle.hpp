// Circle.hpp: Contains the definition for the Circle class

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "Point.hpp"
using namespace std;

class Circle {
private:
	Point centre;							// center-point of the line
	double radius;							// radius of the line
public:
	// Constructors
	Circle();								// Default Constructor
	Circle(const Point& c, double r);		// Constructor with center and radius parameters
	Circle(double r, const Point& c);		// Constructor with center and radius parameters
	Circle(const Circle& circle);			// Copy Constructor

	// Desctructor
	~Circle();								// Destructor

	// Getter and Setter Functions
	double Radius() const;					// Getter for radius
	Point CentrePoint() const;				// Getter for centre of the circle
	void Radius(const double r);			// Setter function for radius
	void CentrePoint(const Point& c);		// Setter function for centre of the citcle

	// Other Functions
	string ToString() const;				// Gives a string representation of a circle
	double Diameter() const;				// Calculate length of the diameter of the circle
	double Circumference() const;			// Calculate the circumference
	double Area() const;					// Calculate the area

};

#endif // CIRCLE_HPP_