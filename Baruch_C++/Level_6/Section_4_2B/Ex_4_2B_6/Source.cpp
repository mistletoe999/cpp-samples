// Ex 4.2B.6: Value Template Arguments:
// Add a size integer template argument to the Stack class

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
#include "PointArray.hpp"
#include "Stack.hpp"
#include "StackException.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"
using namespace std;

int main()
{
	using namespace KAPIL::Containers;
	using namespace KAPIL::CAD;
	
	// Create an instance of the stack class
	Stack<int, 12> s;

	// Make the stack full
	for (int i = 0; i < 12; i++)
	{
		s.Push(i);
	}
	// Push anaother element: Should cause stack overflow
	try 
	{
		s.Push(100);
	}
	catch (StackException& ex)
	{
		cout << ex.GetMessage() << endl;
	}


	// Pull all elements from Stack and print them on console
	for (int i = 0; i < 12; i++)
	{
		cout << s.Pull() << endl;
	}
	// Try another Pull: Should cause stack underflow
	try
	{
		cout << s.Pull() << endl;
	}
	catch (StackException& ex)
	{
		cout << ex.GetMessage() << endl;
	}


	return 0;

}