// Ex 7.3:
// STL Algorithms: Test count_if algo with a global function and 
// a functor

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include "CheckSmaller.hpp"
using namespace std;

template <typename T>
bool isSmaller(T toCheck, T val)
{
	return (toCheck < val);
}



int main()
{
	vector<double> vect;
	vect.push_back(1.20);
	vect.push_back(2.40);
	vect.push_back(3.40);
	vect.push_back(2.56);
	vect.push_back(3.23);
	vect.push_back(7.56);
	vect.push_back(1.23);



	cout << "Defined Vector: { ";
	for (vector<double>::const_iterator iter = vect.cbegin(); iter != vect.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << " }" << endl;

	// PART 1: Using a global function

	// Get user input for the value to check against
	double checkValue;
	cout << "Enter the value to check against: ";
	cin >> checkValue;

	// Get the total number of elements in the vector less than checkValue
	// NOTE: bind works only in C++ 11
 	int totalNum = count_if(vect.cbegin(), vect.cend(), bind(isSmaller<double>, placeholders::_1, checkValue));


	// Print the number of values
	cout << "Number of values in vect less than " << checkValue << ": " << totalNum << endl;

	// PART II: Using a function object

	// Create a function object
	CheckSmaller<double> check(checkValue);

	// Now we can directly assign the functor to the count_if algorithm
	totalNum = count_if(vect.cbegin(), vect.cend(), check);

	// Print the number of values
	cout << "Number of values in vect less than " << checkValue << ": " << totalNum << endl;

	return 0;
}
