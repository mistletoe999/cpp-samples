#include "Point.hpp"
using namespace std;

int main() {
	double xValue, yValue;

	// Get the user input for x and y coordinates for new points
	cout << "Enter the X-coordinate of Point 1: ";
	cin >> xValue;
	cout << "Enter the Y-coordinate of Point 1: ";
	cin >> yValue;
	// Using inline functions to define the point
	Point point1;
	point1.X(xValue);
	point1.Y(yValue);

	cout << "Enter the X-coordinate of Point 2: ";
	cin >> xValue;
	cout << "Enter the Y-coordinate of Point 2: ";
	cin >> yValue;
	// Using inline functions to define the point
	Point point2;
	point2.X(xValue);
	point2.Y(yValue);

	cout << "Point 1: " << point1.ToString() << endl;
	cout << "Point 2: " << point2.ToString() << endl;
	
	return 0;
}