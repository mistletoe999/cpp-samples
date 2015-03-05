// Ex 4.2B.2: Numeric Array (generic inheritance)
// =========================================================
// Assumptions Made: 
// + operator is defined for the individual objects in the array
// * operator is defined for the objects in the array
// The objects can be multiplied to constant value 
// All classes created using template Array<T> have their 
// individual assignment operators defined
// ==========================================================

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "Array.hpp" 
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "DifferentSizeException.hpp"
#include "NumericArray.hpp"
using namespace std;

int main()
{
	using namespace KAPIL::Containers;
	using namespace KAPIL::CAD;
	
	// Create an instance of NumericArray class
	cout << "Create a NumericArray class instance" << endl;
	cout << "====================================" << endl;

	NumericArray<int> arr;
	for (int i = 0; i != arr.Size(); i++) 
	{
		arr[i] = i;
		cout << arr[i] << endl;
	}

	// Test the different size exception
	cout << "Testing the different size exception" << endl;
	cout << "====================================" << endl;

	NumericArray<int> arr2(4);
	for (int i = 0; i != arr2.Size(); i++)
	{
		arr2[i] = i;
	}

	// Should throw an exception
	try 
	{
		cout << "Dot Product: " << arr.DotProduct(arr2) << endl;
	}
	catch (ArrayException& ex) {
		cout << ex.GetMessage() << endl;
	}

	// Again, trying to add different sized arrays
	// Should throw and exception

	NumericArray<int> sumArr;

	try
	{
		sumArr = arr + arr2;
	}
	catch (ArrayException& ex) {
		cout << ex.GetMessage() << endl;
	}

	
	// Test the multiplication operator
	cout << "Testing the Multiplication operator" << endl;
	cout << "Multiply arr by 2 and assign to arr2" << endl;
	cout << "===================================" << endl;

	arr2 = arr * 2;

	cout << "Testing the DotProduct function" << endl;
	cout << "===============================" << endl;

	cout << arr.DotProduct(arr2) << endl;

	// Check whether we can create a NumericArray for Point objects
	// NO, we can't. Since, we do not have functionality for 
	// multiplication of two points, and hence the DotProduct 
	// member function will break


	//NumericArray<Point> arr4;
	//NumericArray<Point> arr5;
	//for (int i = 0; i < arr4.Size(); i++)
	//{
	//	cout << arr4[i] << endl;
	//}

	//cout << arr4.DotProduct(arr5) << endl; // WILL BREAK!!
	return 0;

}