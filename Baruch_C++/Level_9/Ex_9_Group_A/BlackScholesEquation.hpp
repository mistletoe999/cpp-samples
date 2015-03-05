// BlackScholesEquation.hpp
// Defines the Black Scholes equation functions that would be used
// across the project and would be called from the option classes
// The functions are defined in OPTIONPRICING::BLACKSCHOLESEQUATION
// namespace

#ifndef BLACK_SCHOLES_EQUATION_HPP_
#define BLACK_SCHOLES_EQUATION_HPP_

#include <iostream>
#include <cmath>
#include <boost\math\distributions\normal.hpp>
#include <boost\math\distributions.hpp>
#include "NormalDistribution.hpp"
#include "VanillaOption.hpp"
#include "PlainVanillaEuropean.hpp"

namespace OPTIONPRICING
{
	namespace BLACKSCHOLES
	{
		// Helper functions to get d1 and d2

		inline double d1(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double costOfCarry)
		{
			return ((log(stockPrice / strikePrice) + (costOfCarry + (volatility*volatility / 2)) * expiry)) / (volatility*sqrt(expiry));
		}

		//==========================================================================
		// OPTION PRICE
		//==========================================================================

		inline double d2(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double costOfCarry)
		{
			return ((log(stockPrice / strikePrice) + (costOfCarry - (volatility*volatility / 2)) *expiry)) / (volatility*sqrt(expiry));
		}

		// Get price using individual values
		double BlackScholesPrice(const double stockPrice, const double strikePrice, 
			const double expiry, const double volatility, const double intereastRate, 
			const double costOfCarry, const OptionType optionType);

		// Get the price using the OptionData struct and option and type
		double BlackScholesPrice(const OptionData& data, const OptionType optionType);


		// Get the price using the OptionData struct, type and cost of carry
		double BlackScholesPrice(const OptionData& data, const double costOfCarry, const OptionType optionType);


		//==========================================================================
		// GREEKS
		//==========================================================================

		// Delta using all parameters
		double Delta(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType);

		// Gamma using all parameters
		double Gamma(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType);

		// Vega using all parameters
		double Vega(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType);

		// Theta using all parameters
		double Theta(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType);

		// Numeric Methods
		// Ideally, we should define all the numeric methods in a separate namespace
		// however, using the same namespace so that both numerical method and
		// actual formula both are at the same place

		double Delta(const OptionData& data, const double costOfCarry, const double stockPrice, const long double h, OptionType type);

		double Gamma(const OptionData& data, const double costOfCarry, const double stockPrice, const long double h, OptionType type);

	}
}



#endif