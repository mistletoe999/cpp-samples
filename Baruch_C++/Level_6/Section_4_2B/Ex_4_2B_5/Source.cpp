// Ex 4.2B.5: Add StackOverflow and StackUnderflow derived classes under
// StackException Base class

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

	Stack<int> s; // Initiates a stack with m_array size = 5 and m_current pointing to 0
	cout << "Stack: \n Default Size: 5\n";

	// Push five elements
	cout << "Pushing 5 elements into the stack" << endl;
	s.Push(1.0);
	s.Push(1.0);
	s.Push(1.0);
	s.Push(1.0);
	s.Push(1.0);
	// m_current = 5

	cout << "Pushing one more element" << endl;
	// Should cause stack overflow
	try
	{
		s.Push(1.0);
	}
	catch (StackException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	// Check pull function
	cout << s.Pull() << endl;
	// Push the element again
	s.Push(1.0);
	// m_current = 5

	cout << "Pull 6 elements from stack and display" << endl;
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
	catch (StackException& ex)
	{
		cout << ex.GetMessage() << endl;
	}


	// Check Stack with size constructor

	Stack<int> s2(12);
	return 0;

}