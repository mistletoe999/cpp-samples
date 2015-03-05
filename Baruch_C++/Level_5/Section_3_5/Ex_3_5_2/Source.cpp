// Ex 3.5.2: Shape class ToString function can be accessed by the
// Point, Line and Circle derived classes

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
using namespace std;

int main()
{
	// Shape, Point, Line and Circle classes lie in the CAD namespace under 
	// KAPIL namespace
	using namespace KAPIL::CAD;
	Point p(2.0, 5.0);
	Line l(Point(), p);
	Circle c(p, 5.0);

	cout << "Testing the ToString function with appended ID from Base class" << endl;
	cout << "==============================================================" << endl;
	cout << p.ToString() << endl;
	cout << l.ToString() << endl;
	cout << c.ToString() << endl << endl;
	return 0;
}