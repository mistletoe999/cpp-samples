// Ex 3.5.1: Demonstrates the use and importance of virtual functions

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

	cout << "Defined derived objects" << endl;
	cout << "=======================" << endl;
	cout << p.ToString() << endl;
	cout << l.ToString() << endl;
	cout << c.ToString() << endl << endl;

	cout << "========================================================" << endl;
	cout << "Assigning Shape pointer object to point, line and circle" << endl;
	cout << "========================================================" << endl;
	cout << "Calling ToString function for the pointer" << endl;

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable.
	cout << sp->ToString() << endl; 
	sp = &l; // Line in a shape variable.
	cout << sp->ToString() << endl; 
	sp = &c; // Circle in a shape variable.
	cout << sp->ToString() << endl; 
	return 0;

	// SOLUTION: (I) Before defining the ToString function as virtual

	//Defined derived objects
	//== == == == == == == == == == == =
	//ID: 41 : (2, 5)
	//ID : 6334 : Line Segment between ID : 18467 : (0, 0) and ID : 41 : (2, 5)
	//ID : 26500 : Circle with Center at ID : 41 : (2, 5) and Radius = 5
	//Circumference : 31.4159
	//Area : 78.5398

	//== == == == == == == == == == == == == == == == == == == == == == == == == == == ==
	//Assigning Shape pointer object to point, line and circle
	//== == == == == == == == == == == == == == == == == == == == == == == == == == == ==
	//Calling ToString function for the pointer
	//ID : 41
	//ID : 6334
	//ID : 26500
	// Note: We see that when we call the ToString function for a Shape 
	// pointer assigned to Point, Line or Circle, the Base version of the
	// ToString function is called.


	// (II) After defining the ToString function as virtual

	//Defined derived objects
	//== == == == == == == == == == == =
	//ID: 41 : (2, 5)
	//ID : 6334 : Line Segment between ID : 18467 : (0, 0) and ID : 41 : (2, 5)
	//ID : 26500 : Circle with Center at ID : 41 : (2, 5) and Radius = 5
	//Circumference : 31.4159
	//Area : 78.5398

	//== == == == == == == == == == == == == == == == == == == == == == == == == == == ==
	//Assigning Shape pointer object to point, line and circle
	//== == == == == == == == == == == == == == == == == == == == == == == == == == == ==
	//Calling ToString function for the pointer
	//ID : 41 : (2, 5)
	//ID : 6334 : Line Segment between ID : 18467 : (0, 0) and ID : 41 : (2, 5)
	//ID : 26500 : Circle with Center at ID : 41 : (2, 5) and Radius = 5
	//Circumference : 31.4159
	//Area : 78.5398

	// NoteL We see that after defining the ToString function as virtual,
	// correct version of the ToString function, even after assigning a Shape 
	// pointer to a Point, Line and Circle object
}