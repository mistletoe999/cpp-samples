// BlackScholes.cpp
// Implements the functions defined in BlackScholes.hpp

#include "BlackScholes.hpp"

double BlackScholesPrice(const double stockPrice, const double strikePrice,
	const double expiry, const double volatility, const double interestRate,
	const double costOfCarry, const OptionType optionType)
{
	double normalVal1 = N(d1(stockPrice, strikePrice, expiry, volatility, costOfCarry));
	double normalVal2 = N(d2(stockPrice, strikePrice, expiry, volatility, costOfCarry));

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
		throw OPTIONPRICING::EXCEPTIONS::InvalidOptionException(-1);
		break;
	}
}