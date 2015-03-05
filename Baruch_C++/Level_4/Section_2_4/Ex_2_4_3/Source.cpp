// Ex_2_4_3: Demonstrates use of Constructors as conversion operator

#include "Point.hpp"

int main() 
{
	
	Point p(1.0, 1.0);
	// if (p == 1.0) cout << "Equal!" << endl; 	// Compiles without explicit declaration
	if (p == (Point)1.0) cout << "Equal!" << endl; // Now need to explicitly use constructor as conversion operator
	else cout << "Not equal" << endl;
	return 0;
}