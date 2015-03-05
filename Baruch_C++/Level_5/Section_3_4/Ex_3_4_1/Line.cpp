// Implements the Line class defined in Line.hpp
// EDIT: Use Colon syntax for constructors

#include "Line.hpp"

namespace KAPIL
{
	namespace CAD
	{
		Line::Line() : lineStart(Point(0.0, 0.0)), lineEnd(Point(0.0, 0.0)) {} // Default Constructor

		Line::Line(const Point& pS, const Point& pE) : lineStart(pS), lineEnd(pE) {} // Constructor with start and end points

		Line::Line(const Line& line) : lineStart(line.lineStart), lineEnd(line.lineEnd) {}	// Copy Constructor

		Line::~Line() {} // Destructor

		Point Line::Start() const { // Getter function for start-point
			return lineStart;
		}

		Point Line::End() const{ // Getter function for end-point
			return lineEnd;
		}

		void Line::Start(const Point& point) { // Setter function for start-point
			lineStart = point;
		}

		void Line::End(const Point& point) { // Setter function for end-point
			lineEnd = point;
		}

		string Line::ToString() const { // Display line information as a string
			stringstream lineStream; // Start reading input into a stringstream
			lineStream << "Line Segment between " << lineStart.ToString() << " and " << lineEnd.ToString(); // Add string to pointStream
			return(lineStream.str()); // Output the string using the str() member function
		}

		double Line::Length() const { // Distance Function
			return lineStart.Distance(lineEnd);
		}

		// Operator Overloading
		Line& Line::operator = (const Line& source) {		// Assignment Operator
			// Check for self assignment
			if (this == &source) {
				return *this;
			}

			// Copy values
			lineStart = source.lineStart;
			lineEnd = source.lineEnd;

			// Return the refernce to the current object
			return *this;
		}


		// ostream operator: As a friend function, "operator<<" can access 
		// private members of Line l.
		ostream& operator << (ostream& os, const Line& l) { // Send to ostream.
			os << "Line Segment between " << l.lineStart << " and " << l.lineEnd;
			return os;
		}
	}
}

