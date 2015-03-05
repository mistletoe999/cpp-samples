// Exercise 7.2: STL Iterators

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

// Sum functions for List and Vectors

// Sum function with container as parameter
template <typename T>
double Sum(const T& cont)
{
	double sum = 0;
	T::const_iterator it = cont.end();
	for (T::const_iterator iter = cont.begin(); iter != it; ++iter)
	{
		sum += *iter;
	}
	return sum;
}

// Sum function with const_iterator as parameters
template <typename T>
double Sum(typename const T::const_iterator& startIt, typename const T::const_iterator& endIt)
{
	double sum = 0;

	for (T::const_iterator iter = startIt; iter != endIt; ++iter)
	{
		sum += *iter;
	}
	return sum;
}


// Overloaded Sum functions for Maps
// Function with general map as parameter
template <typename T1, typename T2>
double Sum(const map<T1, T2> m)
{
	double sum = 0;
	map<T1, T2>::const_iterator it = m.end();
	for (map<T1, T2>::const_iterator iter = m.begin(); iter != it; ++iter)
	{
		sum = sum + iter->second;
	}
	return sum;
}

template <typename T1, typename T2>
double Sum(typename const map<T1, T2>::const_iterator& startIt, typename const map<T1, T2>::const_iterator& endIt)
{
	double sum = 0;

	for (map<T1, T2>::const_iterator iter = startIt; iter != endIt; ++iter)
	{
		sum += iter->second;
	}
	return sum;
}


int main()
{
	list<double> li;
	li.push_back(1.00);
	li.push_back(2.00);
	li.push_back(3.00);
	li.push_back(3.50);
	li.push_back(3.50);

	vector<double> vect;
	vect.push_back(3.00);
	vect.push_back(4.00);
	vect.push_back(3.00);
	vect.push_back(4.50);

	map<string, double > cities;

	// Insert entries into the map
	cities.insert(make_pair("New York", 10.50));
	cities.insert(make_pair("Chicago", 12.50));
	cities["San Francisco"] = 3.50;

	cout << Sum(li) << endl;
	cout << Sum(vect) << endl;
	cout << Sum(cities) << endl;


	// Testing the sum function with const_iterators as parmeters
	// For list
	list<double>::const_iterator listIter1 = li.begin();
	list<double>::const_iterator listIter2 = li.end();

	++listIter1;

	--listIter2;

	cout << Sum<list<double>>(listIter1, listIter2) << endl;

	// For Vector
	vector<double>::const_iterator vectIter1 = vect.begin();
	vector<double>::const_iterator vectIter2 = vect.end();

	++vectIter1;

	cout << Sum<vector<double>>(vectIter1, vectIter2) << endl;

	// For map
	map<string, double>::const_iterator mapIter1 = cities.begin();
	map<string, double>::const_iterator mapIter2 = cities.end(); 

	++mapIter1;

	// Sum of the map elements
	// NOTE TO SELF: calling Sum<map<string, double>> is actually equivalent to Sum<T> 
	// with T equivalent to map<string, double>
	cout << Sum<string, double>(mapIter1, mapIter2) << endl;

	return 0;
}

