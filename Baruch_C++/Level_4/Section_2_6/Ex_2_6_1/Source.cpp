// Ex 2.6.1: Demostrates the use of namespaces

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

int main()
{
	// Using full namespace for the Point class
	KAPIL::CAD::Point p1(1.5, 2.5);
	KAPIL::CAD::Point origin;

	cout << "Full namespace for Point class" << endl;
	cout << "=============================================" << endl;
	cout << p1 << endl;

	// Using declaration for single class
	using KAPIL::CAD::Line;
	
	cout << "Using 'using' declaration for single class" << endl;
	cout << "=============================================" << endl;
	
	Line line(origin, p1);
	cout << line << endl;

	using namespace KAPIL::Containers;
	cout << "Using 'using' declaration for namespace" << endl;
	cout << "=============================================" << endl;

	Array * arr = new Array(3);
	for (int i = 0; i < 3; i++) {
		cout << "(*arr)[" <<  i << "]= " << (*arr)[i] << endl;
	}

	delete arr;
	arr = 0;

	cout << "Using shorter alias" << endl;
	cout << "=============================================" << endl;

	namespace KC = KAPIL::CAD;
	KC::Circle c(origin, 5.0);
	cout << c << endl;

	return 0;
}