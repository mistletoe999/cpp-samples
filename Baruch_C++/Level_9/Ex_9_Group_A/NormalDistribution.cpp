// NormalDistribution.cpp
// Implements the functions defined in NormalDistribution.hpp

// Headers
#include "NormalDistribution.hpp"


namespace OPTIONPRICING
{
	namespace NORMALDISTRIBUTIONS
	{
		// Normal Cumulative Distribution Function
		double N(const double x)
		{
			boost::math::normal_distribution<double> normalDistribution(0, 1);
			return boost::math::cdf(normalDistribution, x);
		}

		// Normal Probability Distribution Function
		double n(const double x)
		{
			boost::math::normal_distribution<double> normalDistribution(0, 1);
			return boost::math::pdf(normalDistribution, x);
		}
	}
}
