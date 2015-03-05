// PlainVanillaEuropean.cpp
// Implements the the PlainVanillaEuropeanOption class defined in 
// the corresponding header file PlainVanillaEuropean.hpp

#include "PlainVanillaEuropean.hpp"

namespace OPTIONPRICING
{
	namespace VANILLAOPTIONS
	{
		// Constructor with all data members
		PlainVanillaEuropeanOption::PlainVanillaEuropeanOption(OptionType type, double stockPrice,
			double strikePrice, double expiry,
			double vol, double interestRate) : VanillaOption(), m_type(type), m_data(strikePrice, stockPrice, expiry, interestRate, vol)
		{}

		PlainVanillaEuropeanOption::PlainVanillaEuropeanOption(OptionType type, OptionData& data): 
			VanillaOption(), m_type(type), m_data(data) {}

		// Copy Constructor
		PlainVanillaEuropeanOption::PlainVanillaEuropeanOption(const PlainVanillaEuropeanOption& source) :
			VanillaOption(source), m_type(source.m_type), m_data(source.m_data) {}

		// Destructor
		PlainVanillaEuropeanOption::~PlainVanillaEuropeanOption() {}

		// Setters
		void PlainVanillaEuropeanOption::Type(const OptionType type)
		{
			m_type = type;
		}

		void PlainVanillaEuropeanOption::StockPrice(const double stockPrice)
		{
			m_data.S = stockPrice;
		}

		void PlainVanillaEuropeanOption::StrikePrice(const double strikePrice)
		{
			m_data.K = strikePrice;
		}

		void PlainVanillaEuropeanOption::Expiry(const double expiry)
		{
			m_data.T = expiry;
		}

		void PlainVanillaEuropeanOption::InterestRate(const double rate)
		{
			m_data.r = rate;
		}

		void PlainVanillaEuropeanOption::Volatility(const double vol)
		{
			m_data.sig = vol;
		}

		// Getters

		OptionType PlainVanillaEuropeanOption::Type() const { return m_type; }
		
		double PlainVanillaEuropeanOption::StockPrice() const { return m_data.S; }

		double PlainVanillaEuropeanOption::StrikePrice() const { return m_data.K; }

		double PlainVanillaEuropeanOption::Expiry() const { return m_data.T; }

		double PlainVanillaEuropeanOption::InterestRate() const { return m_data.r; }

		double PlainVanillaEuropeanOption::Volatility() const { return m_data.sig; }

		// Operator Overloading

		PlainVanillaEuropeanOption& PlainVanillaEuropeanOption::operator=(const PlainVanillaEuropeanOption& source)
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

			return *this;
		}

		double PlainVanillaEuropeanOption::Price() const
		{
			double price;

			try 
			{
				// Cost Of Carry = Interest Rate
				price = PRICING::BlackScholesPrice(m_data, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

		double PlainVanillaEuropeanOption::Price_S(const double stockPrice) const
		{
			double price;

			try
			{
				// Cost Of Carry = Interest Rate
				price = PRICING::BlackScholesPrice(stockPrice, m_data.K, m_data.T, m_data.sig, m_data.r, m_data.r, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

		double PlainVanillaEuropeanOption::Price_T(const double expiry) const
		{
			double price;

			try
			{
				// Cost Of Carry = Interest Rate
				price = PRICING::BlackScholesPrice(m_data.S, m_data.K, expiry, m_data.sig, m_data.r, m_data.r, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

		double PlainVanillaEuropeanOption::Price_sig(const double vol) const
		{
			double price;

			try
			{
				// Cost Of Carry = Interest Rate
				price = PRICING::BlackScholesPrice(m_data.S, m_data.K, m_data.T, vol, m_data.r, m_data.r, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

		double PlainVanillaEuropeanOption::Price_r(const double interestRate) const
		{
			double price;

			try
			{
				// Cost Of Carry = Interest Rate
				price = PRICING::BlackScholesPrice(m_data.S, m_data.K, m_data.T, m_data.sig, interestRate, m_data.r, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

		double PlainVanillaEuropeanOption::Price_K(const double strikePrice) const
		{
			double price;

			try
			{
				// Cost Of Carry = Interest Rate
				price = PRICING::BlackScholesPrice(m_data.S, strikePrice, m_data.T, m_data.sig, m_data.r, m_data.r, m_type);
			}
			catch (EXCEPTIONS::OptionException& ex)
			{
				std::cout << ex.GetMessage() << std::endl;
				throw EXCEPTIONS::InvalidOptionException(-1);
			}

			return price;
		}

		// Price from Put Call Parity
		double PlainVanillaEuropeanOption::Price(const PlainVanillaEuropeanOption& option) const
		{
			if (option.m_type == EUROPEANCALL && m_type == EUROPEANPUT)
			{
				return (option.Price() + m_data.K*exp(-(m_data.r)*(m_data.T)) - m_data.S);
			}
			else if (option.m_type == EUROPEANPUT && m_type == EUROPEANCALL)
			{
				return (option.Price() - m_data.K*exp(-(m_data.r)*(m_data.T)) + m_data.S);
			}
			else
			{
				throw EXCEPTIONS::PutCallParityException(-1);
			}
		}

	}
}