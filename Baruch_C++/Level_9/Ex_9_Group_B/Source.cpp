// Group B:
// Extending the Group A solution to implement the Perpetual American Option

// Standard Headers
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

// Project headers
#include "NormalDistribution.hpp"
#include "Pricing.hpp"
#include "OptionException.hpp"
#include "InvalidOptionException.hpp"
#include "VanillaOption.hpp"
#include "PlainVanillaEuropean.hpp"
#include "PutCallParityException.hpp"
#include "PerpetualAmericanOption.hpp"
#include "MeshCreator.hpp"

// Namespaces
using namespace std;
using namespace OPTIONPRICING;
using namespace OPTIONPRICING::PRICING;
using namespace OPTIONPRICING::NORMALDISTRIBUTIONS;
using namespace OPTIONPRICING::EXCEPTIONS;
using namespace OPTIONPRICING::VANILLAOPTIONS;

int main()
{
	OptionData perpAmOptData(100.00,110.00, numeric_limits<double>::quiet_NaN(), 0.1, 0.1);
	double b = .02;

	PerpetualAmericanOption opCall(AMERICANPERPETUALCALL, perpAmOptData, b);
	PerpetualAmericanOption opPut(AMERICANPERPETUALPUT, perpAmOptData, b);

	// We will write all the relevant output in the file
	ofstream outf("Group_B_Output.txt");

	if (!outf)
	{
		cerr << "Option_Price.txt could not be opened for writing!" << endl;
		exit(1);
	}

	outf << "LEVEL 9: GROUP B" << endl;
	outf << "================" << endl;

	outf << "Price of American Perpetual Call: " << opCall.Price() << endl;
	cout << "Price of American Perpetual Call: " << opCall.Price() << endl;
	outf << "-----------------------------------" <<  endl;
	cout << "-----------------------------------" <<  endl;
	outf << "Price of American Perpetual Put: " << opPut.Price() << endl;
	cout << "Price of American Perpetual Put: " << opPut.Price() << endl;

	vector<double> perpAmerCallPrices;
	vector<double> perpAmerPutPrices;
	vector<double> stockMesh;
	double h = 1;

	// Create a mesh from .5 times the stock price to 1.5 the stock price
	stockMesh = CreateMesh(perpAmOptData.S*0.5, perpAmOptData.S*1.5, h);

	for_each(stockMesh.cbegin(), stockMesh.cend(), 
		[&perpAmerCallPrices, &opCall](const double val) {perpAmerCallPrices.push_back(opCall.Price_S(val)); });

	for_each(stockMesh.cbegin(), stockMesh.cend(), 
		[&perpAmerPutPrices, &opPut](const double val) {perpAmerPutPrices.push_back(opPut.Price_S(val)); });

	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;

	outf << "Options price mesh for perpetual american calls" << endl;
	outf << "===============================================" << endl;

	cout << "Options price mesh for perpetual american calls" << endl;
	cout << "===============================================" << endl;

	for (int i = 0; i != perpAmerCallPrices.size(); ++i)
	{
		outf << perpAmerCallPrices[i] << ",";
		cout << perpAmerCallPrices[i] << ",";

	}
	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;

	outf << "Options price mesh for perpetual american puts" << endl;
	outf << "===============================================" << endl;

	cout << "Options price mesh for perpetual american puts" << endl;
	cout << "===============================================" << endl;

	for (int i = 0; i != perpAmerPutPrices.size(); ++i)
	{
		outf << perpAmerPutPrices[i] << ",";
		cout << perpAmerPutPrices[i] << ",";

	}
	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;


	outf.close();

	return 0;
}