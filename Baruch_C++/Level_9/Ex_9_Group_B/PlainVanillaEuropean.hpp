// PlainVanillaEuropean.hpp
// Defines the PlainVanillaEuropeanOption class derived from VanillaOption class

#ifndef PLAIN_VANILLA_EUROPEAN_HPP_
#define PLAIN_VANILLA_EUROPEAN_HPP_

#include "VanillaOption.hpp"
#include "Pricing.hpp"
#include "OptionException.hpp"
#include "InvalidOptionException.hpp"
#include "PutCallParityException.hpp"

namespace OPTIONPRICING
{
	namespace VANILLAOPTIONS
	{
		class PlainVanillaEuropeanOption : public VanillaOption
		{
		private:
			OptionType m_type;	// Type of the option
			OptionData m_data;	// Option parameters
		public:
			// Constructor
			PlainVanillaEuropeanOption(OptionType type, double stockPrice, double strikePrice, double expiry, double vol, double interestRate);
			// Constructor with OptionData struct as parameter
			PlainVanillaEuropeanOption(OptionType type, OptionData& data);
			// Copy Constructor
			PlainVanillaEuropeanOption(const PlainVanillaEuropeanOption& source);
			// Destructor
			virtual ~PlainVanillaEuropeanOption();
			// Setters and Getters
			void Type(const OptionType type);
			void StockPrice(const double price);
			void StrikePrice(const double price);
			void Expiry(const double expiry);
			void Volatility(const double vol);
			void InterestRate(const double rate);

			OptionType Type() const;
			double StockPrice() const;
			double StrikePrice() const;
			double Expiry() const;
			double Volatility() const;
			double InterestRate() const;

			// Overridden Price function
			// Using the data members
			double Price() const;
			double Price_S(const double stockPrice) const;
			double Price_r(const double interestRate) const;
			double Price_sig(const double volatility) const;
			double Price_T(const double expiry) const;
			// WOuld not need it but for completeness sake, adding an overloaded function 
			// with strike price as parameter
			double Price_K(const double strikePrice) const;


			// Using the put call parity
			double Price(const PlainVanillaEuropeanOption& option) const;

			// Assignment Operator
			PlainVanillaEuropeanOption& operator=(const PlainVanillaEuropeanOption& source);
		
		};
	}
}

#endif 