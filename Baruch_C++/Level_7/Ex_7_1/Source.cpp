// Exercise 7.1: STL Containers
// Practice with the STL container list, vector and map

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

int main()
{
	// Part 1: Add data to list and get the first and the last element
	cout << "Practice with list class" << endl;
	cout << "========================" << endl;

	int numEntries = 4;

	// Create a list and add data
	list<double> li;
	li.push_back(1.03);
	li.push_back(2.5);
	li.push_back(4.3);
	li.push_back(3.78);
	li.push_back(9.34);


	// Get first and last elements of the list
	cout << "First element in list: " << li.front() << endl;
	cout << "Last element in list: " << li.back() << endl;

	cout << endl;

	cout << "Practice with vector class" << endl;
	cout << "==========================" << endl;

	// Create a vector and add data
	vector<double> vect;
	vect.push_back(1.23);
	vect.push_back(4.56);
	vect.push_back(7.89);
	vect.push_back(12.34);

	// Display data using the index operator
	for (int i = 0; i < vect.size(); i++)
	{
		cout << "Element " << (i + 1) << ": " << vect[i] << endl;
	}

	// Grow the vector: Add 'numEntries' new values
	cout << "Grow with vector" << endl;

	// Grow the vector
	for (int i = 1; i < numEntries + 1; i++)
	{
		vect.push_back(i*3.5);
	}

	// Display all the entries in the changed vector
	cout << "New entries: " << endl;
	for (int i = 0; i < vect.size(); i++)
	{
		cout << "Element " << (i + 1) << ": " << vect[i] << endl;
	}

	cout << "Practice with map class" << endl;
	cout << "=======================" << endl;

	// Create a map with string key and integer value
	map<string, double > m;

	// Insert entries into the map
	m.insert(make_pair("New York", 10.50));
	m.insert(make_pair("Chicago", 12.50));
	// Another way
	m["San Francisco"] = 3.50;
	
	// Display the values of map
	cout << "m[\"New York\"]: " << m["New York"] << endl;
	cout << "m[\"Chicago\"]: " << m["Chicago"] << endl;
	cout << "m[\"San Francisco\"]: " << m["San Francisco"] << endl;

	return 0;

}

