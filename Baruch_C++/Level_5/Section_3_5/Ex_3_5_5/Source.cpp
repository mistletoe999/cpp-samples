// Ex 3.5.5: Template method Pattern

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
using namespace std;

int main()
{
	// All shapes objects are in KAPIL::CAD namespace
	using namespace KAPIL::CAD;

	// Instantiate Point and Line objects
	Point p(10.0, 20.0);
	Line l(Point(), p);

	// Call the print functiosn
	p.Print();
	l.Print();

	return 0;

}