// PerpetualAmericanOption.hpp
// Defines the perpetual american option class derived 
// from VanillaOptions class

#ifndef PERPETUAL_AMERICAN_OPTION_HPP_
#define PERPETUAL_AMERICAN_OPTION_HPP_

#include <limits>
#include "VanillaOption.hpp"
#include "Pricing.hpp"
#include "OptionException.hpp"
#include "InvalidOptionException.hpp"

namespace OPTIONPRICING
{
	namespace VANILLAOPTIONS
	{
		class PerpetualAmericanOption : public VanillaOption
		{
		private:
			OptionType m_type;	// Type of the option
			OptionData m_data;	// Option parameters
			double m_costOfCarry; // Cost of Carry b
		public:
			// Constructor
			PerpetualAmericanOption(OptionType type, double stockPrice, double strikePrice, double vol, double interestRate, double costOfCarry);
			// Constructor with OptionData struct as parameter
			PerpetualAmericanOption(OptionType type, OptionData& data, double costOfCarry);
			// Copy Constructor
			PerpetualAmericanOption(const PerpetualAmericanOption& source);
			// Destructor
			virtual ~PerpetualAmericanOption();
			// Setters and Getters
			void Type(const OptionType type);
			void StockPrice(const double price);
			void StrikePrice(const double price);
			void Volatility(const double vol);
			void InterestRate(const double rate);
			void CostOfCarry(const double costOfCarry);

			OptionType Type() const;
			double StockPrice() const;
			double StrikePrice() const;
			double Volatility() const;
			double InterestRate() const;
			double CostOfCarry() const;

			// Overridden Price function
			// Using the data members
			double Price() const;
			double Price_S(const double stockPrice) const;

			// Assignment Operator
			PerpetualAmericanOption& operator=(const PerpetualAmericanOption& source);
		};	

	}
}

#endif