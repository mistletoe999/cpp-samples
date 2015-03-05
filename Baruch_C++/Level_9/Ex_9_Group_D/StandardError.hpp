// Defines the Standard Deviation/ Standard Error function

#ifndef STANDARD_ERROR_HPP_
#define STANDARD_ERROR_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>


// Boost Includes
#include <boost\tuple\tuple.hpp>
#include <boost\tuple\tuple_io.hpp>

// Definition of the Error function
boost::tuple<double, double> Error(const std::vector<double>& V, const double interestRate, const double maturity);

#endif