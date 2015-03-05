// Ex 2.2.1: Demonstrates the use of Point class
// Point class defined in 'Point.hpp'
// Initiates a default Point objects and modifies it using 
// user-defined X and Y coordinates
// Finally, prints out the output

#include <iostream>
#include <string>
#include <sstream>
#include "Point.hpp" // Point class defined here
using namespace std;

int main() {
	double xValue, yValue;

	// Get the user input for x and y coordinates for a new point
	cout << "Enter the X-coordinate: ";
	cin >> xValue;
	cout << "Enter the Y-coordinate: ";
	cin >> yValue;
	
	// Create a default Point object
	Point newPoint; // Assigns 0.0 and 0.0 to X and Y coordinates, respectively

	// Print the default point
	cout << "Default Point: X=" << newPoint.GetX() << ",Y=" << newPoint.GetY() << endl;

	// Assign the values of x and y to the newPoint object
	newPoint.SetX(xValue);
	newPoint.SetY(yValue);

	// Print the description of the point
	cout << newPoint.ToString() << endl;

	// Print the oordinates using the getter functions
	cout << "User Defined Point: (" << newPoint.GetX() << "," << newPoint.GetY() << ")" << endl;

	return 0;
}