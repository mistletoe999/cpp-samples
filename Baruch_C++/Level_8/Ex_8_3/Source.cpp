// Ex 8.3: Variants:
// Use variants to store diferent types shape objects


// Includes
// Standard Headers

#include <iostream>
#include <string>

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
#include "Visitor.hpp"

// Boost Headers
#include <boost/variant.hpp>
#include <boost/variant/apply_visitor.hpp>

// Namespaces
using namespace std;
using namespace KAPIL::CAD; // For Point, Line and Circle

// Typedefs
typedef boost::variant<Point, Line, Circle> ShapeType;

// Functions
ShapeType get_variant(int option = -1)
{
	ShapeType sType;
	// If user does not give any input in 1,2,or 3, 
	// then function asks for an input
	if (option != 1 && option != 2 && option != 3)
	{
		cout << "Please select the type of object: (1) Point, (2) Line, (3) Circle): ";
		cin >> option;
	}

	switch (option)
	{
	case 1:
		sType = Point();
		break;
	case 2:
		sType = Line();
		break;
	case 3:
		sType = Circle();
		break;
	default:
		//cout << "Invalid option. Default value returned" << endl;
		//sType = Point();
		break;
	}

	return sType;
}


int main()
{
	// PART I
	// Tesing Variants


	cout << "PART I" << endl;

	using boost::variant;
	// Create a new shape variant
	ShapeType newShape = get_variant();
	// Print the type of object selected by the user 
	if (Point* point = boost::get<Point>(&newShape))
	{
		cout << "Variant is a point\n" << point->ToString() << endl;
	}
	else if (Line* line = boost::get<Line>(&newShape))
	{
		cout << "Variant is a line\n" << line->ToString() << endl;
	}	
	if (Circle* circle = boost::get<Circle>(&newShape))
	{
		cout << "Variant is a circle\n" << circle->ToString() << endl;
	}

	// Check the bad_get exception
	cout << "Let us assign a new variant variable to newShape" << endl;
	newShape = get_variant(1);

	try
	{
		newShape = boost::get<Line>(newShape);
	}
	catch (boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl;
	}

	// PART II
	// Test the Visitor class

	cout << "PART II" << endl;

	// Create a line, circle and point objects
	Point newPoint(3, 3);
	Line newLine(Point(1, 1), Point(2, 2));
	Circle newCircle(newPoint, 2);

	newShape = newPoint;
	// Create a visitor class instance

	Visitor visitor(5, 5);

	// Use it on Point 
	cout << boost::get<Point>(&newShape)->ToString() << endl;
	boost::apply_visitor(visitor, newShape);
	cout << boost::get<Point>(&newShape)->ToString() << endl;

	// Use it on Circle
	newShape = newCircle;
	cout << boost::get<Circle>(&newShape)->ToString() << endl;
	boost::apply_visitor(visitor, newShape);
	cout << boost::get<Circle>(&newShape)->ToString() << endl;

	// Use it on Line
	newShape = newLine;
	cout << boost::get<Line>(&newShape)->ToString() << endl;
	boost::apply_visitor(visitor, newShape);
	cout << boost::get<Line>(&newShape)->ToString() << endl;


	return 0;
}