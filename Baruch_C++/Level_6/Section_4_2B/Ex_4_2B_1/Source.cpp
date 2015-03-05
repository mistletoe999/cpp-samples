// Ex 4.2B.1: Static variable as the array default size
// Implemenet use of static data members and static 
// member functions
// Static data members are constant at class level

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "Array.hpp" 
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
using namespace std;

int main()
{
	// All shapes objects are in KAPIL::CAD namespace
	using namespace KAPIL::Containers;
	using namespace KAPIL::CAD;
	
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;
	intArray1.DefaultSize(15);
	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	// Output
	//5
	//5
	//5
	//15
	//15
	//5

	// Explanation:
	// Intially, all the class/data types have the same
	// default size of 5, since it is a static data member
	// of the class and is same for all the instances
	// of the class
	// After we change the default size for int arrays to 15,
	// all int arrays or class Array<int> have the same 
	// size of 15
	// However, this still does not change the default size 
	// for the class Array<double> since it is a separate
	// class and would only change if we specifically call
	// Setter for default size on a double array

	return 0;

}