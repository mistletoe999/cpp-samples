// Ex 2.3.2: Improves upon the Point class defined in Section 2.2
// Point class defined in 'Point.hpp'
// This program demonstrates the importance of passing 
// objects by reference in member functions

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

	cout << "The distance of Point 2 from Point 1: " << point1.Distance(point2) << endl;
	// point2 is called by reference and hence cpy constructor would not be calles

	return 0;

	// ****Passing By Reference****
	// No copy constructor called

	//Enter the X - coordinate of Point 1: 12.0
	//Enter the Y - coordinate of Point 1 : 12.0
	//Calling Constructor..
	//Enter the X - coordinate of Point 2 : 13.0
	//Enter the Y - coordinate of Point 2 : 14.0
	//Calling Constructor..
	//Returning distance.. *****No Copy Constructor Called****
	//The distance of Point 2 from Point 1 : 2.23607
	//Calling Destructor..
	//Calling Destructor..
}