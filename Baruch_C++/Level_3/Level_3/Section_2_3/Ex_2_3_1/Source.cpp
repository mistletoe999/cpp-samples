// Ex 2.3.1: Improve upon the Point class defined in Section 2.2
// Point class defined in 'Point.hpp'
// This program demonstrates the copy constructor

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

	// Create a default Point object
	// Copy Constructor is called while the distance is calculated and after calculation
	// destructor is called

	cout << "The distance of Point 2 from Point 1: " << point1.Distance(point2) << endl;
	
	return 0;

	//  Answer to part 1: *******BEFORE DEFINING COPY CONSTRCUTOR***********
	//  Checking the number of times constructor and destructors are called
	//  Number of times constructor called is not equal to number of times destructor is called 

	//Enter the X - coordinate of Point 1: 12.0
	//Enter the Y - coordinate of Point 1 : 12.0
	//Calling Constructor..
	//Enter the X - coordinate of Point 2 : 13.0
	//Enter the Y - coordinate of Point 2 : 13.0
	//Calling Constructor..
	//Returning distance..
	//Calling Destructor..
	//The distance of Point 2 from Point 1 : 1.
	//Calling Destructor..
	//Calling Destructor..

	//  Answer to part 2: *******AFTER DEFINING COPY CONSTRCUTOR***********
	//  Checking the number of times constructor and destructors are called
	//  Number of times constructor called is equal to number of times destructor is called
	//	Copy Constructor is called once, when distance is calculated

	//Enter the X - coordinate of Point 1: 12.0
	//Enter the Y - coordinate of Point 1 : 12.0
	//Calling Constructor..
	//Enter the X - coordinate of Point 2 : 13.0
	//Enter the Y - coordinate of Point 2 : 14.0
	//Calling Constructor..
	//Calling Copy Constructor.. ****Another Cosntructor Call
	//Returning distance..
	//Calling Destructor..
	//The distance of Point 2 from Point 1 : 2.23607
	//
	//Calling Destructor..
	//Calling Destructor..


}