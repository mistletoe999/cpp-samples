// BlackScholes.hpp
// Contains the definition for the BlackScholes pricing formula

#ifndef BLACK_SCHOLES_HPP_
#define BLACK_SCHOLES_HPP_

#include <iostream>
#include <cmath>
#include <boost\math\distributions\normal.hpp>
#include <boost\math\distributions.hpp>
#include "InvalidOptionException.hpp"

// OptionType enum type
enum OptionType
{
	EUROPEANCALL,
	EUROPEANPUT,
	AMERICANPERPETUALCALL,
	AMERICANPERPETUALPUT
};

// Inline functions to help in calculating the Black Scholes Price
inline double N(const double x)
{
	boost::math::normal_distribution<double> normalDistribution(0, 1);
	return boost::math::cdf(normalDistribution, x);
}

inline double n(const double x)
{
	boost::math::normal_distribution<double> normalDistribution(0, 1);
	return boost::math::pdf(normalDistribution, x);
}

inline double d1(const double stockPrice, const double strikePrice,
	const double expiry, const double volatility, const double costOfCarry)
{
	return ((log(stockPrice / strikePrice) + (costOfCarry + (volatility*volatility / 2)) * expiry)) / (volatility*sqrt(expiry));
}

inline double d2(const double stockPrice, const double strikePrice,
	const double expiry, const double volatility, const double costOfCarry)
{
	return ((log(stockPrice / strikePrice) + (costOfCarry - (volatility*volatility / 2)) *expiry)) / (volatility*sqrt(expiry));
}

double BlackScholesPrice(const double stockPrice, const double strikePrice,
	const double expiry, const double volatility, const double interestRate,
	const double costOfCarry, const OptionType optionType);

#endif