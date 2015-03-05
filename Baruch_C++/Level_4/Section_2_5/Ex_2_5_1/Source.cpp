// Ex_2.5.1: Demonstrates the use of dynamic memory alocation
// for classes

#include "Point.hpp"

int main() {

	cout << "PART 1: Initialize Point objects on the heap" << endl;
	cout << "============================================" << endl << endl;

	// Initializing Point objects in the heap
	Point * p1 = new Point();			// Using Default Constructor
	Point * p2 = new Point(1.0, 2.0);	// Using Constructor with coordinates
	Point * p3 = new Point((*p2));		// Using Copy Constructor
	
	double d1 = (*p1).Distance();		// Can also call p1-> instead of (*p1).
	double d2 = (*p2).Distance();		// Can also call p1-> instead of (*p1).
	double d3 = (*p3).Distance();		// Can also call p1-> instead of (*p1).

	cout << "Points Initialized are : \nP1:" << (*p1) << "\tP2:" << (*p2) << "\tP3:" << (*p3) << endl;
	cout << "Calling Distance() function, distances from the origin: " << endl;
	cout << "P1: " << d1 << ", P2: " << d2 << ", P3: " << d3 << endl;

	// Delete the Point objects initialized on the heap  
	delete p1;
	p1 = 0;
	delete p2;
	p2 = 0;
	delete p3;
	p3 = 0;


	cout << "PART 2: Initialize Point array on the heap" << endl;
	cout << "============================================" << endl << endl;

	unsigned int arraySize;
	cout << "Please enter the array size: " << endl;
	cin >> arraySize;
	//Point p[arraySize];		Does not run. Causes Compiler Error
	
	// Initialize array on the heap
	Point * pointArray = new Point[arraySize]; // Cannot assign any other constructor apart from default constructor
	
	cout << "Initialized array with " << arraySize << " Point objects on the heap" << endl;
	cout << "Deleting the Point Array from the heap" << endl;
	
	// Deleting the pointer
	delete[] pointArray;
	pointArray = 0;

	return 0;
}