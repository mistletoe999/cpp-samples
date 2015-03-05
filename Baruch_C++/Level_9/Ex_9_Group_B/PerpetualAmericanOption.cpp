// PerpetualAmericanOption.cpp
// Implements the PerpetualAmericanOption class

#include "PerpetualAmericanOption.hpp"

namespace OPTIONPRICING
{
	namespace VANILLAOPTIONS
	{
		PerpetualAmericanOption::PerpetualAmericanOption(OptionType type, double stockPrice,
			double strikePrice, double vol, double interestRate, double costOfCarry) : VanillaOption(), m_type(type), m_data(strikePrice, stockPrice, 
			std::numeric_limits<double>::quiet_NaN(), interestRate, vol), m_costOfCarry(costOfCarry)
		{}

		PerpetualAmericanOption::PerpetualAmericanOption(OptionType type, OptionData& data, double costOfCarry) :
			VanillaOption(), m_type(type), m_data(data), m_costOfCarry(costOfCarry)
		{
			m_data.T = std::numeric_limits<double>::quiet_NaN();
		}

		// Copy Constructor
		PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) :
			VanillaOption(source), m_type(source.m_type), m_data(source.m_data), m_costOfCarry(source.m_costOfCarry) {}

		// Destructor
		PerpetualAmericanOption::~PerpetualAmericanOption() {}

		// Setters
		void PerpetualAmericanOption::Type(const OptionType type)
		{
			m_type = type;
		}

		void PerpetualAmericanOption::StockPrice(const double stockPrice)
		{
			m_data.S = stockPrice;
		}

		void PerpetualAmericanOption::StrikePrice(const double strikePrice)
		{
			m_data.K = strikePrice;
		}

		void PerpetualAmericanOption::InterestRate(const double rate)
		{
			m_data.r = rate;
		}

		void PerpetualAmericanOption::Volatility(const double vol)
		{
			m_data.sig = vol;
		}

		void PerpetualAmericanOption::CostOfCarry(const double costOfCarry)
		{
			m_costOfCarry = costOfCarry;
		}

		OptionType PerpetualAmericanOption::Type() const { return m_type; }

		double PerpetualAmericanOption::StockPrice() const { return m_data.S; }

		double PerpetualAmericanOption::StrikePrice() const { return m_data.K; }

		double PerpetualAmericanOption::InterestRate() const { return m_data.r; }

		double PerpetualAmericanOption::Volatility() const { return m_data.sig; }

		double PerpetualAmericanOption::CostOfCarry() const { return m_costOfCarry; }

		// Operator Overloading

		PerpetualAmericanOption& PerpetualAmericanOption::operator=(const PerpetualAmericanOption& source)
		{
			if (this == &source)
			{
				return *this;
			}

			// No data in base class to copy, hence, no need to call the base class
			// assignment operator

			// Copy the data members
			m_type = source.m_type;
			m_data = source.m_data;
			m_costOfCarry = source.m_costOfCarry;

			return *this;
		}

		double PerpetualAmericanOption::Price() const
		{
			double price;

			try
			{
				price = PRICING::PerpetualAmericanOptionPrice(m_data, m_costOfCarry, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

		double PerpetualAmericanOption::Price_S(const double stockPrice) const
		{
			double price;

			try
			{
				price = PRICING::PerpetualAmericanOptionPrice(stockPrice, m_data.K, m_data.sig, m_data.r, m_costOfCarry, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

	}
}