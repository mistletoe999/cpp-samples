// Ex 2.3.5: Demonstrates the use two classes at the same time
// Loads Line.hpp and Point.hpp, which contain definitions for 
// Line and Point classes, respectvely


#include "Line.hpp"
#include "Point.hpp"

int main() {
	// Initiate points to be used for creating line segments
	Point p1(1.0, 2.0);
	Point p2(4.0, 3.0);

	// Define instances of Line class
	// ##1
	Line newLine; // Define using the default constructor and Start & End functionsS 
	newLine.Start(p1);
	newLine.End(p2);
	// ##2
	Line newLine2(p1, p2); // Define using p1 and p2 directly
	// ##3
	Line newLine3 = newLine2; // Define using the copy constuctor;

	// Display information about the three Line objects
	cout << "Line Segment 1: " << newLine.ToString() << endl;
	cout << "Line Segment 2: " << newLine2.ToString() << endl;
	cout << "Line Segment 3: " << newLine3.ToString() << endl;

	// Display the corresponding lengths
	cout << "Length of the line segment 1: " << newLine.Length() << endl;
	cout << "Length of the line segment 2: " << newLine2.Length() << endl;
	cout << "Length of the line segment 3: " << newLine3.Length() << endl;

	return 0;

	//  OUTPUT:
	//  Line Segment 1: Line Segment between Point(1, 2)
	//	and Point(4, 3)

	//	Line Segment 2 : Line Segment between Point(1, 2)
	//	and Point(4, 3)

	//	Line Segment 3 : Line Segment between Point(1, 2)
	//	and Point(4, 3)

	//	Length of the line segment 1 : 3.16228
	//	Length of the line segment 2 : 3.16228
	//	Length of the line segment 3 : 3.16228
}