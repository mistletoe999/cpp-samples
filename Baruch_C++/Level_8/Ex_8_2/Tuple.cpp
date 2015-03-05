// Ex 8.1: Create a tuple and print its values

// Standard Includes
#include <iostream>
#include <string>
#include <vector>

// Boost Includes
#include <boost\tuple\tuple.hpp>
#include <boost\tuple\tuple_io.hpp>

// Namespaces
using namespace std;
using boost::tuple;

// Typedefs
typedef boost::tuple <string, int, double> Person;

void printPerson(const Person& person) 
{
	cout << "=================\nName: " << get<0>(person) << 
		"\nAge: " << get<1>(person) << 
		"\nLength: " << get<2>(person) << "\n=================" << endl;
}

int main()
{
	// Create a vector of Person tuples
	vector<Person> persons;

	// push back new Person tuples into the vector persons
	persons.push_back(Person(string("John"), 23, 172.45));
	persons.push_back(Person(string("Mark"), 25, 182.55));
	persons.push_back(Person(string("Oliver"), 28, 162.00));
	persons.push_back(Person(string("Andy"),18, 185.00));

	for (int i = 0; i < persons.size(); i++)
	{
		cout << "Person " << (i + 1) << endl;
		printPerson(persons[i]);
	}

	Person newPerson(string("Kapil"), 27, 170.10);
	printPerson(newPerson);
	// Increment the age of newPerson tuple
	get<1>(newPerson) += 1;
	cout << "Incrementing the age of Kapil" << endl;
	printPerson(newPerson);

	return 0;

}