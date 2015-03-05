// Visitor.hpp:
// Defines the Visitor class

#ifndef VISITOR_HPP_
#define VISITOR_HPP_

// Includes
// Standard Headers

#include <iostream>
#include <string>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include <boost/variant.hpp>
#include <boost/variant/apply_visitor.hpp>

using namespace KAPIL::CAD;

class Visitor : public boost::static_visitor<void>
{
private :
	// Data members
	double m_x;			// X-value
	double m_y;			// Y-value

public:
	// Constructors
	Visitor();							// Default Constructor
	Visitor(const double x, const double y);		// Constructor with x and y values
	Visitor(const Visitor& source);		// Copy Constructor

	// Destructor
	~Visitor();							// Destructor

	// Operators
	Visitor& operator=(const Visitor& source);
	void operator()(Point& p) const;
	void operator()(Line& l) const;
	void operator()(Circle& c) const;

};


#endif // VISITOR_HPP_
