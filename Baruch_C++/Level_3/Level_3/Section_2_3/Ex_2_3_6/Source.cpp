// Ex 2.3.6: Demonstrates the use two classes at the same time
// Loads Circle.hpp and Point.hpp, which contain definitions for 
// Circle and Point classes, respectvely

#include "Circle.hpp"
#include "Point.hpp"
using namespace std;

int main() {
	Point centerPoint(2.0, 3.0);
	double circleRadius = 4.0;

	// Could have defined as below
	//Circle circle;
	//circle.Radius(circleRadius);
	//circle.CentrePoint(centerPoint);
	// Circle circle(circleRadius, centerPoint);
	Circle circle(centerPoint, circleRadius);

	// Check all functions
	cout << "Checking all member functions... " << endl;
	cout << "Description:" << endl;
	cout << circle.ToString() << endl;
	cout << "=====================================" << endl;
	cout << "Radius: " << circle.Radius() << endl;
	cout << "Center: " << circle.CentrePoint().ToString() << endl;
	cout << "Diameter: " << circle.Diameter() << endl;
	cout << "Circumference: " << circle.Circumference() << endl;
	cout << "Area: " << circle.Area() << endl;

	return 0;
}
