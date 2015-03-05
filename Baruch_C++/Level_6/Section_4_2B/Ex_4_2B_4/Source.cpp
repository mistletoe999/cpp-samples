// Ex 4.2B.4: Implement a Stack class using the template Array class as the 
// storage 

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
using namespace std;

int main()
{
	using namespace KAPIL::Containers;
	using namespace KAPIL::CAD;

	Stack<int> s; // Initiates a stack with m_array size = 5 and m_current pointing to 0
	
	// Push five elements
	s.Push(1.0);
	s.Push(1.0);
	s.Push(1.0);
	s.Push(1.0);
	s.Push(1.0);
	// m_current = 5
	// Should cause stack overflow
	try
	{
		s.Push(1.0);
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	// Check pull function
	cout << s.Pull() << endl;
	// Push the element again
	s.Push(1.0);
	// m_current = 5

	// Pull all 5 elements
	cout << s.Pull() << endl;
	cout << s.Pull() << endl;
	cout << s.Pull() << endl;
	cout << s.Pull() << endl;
	cout << s.Pull() << endl;
	
	// m_current = 0
	// Should cause stack underflow
	try 
	{
		cout << s.Pull() << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}


	// Check Stack with size parameter
	Stack<int> s2(10);
	return 0;

}