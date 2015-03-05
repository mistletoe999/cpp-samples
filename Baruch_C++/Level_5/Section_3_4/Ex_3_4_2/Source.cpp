// Ex 3.4.2: Demostrates the implementation of Basic Inheritance

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
	
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.
	cout << s.ToString() << endl; // Print shape.
	cout << p.ToString() << endl; // Print point.
	cout << l.ToString() << endl; // Print line
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?
	// ****ANSWER: YES
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?

	// ****ANSWER: YES
	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible?

	// ****ANSWER: YES, Shape pointer can point to any of its derived classes.
	cout << sp->ToString() << endl; // What is printed?

	// ****ANSWER: Calls the Shape version of ToString to print the ID of p.
	// This is because, as a base pointer sp can only access the base version (Shape) of the derived class (Point)
	
	//// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
	// The base class assignment in point?

	// ****ANSWER: No, the ID is not copied, if the base classs assignment 
	// is not called in the assignment operator of the point

	return 0;

	//=================================================================
	//// Self Testing

	//// Create a Shape object and test its functions first
	//Shape s;
	//cout << "Testing the Shape s object" << endl;
	//cout << "===================================" << endl;
	//cout << "s.ID() returns " << s.ID() << endl;
	//cout << "s.ToString() returns " << s.ToString() << endl;
	//Shape t = s;
	//cout << "Shape t = s" << endl;
	//cout << "t.ToString() returns " << t.ID() << endl << endl;

	//Point p, r;
	//cout << "Testing the Point class" << endl;
	//cout << "===================================" << endl;
	//cout << "Point p, r" << endl;
	//cout << "p.ToString() returns " << p.ToString() << endl;
	//cout << "r.ToString() returns " << r.ToString() << endl;
	//cout << "Point q = p" << endl;
	//Point q = p;
	//cout << "q.ToString() returns " << q.ToString() << endl;
	//r = q;
	//cout << "r = q" << endl;
	//cout << "r.ToString() returns " << r.ToString() << endl << endl;

	//Line l, m;
	//cout << "Testing the Line class" << endl;
	//cout << "===================================" << endl;
	//cout << "Line l, m" << endl;
	//cout << "l.ToString() returns " << l.ToString() << endl;
	//cout << "m.ToString() returns " << m.ToString() << endl;
	//cout << "Line n = l" << endl;
	//Line n = l;
	//cout << "n.ToString() returns " << n.ToString() << endl;
	//n = m;
	//cout << "n = m" << endl;
	//cout << "n.ToString() returns " << n.ToString() << endl << endl;

	//Circle c(p, 4.0), d(Point(), 5.0);
	//cout << "Testing the Circle class" << endl;
	//cout << "===================================" << endl;
	//cout << "Circle c(p, 4.0), d(q, 5.0);" << endl;
	//cout << "c.ToString() returns " << c.ToString() << endl;
	//cout << "d.ToString() returns " << d.ToString() << endl;
	//cout << "Circle e = d" << endl;
	//Circle e = d;
	//cout << "e.ToString() returns " << e.ToString() << endl;
	//c = d;
	//cout << "c = d" << endl;
	//cout << "c.ToString() returns " << c.ToString() << endl << endl;
}