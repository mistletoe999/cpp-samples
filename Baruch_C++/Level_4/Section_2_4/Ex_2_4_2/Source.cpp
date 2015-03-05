// Ex_2_4_2: Demonstrates the use of operator overloading
// Extends the Point class updated till Section 2_3
// EDIT from Ex 2.4.1: Using ostream operator instead of 
// ToString() member function everywhere

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() 
{
	Point p(1.0, 2.0);
	cout << "Point initialized: p = " << p << endl;
	cout << "==============================================" << endl;
	// Testing the overloaded unary operator '-':
	cout << "Applying unary '-' operator: " << endl;
	cout << "Negated Point: " << (-p) << endl;
	cout << "==============================================" << endl << endl;

	// Testing the overloaded operator '*':
	cout << "Applying '*' scale operator: " << endl;
	cout << "Scaled Point by factor 2: " << (p * 2) << endl;
	cout << "==============================================" << endl << endl;

	// Testing the + operator
	cout << "Applying '+' operator" << endl;
	cout << "p + Point(2.5, 3.5) = " << (p + Point(2.5, 3.5)) << endl;
	cout << "==============================================" << endl << endl;

	// Testing the == operator
	Point q(2.0, 3.0);
	Point r(1.0, 2.0);
	bool pointEqual = p == q;
	cout << "Testing == operator with q = " << q << " and r = " << r << endl;
	cout << "p == q yields " << ((p == q) ? "TRUE":"FALSE") << endl;
	cout << "p == r yields " << ((p == r) ? "TRUE": "FALSE") << endl;
	cout << "==============================================" << endl << endl;

	// Testing the assignment operator
	p = r = q; // operator can be chained
	cout << "Testing the assignment operator" << endl;
	cout << "p = r = q makes p =  " << p << endl;
	cout << "==============================================" << endl << endl;

	// Testing the scale and assign operator;
	p *= 2;
	cout << "Testing the *= operator" << endl;
	cout << "p *= 2 makes p = " << p << endl;
	cout << "==============================================" << endl << endl;

	// Testing the assignment operator for Lines
	cout << "Testing the assignment operator for Line object" << endl;
	Line line1(Point(0, 0), p);
	Line line2(p, r);
	cout << "Line 1: \n" << line1 << endl;
	cout << "Line 2: \n" << line2 << endl;
	line1 = line2; // Using the assigment operator
	cout << "line1 = line2 yields Line 1: " << line1 << " and Line 2:" << endl << line2 << endl;
	cout << "==============================================" << endl << endl;

	// Testing the assignment operator for Lines
	cout << "Testing the assignment operator for Circle object" << endl;
	Circle c1(p, 10.0);
	Circle c2(q, 12.0);
	cout << "Circle 1: \n" << c1 << endl;
	cout << "Circle 2: \n" << c2 << endl;
	c1 = c2; // Using the assigment operator
	cout << "c1 = c2 yields Circle 1: " << c1 << " and Circle 2:" << endl << c2 << endl;
	cout << "==============================================" << endl << endl;

	return 0;
}