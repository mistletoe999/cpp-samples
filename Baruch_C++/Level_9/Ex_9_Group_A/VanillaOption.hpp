// VanillaOption.hpp
// VanillaOption is a abstract class that provides 
// an interface for the different option classes

#ifndef VANILLA_OPTION_HPP_
#define VANILLA_OPTION_HPP_

namespace OPTIONPRICING
{
	// Type of option to be priced

	enum OptionType
	{
		EUROPEANCALL,
		EUROPEANPUT,
		AMERICANPERPETUALCALL,
		AMERICANPERPETUALPUT

	};

	// Struct to save the option data
	// Putting StockPrice in here so that each Batch provided
	// in exercise can be interpreted as an instance of OptionData
	struct OptionData
	{
		double K;
		double S;
		double T;
		double r;
		double sig;

		// Constructor with values
		OptionData(double strikePrice, double stockPrice, double expiry, double interestRate, double vol) :
			K(strikePrice), S(stockPrice), T(expiry), r(interestRate), sig(vol) {}
	};
	
	namespace VANILLAOPTIONS
	{
		class VanillaOption
		{
		private:
		public:
			VanillaOption();		// Default Constructor
			VanillaOption(const VanillaOption& source);		// 
			~VanillaOption();		// Destructor

			VanillaOption& operator=(const VanillaOption& source);	// Assignment Operator

			virtual double Price() const = 0;			// Pure Virtual Price function

		};

	}
}

#endif