// Ex 3.4.1: Shows the implementation and importance of colon syntax

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
using namespace std;

int main()
{
	// Shape, Point, Line and Circle classes lie in the CAD namespace under 
	// KAPIL namespace
	using namespace KAPIL::CAD;
	Line l;
	return 0;

	// Solution: 
	// 1. Before Colon Syntax
	// ======================
	//Default Point Constructor
	//Default Point Constructor
	//Point Constructor - Values
	//Point Assignment Operator
	//Point Destructor
	//Point Constructor - Values
	//Point Assignment Operator
	//Point Destructor
	//Point Destructor
	//Point Destructor

	// 2. After Colon Syntax: with reduced number of constructor calls
	// =====================
	//Point Constructor - Values
	//Point Constructor - Values
	//Point Destructor
	//Point Destructor

}