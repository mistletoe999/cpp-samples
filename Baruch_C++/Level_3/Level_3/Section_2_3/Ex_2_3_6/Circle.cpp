// Implements the Circle class in Circle.hpp

#include "Circle.hpp"

// Constructors
Circle::Circle() {// Default Constructor : Unit circle
	centre = Point(0.0, 0.0);
	radius = 1.0;
}

Circle::Circle(const Point& c, double r) {// Constructor with center and radius parameters
	centre = c;
	radius = r;
}
Circle::Circle(double r, const Point& c) {// Constructor with center and radius parameters
	centre = c;
	radius = r;
}

Circle::Circle(const Circle& circle) {// Copy Constructor 
	centre = circle.CentrePoint();
	radius = circle.Radius();
}

// Destructor
Circle::~Circle() { // Destructor
}

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
	circleStream << "Circle with Center at (" << centre.X() << "," << centre.Y() << ") and Radius = " 
		<< radius << "\nCircumference: " << Circumference() << "\nArea: " <<  Area(); // Add string to circleStream
	return(circleStream.str()); // Output the string using the str() member function
}