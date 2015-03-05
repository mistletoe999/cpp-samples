// Point.hpp: Defines the specialzed functionalities of Array<Point> class
// derived from the template Array class

#ifndef POINT_ARRAY_HPP_
#define POINT_ARRAY_HPP_

#include "Array.hpp"
#include "Point.hpp"
using namespace std;

namespace KAPIL 
{
	namespace Containers
	{
		using namespace KAPIL::CAD;
		class PointArray : public Array<Point> 
		{
		private:

		public:
			PointArray();										// Default Constructor
			PointArray(unsigned int size);						// Constructor with size parameter
			PointArray(const PointArray& source);				// Copy Constructor
			virtual ~PointArray();								// Destructor

			double Length();									// Length between all points

			PointArray& operator = (const PointArray& source);	// Assignment Operator

		};
	
	}
}

#endif