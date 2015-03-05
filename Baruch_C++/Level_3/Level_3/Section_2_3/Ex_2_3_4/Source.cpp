// Ex 2.3.3: Improves upon the Point class defined in Section 2.2
// Point class defined in 'Point.hpp'
// This program demonstrates the use of const
// keyword

#include <iostream>
#include <string>
#include <sstream>
#include "Point.hpp"
using namespace std;


int main() {
	double xValue, yValue;

	cout << "Defining Point cp(1.5, 3.9)" << endl;
	const Point cp(1.5, 3.9);

	// Check 1
	// cp.X(0.3); // Causes compiler error
	// Check 2
	cout << "Printing X-coordinate of cp" << endl;
	cout << cp.X() << endl;

	return 0;

}