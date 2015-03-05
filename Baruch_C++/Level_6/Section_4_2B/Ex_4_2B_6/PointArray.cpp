// PointArray.cpp: Implements the PointArray class derived from
// Array template class

#include "PointArray.hpp"
using namespace std;

namespace KAPIL
{
	namespace Containers
	{
		// Default Constructor
		PointArray::PointArray() : Array<Point>() {}

		// Constructor with size
		PointArray::PointArray(unsigned int size) : Array<Point>(size) {};

		// Copy Constructor
		PointArray::PointArray(const PointArray& source) : Array<Point>(source) {}

		// Destructor: All functionality implemented by the base class
		PointArray::~PointArray() {}

		// Length function
		// NOTE: Very loosely defined as the sum of distances 
		// among all the points in the array
		// Have not taken care of the colinearity
		double PointArray::Length()
		{
			double dist = 0;
			for (int i = 0; i < Size(); i++)
			{
				for (int j = i + 1; j < Size(); j++)
				{
					dist += (*this)[i].Distance((*this)[j]);
				}
			}
			return dist;
		}

		// Assignment Operator
		PointArray& PointArray::operator = (const PointArray& source)
		{
			// Self Assignment Check
			if (this == &source)
			{
				return *this;
			}

			Array<Point>::operator=(source);

			return *this;
		}

	}
}