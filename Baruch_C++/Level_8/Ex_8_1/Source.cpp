// Ex 8.1: Smart Pointers
// Test the functionality of smart/shared pointers

// Includes
// Standard Headers

#include <iostream>

// Project Headers
#include "Array.hpp"
#include "ArrayException.hpp"
#include "Circle.hpp"
#include "DifferentSizeException.hpp"
#include "Line.hpp"
#include "NumericArray.hpp"
#include "OutOfBoundsException.hpp"
#include "Point.hpp"
#include "PointArray.hpp"
#include "Shape.hpp"
#include "Stack.hpp"
#include "StackEmptyException.hpp"
#include "StackException.hpp"
#include "StackFullException.hpp"

// Boost Headers

#include <boost/shared_ptr.hpp>

// Namespaces
using namespace std;
using namespace KAPIL::CAD;
using namespace KAPIL::Containers;


// Typedefs

// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main()
{

	
	// Define a scope to see the reference count of the shared_ptr

	ShapeArray shapeArray(3);

	{
		// Define 3 shape objects	
		ShapePtr point(new Point(1, 1));
		cout << point->ToString() << endl;

		ShapePtr line(new Line(Point(0, 0), Point(0, 3)));
		cout << line->ToString() << endl;

		ShapePtr circle(new Circle(Point(4, 4), 5.0));
		cout << circle->ToString() << endl;
		shapeArray[0] = point;
		shapeArray[1] = line;
		shapeArray[2] = circle;

		// Check Reference Counts
		for (int i = 0; i < shapeArray.Size(); i++)
		{
			cout << shapeArray[i]->ToString() << endl;
			cout << "Refernce Count of individual smart pointer: " 
				<< shapeArray[i].use_count() << endl; //2
 		}
	}

	cout << "\nOutside of the scope" << endl;
	// Check reference count again
	// One refernce to each smart pointer should be deleted now
	// SHould print 1 for each
	for (int i = 0; i < shapeArray.Size(); i++)
	{
		cout << "Refernce Count of individual smart pointer: "
			<< shapeArray[i].use_count() << endl; //1
	}

	return 0;
}