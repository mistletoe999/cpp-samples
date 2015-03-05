// Line.hpp: Contains the defintion for Line class
// EDIT: Added ostream operator as friend function

#ifndef LINE_HPP_
#define LINE_HPP_

#include "Point.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Line {
private:
	Point lineStart;							// start-point of the line
	Point lineEnd;								// end-point of the line

public:
	// Constructors
	Line();										// Default Constructor
	Line(const Point& pS, const Point& pE);		// Constructor with start and end points
	Line(const Line& line);						// Copy Constructor
	
	// Desctructor
	~Line();									// Destructor
	
	// Getter and Setter Functions
	Point Start() const;						// Getter for start-point
	Point End() const;							// Getter for end-point
	void Start(const Point& point);				// Setter function for start-point
	void End(const Point& point);				// Setter function for end-point

	// Other Functions
	string ToString() const; // Gives a string representation of a line
	double Length() const; // Calculate length of the line segment

	// Operator Overloading
	Line& operator = (const Line& source);		// Assignment Operator
	friend ostream& operator << (ostream& os, const Line& l); // send to ostream

};


#endif // LINE_HPP_