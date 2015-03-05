// BlackScholesEquation.cpp
// Implements the functions defined in BlackScholesEquation.hpp

#include "Pricing.hpp"
#include "OptionException.hpp"
#include "InvalidOptionException.hpp"

namespace OPTIONPRICING
{
	namespace PRICING
	{
		//==========================================================================
		// OPTION PRICE
		//==========================================================================
		
		double BlackScholesPrice(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double interestRate, 
			const double costOfCarry, const OptionType optionType)
		{
			double normalVal1 = NORMALDISTRIBUTIONS::N(d1(stockPrice, strikePrice, expiry, volatility, costOfCarry));
			double normalVal2 = NORMALDISTRIBUTIONS::N(d2(stockPrice, strikePrice, expiry, volatility, costOfCarry));

			switch (optionType)
			{
			case EUROPEANCALL:
				return (stockPrice*normalVal1*exp((costOfCarry - interestRate)*expiry) - strikePrice*normalVal2*exp(-interestRate*expiry));
				break;
			case EUROPEANPUT:
				// N(-d1) = 1 - N(d1) and N(-d2) = 1 - N(d2)
				return (strikePrice*(1 - normalVal2)*exp(-interestRate*expiry) - stockPrice*(1 - normalVal1)*exp((costOfCarry - interestRate)*expiry));
				break;
			default:
				throw EXCEPTIONS::InvalidOptionException(-1);
				break;
			}
		}

		// This function has been written specifically for stock option, since OptionData struct has 
		// been defined keeping the stock option in perspective.
		// The struct OptionData can be exptended easily to apply other types of options
		double BlackScholesPrice(const OptionData& data, const OptionType optionType)
		{
			double normalVal1 = NORMALDISTRIBUTIONS::N(d1(data.S, data.K, data.T, data.sig, data.r));
			double normalVal2 = NORMALDISTRIBUTIONS::N(d2(data.S, data.K, data.T, data.sig, data.r));

			switch (optionType)
			{
			case EUROPEANCALL:
				return (data.S*normalVal1 - data.K*normalVal2*exp(-data.r*data.T));
				break;
			case EUROPEANPUT:
				// N(-d1) = 1 - N(d1) and N(-d2) = 1 - N(d2)
				return (data.K*(1 - normalVal2)*exp(-data.r*data.T) - data.S*(1 - normalVal1));
				break;
			default:
				throw EXCEPTIONS::InvalidOptionException(-1);
				break;
			}
		}

		// This overloaded function has been written for any vanilla european option, 
		// using the OptionData struct, convenience yield, and optionType as parameters
		// This can be used for different values of convenience yield

		double BlackScholesPrice(const OptionData& data, const double costOfCarry, const OptionType optionType)
		{
			double normalVal1 = NORMALDISTRIBUTIONS::N(d1(data.S, data.K, data.T, data.sig, data.r));
			double normalVal2 = NORMALDISTRIBUTIONS::N(d2(data.S, data.K, data.T, data.sig, data.r));

			switch (optionType)
			{
			case EUROPEANCALL:
				return (data.S*normalVal1*exp((costOfCarry - data.r)*data.T) - data.K*normalVal2*exp(-data.r*data.T));
				break;
			case EUROPEANPUT:
				// N(-d1) = 1 - N(d1) and N(-d2) = 1 - N(d2)
				return (data.S*(1 - normalVal2)*exp(-data.r*data.T) - data.S*(1 - normalVal1)*exp((costOfCarry - data.r)*data.T));
				break;
			default:
				throw EXCEPTIONS::InvalidOptionException(-1);
				break;
			}
		}

		//==========================================================================
		// GREEKS
		//==========================================================================

		double Delta(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType)
		{
			double normalVal1 = NORMALDISTRIBUTIONS::N(d1(stockPrice, strikePrice, expiry, volatility, costOfCarry));

			switch (optionType)
			{
			case EUROPEANCALL:
				return (exp((costOfCarry - intereastRate)*expiry)*normalVal1);
				break;
			case EUROPEANPUT:
				// N(-d1) = 1 - N(d1) and N(-d2) = 1 - N(d2)
				return (exp((costOfCarry - intereastRate)*expiry)*(normalVal1 - 1));
				break;
			default:
				throw EXCEPTIONS::InvalidOptionException(-1);
				break;
			}
		}

		double Gamma(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType)
		{
			// Gamma need the pdf value of d1
			double normalDist1 = NORMALDISTRIBUTIONS::n(d1(stockPrice, strikePrice, expiry, volatility, costOfCarry));

			// Gamma of CALL = Gamma of PUT
			if (optionType == EUROPEANCALL || optionType == EUROPEANPUT)
			{
				return (exp((costOfCarry - intereastRate)*expiry)*normalDist1)/(stockPrice*volatility*sqrt(expiry));
			}
			else
			{
				throw EXCEPTIONS::InvalidOptionException(-1);
			}				
		}

		double Vega(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType)
		{
			// Vega need the pdf value of d1
			double normalDist1 = NORMALDISTRIBUTIONS::n(d1(stockPrice, strikePrice, expiry, volatility, costOfCarry));

			// Vega of CALL = Vega of PUT
			if (optionType == EUROPEANCALL || optionType == EUROPEANPUT)
			{
				return (exp((costOfCarry - intereastRate)*expiry)*normalDist1)*stockPrice*sqrt(expiry);
			}
			else
			{
				throw EXCEPTIONS::InvalidOptionException(-1);
			}
		}

		double Theta(const double stockPrice, const double strikePrice,
			const double expiry, const double volatility, const double intereastRate,
			const double costOfCarry, const OptionType optionType)
		{
			double normalVal1 = NORMALDISTRIBUTIONS::N(d1(stockPrice, strikePrice, expiry, volatility, costOfCarry));
			double normalVal2 = NORMALDISTRIBUTIONS::N(d2(stockPrice, strikePrice, expiry, volatility, costOfCarry));
			double normalDist1 = NORMALDISTRIBUTIONS::n(d1(stockPrice, strikePrice, expiry, volatility, costOfCarry));

			// First expression in the formula would be used in both CALL and PUT
			double part1 = -(stockPrice*normalDist1*volatility*exp((costOfCarry - intereastRate)*expiry))/(2*sqrt(expiry));

			switch (optionType)
			{
			case EUROPEANCALL:
				return (part1 
					- (costOfCarry - intereastRate)*stockPrice*exp((costOfCarry - intereastRate)*expiry)*normalVal1 
					- intereastRate*strikePrice*exp(-intereastRate*expiry)*normalVal2);
				break;
			case EUROPEANPUT:
				// N(-d1) = 1 - N(d1) and N(-d2) = 1 - N(d2)
				return (part1
					+ (costOfCarry - intereastRate)*stockPrice*exp((costOfCarry - intereastRate)*expiry)*(1 - normalVal1) 
					+ intereastRate*strikePrice*exp(-intereastRate*expiry)*(1-normalVal2));
				break;
			default:
				throw EXCEPTIONS::InvalidOptionException(-1);
				break;
			}
		}

		// Nuemrical Method for Delta
		double Delta(const OptionData& data, const double costOfCarry, const double stockPrice, const long double h, OptionType type)
		{
			return (BlackScholesPrice(stockPrice + h, data.K, data.T, data.sig, data.r, costOfCarry, type) -
				BlackScholesPrice(stockPrice - h, data.K, data.T, data.sig, data.r, costOfCarry, type)) / (2 * h);
		}

		double Gamma(const OptionData& data, const double costOfCarry, const double stockPrice, const long double h, OptionType type)
		{
			return (BlackScholesPrice(stockPrice + h, data.K, data.T, data.sig, data.r, costOfCarry, type) -
				2*BlackScholesPrice(stockPrice, data.K, data.T, data.sig, data.r, costOfCarry, type) + 
				BlackScholesPrice(stockPrice - h, data.K, data.T, data.sig, data.r, costOfCarry, type)) / (h*h);
		}


	}
}