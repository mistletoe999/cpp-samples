// Ex 4.2B.3: Point Array (Concrete Inheritence)
// Specialize the Point Array class derived from
// Array template class

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "Array.hpp" 
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "DifferentSizeException.hpp"
#include "NumericArray.hpp"
#include "PointArray.hpp"
using namespace std;

int main()
{
	using namespace KAPIL::Containers;
	using namespace KAPIL::CAD;

	cout << "Testing the defualt constructor," << endl;
	cout << "PointArray p1" << endl;

	PointArray p1;

	cout << "and the constructor with size" << endl;
	cout << "PointArray p2(4)" << endl;
	cout << "===============================" << endl;
	PointArray p2(4);

	cout << "Testing the copy constructor" << endl;
	cout << "PointArray p3(p2)" << endl;
	cout << "===============================" << endl;

	PointArray p3(p2);

	p1[0] = Point(1, 0);

	cout << "Testing the Length functions" << endl;
	cout << "p1.Length(): " << p1.Length() << endl;
	cout << "===============================" << endl;

	cout << "Testing the assignment operator" << endl;
	p3 = p1;
	cout << "p3 = p1 and printing p3 npw" << endl;
	cout << "===============================" << endl;

	for (int i = 0; i < p3.Size(); i++)
	{
		cout << p1[i] << endl;
	}

	return 0;

}