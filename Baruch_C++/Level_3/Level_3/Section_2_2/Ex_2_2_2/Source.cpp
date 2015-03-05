// Ex 2.2.2: Demonstrates the use of Point class
// Point class defined in 'Point.hpp'
// This program extends the use of Point class by
// adding Distance functions

#include <iostream>
#include <string>
#include <sstream>
#include "Point.hpp"
using namespace std;


int main() {
	double xValue, yValue;

	// Get the user input for x and y coordinates for new points
	cout << "Enter the X-coordinate of Point 1: ";
	cin >> xValue;
	cout << "Enter the Y-coordinate of Point 1: ";
	cin >> yValue;
	Point point1(xValue, yValue);

	cout << "Enter the X-coordinate of Point 2: ";
	cin >> xValue;
	cout << "Enter the Y-coordinate of Point 2: ";
	cin >> yValue;
	Point point2(xValue, yValue);

	// Print distances from origin
	cout << "The distance of Point 1 from Origin: " << point1.DistanceOrigin() << endl;
	cout << "The distance of Point 2 from Origin: " << point2.DistanceOrigin() << endl;

	// Print distances from each other
	cout << "The distance of Point 2 from Point 1: " << point1.Distance(point2) << endl;
	cout << "The distance of Point 1 from Point 2: " << point2.Distance(point1) << endl; 

	return 0;
}