// Visitor.cpp
// Implements the Visitor class

#include "Visitor.hpp";

// Default Constructor
Visitor::Visitor() : m_x(0), m_y(0) {}

// COnstructor with x and y values
Visitor::Visitor(const double x, const double y) : m_x(x), m_y(y) {}

// Copy Constructor
Visitor::Visitor(const Visitor& source) : m_x(source.m_x), m_y(source.m_y) {}

// Destructor
Visitor::~Visitor() {}

// Operators
// Assignment Operator

Visitor& Visitor::operator=(const Visitor& source) 
{
	// Self assignment check
	if (this == &source)
	{
		return (*this);
	}

	// Copy elements
	m_x = source.m_x;
	m_y = source.m_y;

	return (*this);
}

void Visitor::operator()(Point& p) const
{
	p.X(p.X() + m_x);
	p.Y(p.Y() + m_y);
}

void Visitor::operator()(Line& l) const
{
	// Already had a + operator defined for Point
	l.Start(l.Start() + Point(m_x, m_y));
	l.End(l.End() + Point(m_x, m_y));
}

void Visitor::operator()(Circle& c) const
{
	c.CentrePoint(c.CentrePoint() + Point(m_x, m_y));
}

