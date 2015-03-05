// Ex_2.5.3: Demonstrates the use of dynamic memory alocation
// for classes
// Implements an Array container class

#include "Point.hpp"
#include "Array.hpp"

int main() {
	// Testing the default constructor
	cout << "Testing the default constructor" << endl;
	cout << "==================================================" << endl;
	Array * arr = new Array();
	delete arr;
	arr = 0;

	cout << endl;

	// Testing the constructor with size parameter
	unsigned int arraySize = 3;
	cout << "Testing the constructor with size parameter = " << arraySize << endl;
	cout << "==================================================" << endl;
	arr = new Array(arraySize);
	delete arr;
	arr = 0;

	cout << "Testing the getter, setter, [], and assignment operator" << endl;
	cout << "==================================================" << endl;

	arr = new Array(arraySize);
	Array * arr1 = new Array();
	for (int i = 0; i < arraySize; i++)
	{
		arr->SetElement(i, Point(i, i + 1));
		cout << "Element " << (i + 1) << " of arr: " << arr->GetElement(i) << endl;
		(*arr1)[i] = Point(2*i, 2*i + 1);
		cout << "Element " << (i + 1) <<  "of arr1: " << (*arr1)[i] << endl;
	}


	*arr1 = *arr; // Checking the assignment operator
	cout << "*arr1 = *arr yields:" << endl;

	for (int i = 0; i < arraySize; i++)
	{
		cout << "Element " << (i + 1) << " of arr1: " << (*arr1)[i] << endl;
	}

	cout << "Testing the copy constructor" << endl;
	cout << "==================================================" << endl;


	Array arr2 = Array(*arr); // Defining arr2 on the stack

	cout << "Initiated arr2 on stack using copy constructor. Size = " << arr2.Size() << endl;

	for (int i = 0; i < arraySize; i++)
	{
		cout << "Element " << (i + 1) << " of arr2: " << arr2[i] << endl;
	}

	cout << "Now, arr = arr1 = arr2; " << arraySize << " destructor calls = " << 3*arraySize << " Point objects deleted" << endl;

	delete arr;
	delete arr1;

	return 0;
}