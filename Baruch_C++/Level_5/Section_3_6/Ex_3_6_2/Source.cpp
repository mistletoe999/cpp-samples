// Ex 3.6.2: Demonstration of Exception Handling
// Use Exception Handling to check array bouns
// EDIT from Ex 3.6.1: Implemented the OutOfBoundException class


#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
using namespace std;

int main()
{
	// All shapes objects are in KAPIL::CAD namespace
	using namespace KAPIL::Containers;
	
	// Initiate an array of points
	unsigned int arraySize = 3;
	cout << "Created an array of points with size = " << arraySize << endl;
	Array * arr = new Array(arraySize);

	// Set elements of the array
	for (int i = 0; i < arraySize; i++)
	{
		arr->SetElement(i, KAPIL::CAD::Point(i, i + 1));
	}

	// Testing
	cout << "Testing SetElement: Try to set an out of bounds element" << endl;
	cout << "=======================================================" << endl;

	// Without the try-catch blocks, the program throws an exception 
	// and the program stops running 

	// Testing the GetElement function
	try 
	{
		arr->SetElement(arraySize + 2, KAPIL::CAD::Point());
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	cout << "Testing GetElement: Try to get an out of bounds element" << endl;
	cout << "=======================================================" << endl;

	try
	{
		arr->GetElement(arraySize + 5);
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	delete arr;

	return 0;

}