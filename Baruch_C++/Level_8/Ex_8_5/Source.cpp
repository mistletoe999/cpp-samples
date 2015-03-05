// Ex 8.5: Testing the Exponential and Poison Distributions


// Standard Headers
#include <vector>
#include <iostream>

// Boost headers
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> 

// Namespaces
using namespace std;
using namespace boost::math;


int main()
{
	// EXPONENTIAL DISTRIBUTION

	cout << "EXPONENTIAL DISTRIBUTION" << endl;
	cout << "========================" << endl;


	double scaleParameter = 0.5;
	// Default type is 'double'
	exponential_distribution<> myExponential(scaleParameter);

	cout << "Mean: " << mean(myExponential)
		<< ",Standard Deviation: " << standard_deviation(myExponential) << endl;

	// Distributional properties
	double x = 10.25;

	cout << "pdf: " << pdf(myExponential, x) << endl;
	cout << "cdf: " << cdf(myExponential, x) << endl;

	// Default exponential distribution - with scale parameter = 1
	exponential_distribution<float> myExponential2;
	cout << "Mean: " << mean(myExponential2) << ", Standard Deviation: " << standard_deviation(myExponential2) << endl;

	cout << "pdf: " << pdf(myExponential2, x) << endl;
	cout << "cdf: " << cdf(myExponential2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\nExponential Distribution - Additional Properties: \n";
	cout << "mean: " << mean(myExponential) << endl;
	cout << "variance: " << variance(myExponential) << endl;
	cout << "median: " << median(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "characteristic function: " << chf(myExponential, x) << endl;
	cout << "hazard: " << hazard(myExponential, x) << endl;

	cout << "\n\n";
	// POISSON DISTRIBUTION


	cout << "POISSON DISTRIBUTION" << endl;
	cout << "====================" << endl;


	double meanPoisson = 3.0;
	poisson_distribution<double> myPoisson(meanPoisson);

	cout << "Mean: " << mean(myPoisson) << ", Standard Deviation: " << standard_deviation(myPoisson) << endl;


	double val = 13.0;
	cout << endl << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));
		val += h;
	}

	cout << "Printng pdf list" << endl;

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";
	}

	cout << "\n\nPrinting cdf list" << endl;
	
	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";
	}

	return 0;
}