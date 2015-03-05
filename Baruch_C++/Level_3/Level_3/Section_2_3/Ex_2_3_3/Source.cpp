// Ex 2.3.3: Improves upon the Point class defined in Section 2.2
// Point class defined in 'Point.hpp'
// This program demonstrates the use of function
// overloading for member functions

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

	// Example:  Calling overloaded functions
	cout << "The distance of Point 1 from origin: " << point1.Distance() << endl;
	cout << "The distance of Point 2 from origin: " << point2.Distance() << endl;
	cout << "The distance of Point 2 from Point 1: " << point1.Distance(point2) << endl;

	return 0;
}