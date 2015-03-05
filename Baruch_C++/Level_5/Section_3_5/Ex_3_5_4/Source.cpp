// Ex 3.5.4: Demostrates the use of Abstract functions and classes

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
using namespace std;

int main()
{
	using namespace KAPIL::CAD;
	// Shape s; // Not possible
	Shape * shapes[10];

	// Initiate objects on the heap
	for (int i = 0; i < 10; i++) {
		if (i % 3 == 0) {
			shapes[i] = new Point(i, 2*i);
		}
		else if (i % 3 == 1) {
			shapes[i] = new Line(Point(), Point(2*i, 2*i + 1));
		}
		else {
			shapes[i] = new Circle(Point(), i);
		}
	}

	// Call the Draw function for all the object
	for (int i = 0; i < 10; i++) {
		shapes[i]->Draw();
	}

	// Delete the objects
	for (int i = 0; i < 10; i++) {
		delete shapes[i];
	}

	return 0;

}