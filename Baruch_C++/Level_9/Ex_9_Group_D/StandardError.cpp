// Implements the functions in StandardError.hpp

#include "StandardError.hpp"

// Error function tha returns a tuple with the Standard deviation and 
// Standard Error

boost::tuple<double, double> Error(const std::vector<double>& V, 
	const double interestRate, const double expiry) 
{
	double sumPrices;
	double sumSquarePrices;
	double stDev;
	double stError;

	std::vector<double>::const_iterator it = V.cbegin();

	sumPrices = std::accumulate(it, V.cend(), 0);

	sumSquarePrices = std::inner_product(it, V.cend(), it, 0);

	stDev = sqrt(sumSquarePrices - ((sumPrices*sumPrices) / V.size()))*exp(-2*interestRate*expiry)/(V.size() - 1);

	stError = stDev / sqrt(V.size());

	return boost::tuple<double, double>(stDev, stError);
}
