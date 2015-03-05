// Ex 3.5.3: Demostrates the importance of declaring the destructors as virtual

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
	Shape* shapes[3];
	
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];
	return 0;

	// SOLUTION: (I) Before declaring the Shape class destructor as virtual
	//Shape Destructor
	//Shape Destructor
	//Shape Destructor
	// Correct destructor is not called since only the 
	// Shape part of the Point and Line pointers are deleted

	// (II) After declaring the Shape class destrcutor as virtual
	//Shape Destructor
	//Point Destructor
	//Shape Destructor
	//Line Destructor
	//Point Destructor
	//Shape Destructor
	//Point Destructor
	//Shape Destructor
	//Shape Destructor

	// Correct version of Destructors called. First the derived part memory deleted and then 
	// the Shape class memory is deleted

}