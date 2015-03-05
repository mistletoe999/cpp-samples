// NormalDistribution.hpp: Defines the normal distribution methods those would be used 
// across the project
// We put all the methods in a nested namespace
// All methods in the header file are defined in 
// OPTIONPRICING::NORMALDISTRIBUTIONS namespace

#ifndef NORMAL_DISTRIBUTION_HPP_
#define NORMAL_DISTRIBUTION_HPP_

#include <iostream>
#include <cmath>
#include <boost\math\distributions\normal.hpp>
#include <boost\math\distributions.hpp>


namespace OPTIONPRICING
{
	namespace NORMALDISTRIBUTIONS
	{
		double N(const double x);	// Normal Cumulative Distribution Function
		double n(const double x);	// Normal Probability Distribution Function
	}
}

#endif