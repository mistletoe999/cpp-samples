// Ex 4.2A.1: Basic Template Programming
// Convert the Array class into a template
// so that it can take any of the Point, Line 
// or Circle object

#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"
#include "Array.hpp" // Need to include the header file only -
// if the hpp file has the 
// #ifndef #endif block
// Required block in .hpp file
//=============================
// #ifndef Array_cpp
// #include "Array.cpp"
// #endif
//=============================
// If the block does not exist in the header file,
// include the cpp file


#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
using namespace std;

int main()
{
	// All shapes objects are in KAPIL::CAD namespace
	using namespace KAPIL::Containers;
	using namespace KAPIL::CAD;
	
	// Initiate an array of points
	unsigned int size = 3;
	cout << "Created an array of points with size = " << size << endl;
	cout << "========================================" << endl;

	cout << "Testing Setters, Getters, and Indexing operetor" << endl;
	cout << "========================================" << endl;

	Array<Point> points(size);

	for (int i = 0; i != size; i++) 
	{
		cout << "points.GetElement(i) = " << points.GetElement(i) << endl;
		points.SetElement(i, Point(1.3*i, 1.4*i));
		cout << "New points.GetElement(i) = " << points.GetElement(i) << endl;
		cout << "New points[i] = " << points[i] << endl;
	}

	cout << "Testing the copy constructor" << endl;
	cout << "========================================" << endl;

	Array<Point> points2(points);

	for (int i = 0; i != size; i++)
	{
		cout << "New points2[i] = " << points2[i] << endl;
	}

	cout << "Testing the Size function" << endl;
	cout << "========================================" << endl;

	cout << "Size of points2 = " << points2.Size() << endl;

	cout << "Testing the assignment operator" << endl;
	cout << "========================================" << endl;

	Array<Point> points3;

	points3 = points2;

	for (int i = 0; i != size; i++)
	{
		cout << "New points3[i] = " << points3[i] << endl;
	}

	/*
	//cout << "Testing the Array template class for other classes: Lines" << endl;
	//cout << "=========================================================" << endl;

	//Array<Line> lines;
	//for (int i = 0; i != lines.Size(); i++) {
	//	cout << lines[i].ToString() << endl;

	//}

	//cout << "Testing the Array template class for other classes: Circles" << endl;
	//cout << "===========================================================" << endl;

	//Array<Circle> circles;
	//for (int i = 0; i != circles.Size(); i++) {
	//	cout << circles[i].ToString() << endl;
	//}

	//cout << "Testing the Array template class for other classes: double" << endl;
	//cout << "===========================================================" << endl;

	//Array<double> d;
	//for (int i = 0; i != d.Size(); i++) {
	//	cout << d[i] << endl;
	//}
	*/

	return 0;

}