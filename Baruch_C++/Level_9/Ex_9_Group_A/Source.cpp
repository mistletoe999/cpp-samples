// Group A:
// The exercise focusses on defining an option class 
// with appropriate encapsulation and class hierarchy
// as and when required
// The option class will be used to calculate prices 
// on 4 batches of data:
// Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13293, P = 5.84584).
// Batch 2 : T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96632, P = 7.96632).
// Batch 3 : T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204121, P = 4.0733).
// Batch 4 : T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.1749, P = 1.24651).

// Standard Headers
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

// Project headers
#include "NormalDistribution.hpp"
#include "Pricing.hpp"
#include "OptionException.hpp"
#include "InvalidOptionException.hpp"
#include "VanillaOption.hpp"
#include "PlainVanillaEuropean.hpp"
#include "PutCallParityException.hpp"
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
	// GROUP A: PART I
	//==========================================================================================
	//==========================================================================================

	// Options batches
	vector<OptionData> optionBatches;
	optionBatches.push_back(OptionData(65, 60, .25, 0.08, .30));
	optionBatches.push_back(OptionData(100, 100, 1, 0, .2));
	optionBatches.push_back(OptionData(10, 5, 1, 0.12, .5));
	optionBatches.push_back(OptionData(100, 100, 30, 0.08, .3));

	// We will use the following variables to get the option meshes
	vector<double> stockMesh;	// Mesh of stock prices
	double h; // Difference in prices in the mesh
	int numOfOptions = 100;	// Number of options in the mesh


	// Based on the batches, create a vector of CALLs and PUTs with the data
	vector<PlainVanillaEuropeanOption> options;
	for (int i = 0; i != optionBatches.size(); ++i)
	{
		options.push_back(PlainVanillaEuropeanOption(EUROPEANCALL, optionBatches[i]));
		options.push_back(PlainVanillaEuropeanOption(EUROPEANPUT, optionBatches[i]));
	}

	// We will write all the relevant output in the file
	ofstream outf("Group_A_Output.txt");

	if (!outf)
	{
		cerr << "Option_Price.txt could not be opened for writing!" << endl;
		exit(1);
	}

	outf << "LEVEL 9: GROUP A - PART I" << endl;
	outf << "=========================" << endl;

	// Price from Price function
	outf << "Price Using the Global BSE function" << endl;
	outf << "===================================" << endl;

	// BS Prices for all batches
	for (int i = 0; i != optionBatches.size(); ++i)
	{
		outf << "Batch " << i + 1 << "\nCALL: " << BlackScholesPrice(optionBatches[i].S,
			optionBatches[i].K, optionBatches[i].T, optionBatches[i].sig, 
			optionBatches[i].r, optionBatches[i].r, EUROPEANCALL) << 
			"; PUT: " << BlackScholesPrice(optionBatches[i].S,
			optionBatches[i].K, optionBatches[i].T, optionBatches[i].sig,
			optionBatches[i].r, optionBatches[i].r, EUROPEANPUT) << endl;

		outf << "-----------------------------------------" << endl;
	}

	outf << "===========================================================================" << endl;

	// Price from Price function
	outf << "Price Using the Price member function" << endl;
	outf << "=====================================" << endl;

	for (int i = 0; i != optionBatches.size(); ++i)
	{
		outf << "Batch " << i + 1 << "\nCALL: " << options[2 * i].Price() << "; PUT: " << options[2 * i + 1].Price() << endl;
		outf << "-----------------------------------------" << endl;
 	}

	outf << "===========================================================================" << endl;

	// Price from PutCallParity Price function
	outf << "Price Using the Put Call Parity Relation" << endl;
	outf << "========================================" << endl;
	for (int i = 0; i != optionBatches.size(); ++i)
	{
		outf << "Batch " << i + 1 << "\nCALL: " << options[2 * i].Price(options[2 * i + 1]) << "; PUT: " << options[2 * i + 1].Price(options[2 * i]) << endl;
		outf << "-----------------------------------------" << endl;
	}

	outf << "Printing the Price Mesh for each batch" << endl;
	outf << "======================================" << endl;

	vector<double> tempPrices;

	// Vector of vectors of double - Each internal vector stores the prices for one batch
	vector<vector<double>> optionCallPrices; // Store the prices for each of the option batches
	vector<vector<double>> optionPutPrices; // Store the prices for each of the option batches

	for (int i = 0; i != optionBatches.size(); ++i)
	{
		// let us create a mesh of 101 different prices around the stockPrice of
		// individual batches
		h = options[2 * i].StockPrice() / numOfOptions;
		// Create a mesh
		stockMesh = CreateMesh(options[2 * i].StockPrice()*0.5, options[2 * i].StockPrice()*1.5, h);
		// Push option prices in the mesh. Use the Price_S function that gets the prices for changed stockPrice
		// keeping the rest of the option parameters same
		
		// CALL PRICES
		for (int j = 0; j != stockMesh.size(); ++j)
		{
			// 2i element in options is a call option for ith batch
			tempPrices.push_back(options[2 * i].Price_S(stockMesh[j]));
		}
		optionCallPrices.push_back(tempPrices);
		tempPrices.clear();

		// PUT PRICES
		for (int j = 0; j != stockMesh.size(); ++j)
		{
			// 2i+1 element in options is a put option for ith batch
			tempPrices.push_back(options[2 * i + 1].Price_S(stockMesh[j]));
		}
		optionPutPrices.push_back(tempPrices);
		tempPrices.clear();

		stockMesh.clear();
	}

	outf << endl;

	outf << "Options prices for a stock price mesh: Call Prices" << endl;
	outf << "==================================================" << endl;

	// Write the prices in the text file.
	// Also print the exact same output on screen
	for (int i = 0; i != optionCallPrices.size(); ++i)
	{
		outf << "Batch " << i + 1 << endl;
		outf << "-----------------------------------------------" << endl;
		cout << "Batch " << i + 1 << endl;
		cout << "-----------------------------------------------" << endl;

		for (int j = 0; j != optionCallPrices[i].size(); ++j)
		{
			outf << optionCallPrices[i][j] << ",";
			cout << optionCallPrices[i][j] << ",";

		}
		outf << endl << "-----------------------------------------------" << endl;
		cout << endl << "-----------------------------------------------" << endl;
	}

	outf << endl;

	outf << "Options prices for a stock price mesh: Put Prices" << endl;
	outf << "==================================================" << endl;


	for (int i = 0; i != optionPutPrices.size(); ++i)
	{
		outf << "Batch " << i + 1 << endl;
		outf << "-----------------------------------------------" << endl;
		cout << "Batch " << i + 1 << endl;
		cout << "-----------------------------------------------" << endl;

		for (int j = 0; j != optionCallPrices[i].size(); ++j)
		{
			outf << optionPutPrices[i][j] << ",";
			cout << optionPutPrices[i][j] << ",";

		}
		outf << endl << "-----------------------------------------------" << endl;
		cout << endl << "-----------------------------------------------" << endl;
	}

	// GROUP A: PART II
	//==========================================================================================
	//==========================================================================================
	outf << "LEVEL 9: GROUP A - PART II" << endl;
	outf << "==========================" << endl;

	OptionData futoptData(100, 105, .5, 0.1, 0.36);

	outf << "Future Option Parameters" << endl;
	outf << "------------------------" << endl;
	cout << "Future Option Parameters" << endl;
	cout << "------------------------" << endl;


	outf << "Stock Price: " << futoptData.S << endl;
	cout << "Stock Price: " << futoptData.S << endl;
	outf << "Strike Price: " << futoptData.K << endl;
	cout << "Strike Price: " << futoptData.K << endl;
	outf << "Volatility: " << futoptData.sig << endl;
	cout << "Volatility: " << futoptData.sig << endl;
	outf << "Expiry: " << futoptData.T << endl;
	cout << "Expiry: " << futoptData.T << endl;
	outf << "Interest Rate: " << futoptData.r << endl;
	cout << "Interest Rate: " << futoptData.r << endl;

	outf << "----------------------------------------------" << endl;

	outf << "Delta of the Future Option - CALL: " <<
		Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANCALL) << endl;

	cout << "Delta of the Future Option - CALL: " <<
		Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANCALL) << endl;

	outf << "Delta of the Future Option - PUT: " <<
		Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	cout << "Delta of the Future Option - PUT: " <<
		Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	outf << "----------------------------------------------" << endl;

	outf << "Gamma of the Future Option - CALL: " <<
		Gamma(futoptData.S,
		futoptData.K, 
		futoptData.T, 
		futoptData.sig, 
		futoptData.r, 
		0,
		EUROPEANCALL) << endl;

	cout << "Gamma of the Future Option - CALL: " <<
		Gamma(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANCALL) << endl;

	outf << "Gamma of the Future Option - PUT: " <<
		Gamma(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	cout << "Gamma of the Future Option - PUT: " <<
		Gamma(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	outf << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl << endl;

	vector<double> futureOptionCallDeltas;
	vector<double> futureOptionPutDeltas;

	h = futoptData.S / numOfOptions;
	
	// CLear the stock mesh 
	stockMesh.clear();
	// Create a mesh
	stockMesh = CreateMesh(futoptData.S*0.5, futoptData.S*1.5, h);
	
	// Push option deltas in the mesh. Using Lambda expressions
	// CALL DELTAS

	for_each(stockMesh.cbegin(), stockMesh.cend(), [&futoptData, &futureOptionCallDeltas](const double val) {
		futureOptionCallDeltas.push_back(Delta(val, futoptData.K, futoptData.T,
			futoptData.sig, futoptData.r, 0, EUROPEANCALL)); });

	for_each(stockMesh.cbegin(), stockMesh.cend(), [&futoptData, &futureOptionPutDeltas] (const double val) {
		futureOptionPutDeltas.push_back(Delta(val, futoptData.K, futoptData.T,
			futoptData.sig, futoptData.r, 0, EUROPEANPUT)); });

	outf << "Options deltas mesh for future option: Call Options" << endl;
	outf << "===================================================" << endl;

	cout << "Options deltas mesh for future option: Call Options" << endl;
	cout << "===================================================" << endl;

	for (int i = 0; i != futureOptionCallDeltas.size(); ++i)
	{
		outf << futureOptionCallDeltas[i] << ",";
		cout << futureOptionCallDeltas[i] << ",";

	}
	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;


	outf << "Options deltas mesh for future option: Put Options" << endl;
	outf << "===================================================" << endl;

	cout << "Options deltas mesh for future option: Put Options" << endl;
	cout << "===================================================" << endl;

	for (int i = 0; i != futureOptionPutDeltas.size(); ++i)
	{
		outf << futureOptionPutDeltas[i] << ",";
		cout << futureOptionPutDeltas[i] << ",";
	}

	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;

	// We will use h for the difference in divided difference method
	// h would be decreased in every iteration and the option delta would 
	// be calculated using the new difference
	// As h is decreased, the divided difference delta  and gamma 
	// should converge the actual values

	double numericalGreek;

	outf <<  "Numerically Calculated Greeks: Call Deltas" << endl;
	cout <<  "Numerically Calculated Greeks: Call Deltas" << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	outf << "Actual Call Delta = " << Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANCALL) << endl;

	cout << "Actual Call Delta = " << Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANCALL) << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	// Trying to go from h = 10 to 10*2^(-9)
	for (int i = 0; i < 10; ++i)
	{
		h = 10*pow(2, -i);
		numericalGreek = Delta(futoptData, 0, futoptData.S, h, EUROPEANCALL);

		outf << "h = " << h << "; Delta = " << numericalGreek << endl;
		cout << "h = " << h << "; Delta = " << numericalGreek << endl;
	}

	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;

	outf << "Numerically Calculated Greeks: Put Deltas" << endl;
	cout << "Numerically Calculated Greeks: Put Deltas" << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	outf << "Actual Put Delta = " << Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	cout << "Actual Put Delta = " << Delta(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	// Trying to go from h = 10 to 10*2^(-9)
	for (int i = 0; i < 10; ++i)
	{
		h = 10 * pow(2, -i);
		numericalGreek = Delta(futoptData, 0, futoptData.S, h, EUROPEANPUT);

		outf << "h = " << h << "; Delta = " << numericalGreek << endl;
		cout << "h = " << h << "; Delta = " << numericalGreek << endl;
	}

	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;

	outf << "Numerically Calculated Greeks: Call Gammas" << endl;
	cout << "Numerically Calculated Greeks: Call Gammas" << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	outf << "Actual Call Gamma = " << Gamma(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANCALL) << endl;

	cout << "Actual Call Gamma = " << Gamma(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANCALL) << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	// Trying to go from h = 10 to 10*2^(-9)
	for (int i = 0; i < 10; ++i)
	{
		h = 10 * pow(2, -i);
		numericalGreek = Gamma(futoptData, 0, futoptData.S, h, EUROPEANCALL);

		outf << "h = " << h << "; Gamma = " << numericalGreek << endl;
		cout << "h = " << h << "; Gamma = " << numericalGreek << endl;
	}

	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;

	outf << "Numerically Calculated Greeks: Put Gammas" << endl;
	cout << "Numerically Calculated Greeks: Put Gammas" << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	outf << "Actual Put Gamma = " << Gamma(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	cout << "Actual Put Gamma = " << Gamma(futoptData.S,
		futoptData.K,
		futoptData.T,
		futoptData.sig,
		futoptData.r,
		0,
		EUROPEANPUT) << endl;

	outf << "-----------------------------------------------" << endl;
	cout << "-----------------------------------------------" << endl;

	// Trying to go from h = 10 to 10*2^(-9)
	for (int i = 0; i < 10; ++i)
	{
		h = 10 * pow(2, -i);
		numericalGreek = Gamma(futoptData, 0, futoptData.S, h, EUROPEANPUT);

		outf << "h = " << h << "; Gamma = " << numericalGreek << endl;
		cout << "h = " << h << "; Gamma = " << numericalGreek << endl;
	}

	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;

	futureOptionCallDeltas.clear();
	futureOptionPutDeltas.clear();

	// We see that the divided difference methods converge for both 
	// Delta and Gamma by 0.05. So, we will take the value 0.05 for the
	// option mesh in the next segment of the code.
	h = 0.05;

	for_each(stockMesh.cbegin(), stockMesh.cend(), [&futoptData, &futureOptionCallDeltas](const double val) {
		futureOptionCallDeltas.push_back(Delta(futoptData, 0, val, 0.001, EUROPEANCALL)); });

	for_each(stockMesh.cbegin(), stockMesh.cend(), [&futoptData, &futureOptionPutDeltas](const double val) {
		futureOptionPutDeltas.push_back(Delta(futoptData, 0, val, 0.001, EUROPEANPUT)); });

	outf << "Options deltas mesh using numerical method: Call Options" << endl;
	outf << "========================================================" << endl;

	cout << "Options deltas mesh using numerical method: Call Options" << endl;
	cout << "========================================================" << endl;

	for (int i = 0; i != futureOptionCallDeltas.size(); ++i)
	{
		outf << futureOptionCallDeltas[i] << ",";
		cout << futureOptionCallDeltas[i] << ",";

	}
	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;


	outf << "Options deltas mesh using numerical method: Put Options" << endl;
	outf << "=======================================================" << endl;

	cout << "Options deltas mesh using numerical method: Put Options" << endl;
	cout << "=======================================================" << endl;

	for (int i = 0; i != futureOptionPutDeltas.size(); ++i)
	{
		outf << futureOptionPutDeltas[i] << ",";
		cout << futureOptionPutDeltas[i] << ",";
	}

	outf << endl << "-----------------------------------------------" << endl;
	cout << endl << "-----------------------------------------------" << endl;


	outf.close();
	return 0;
}