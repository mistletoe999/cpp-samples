// Compilation Notes:
// Please include the Project Directory - <path to project>/Level_9/Ex_9_Group_E in
// properties -> VC++ directories

// The code has been created from Dr.Duffy's TestTwoCurves.
// We will create an excel with Call and Put Prices 
// and save these for each batch
// Thee prices would be used in the Excel to create a chart 
// displaying both call and put prices for each batch

#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"

#include <cmath>
#include <list>
#include <string>

// EDIT
#include "Pricing.hpp"
#include "VanillaOption.hpp"
#include "OptionException.hpp"
#include "NormalDistribution.hpp"
#include "MeshCreator.hpp"

// EDIT
#include <vector>

// EDIT
using namespace std;
using namespace OPTIONPRICING;
using namespace OPTIONPRICING::PRICING;
using namespace OPTIONPRICING::NORMALDISTRIBUTIONS;
using namespace OPTIONPRICING::EXCEPTIONS;
using namespace OPTIONPRICING::VANILLAOPTIONS;

int main()
{
	long numPrices = 100;

	// EDIT:
	// Create vectors of prices
	vector<double> callPrices;
	vector<double> putPrices;
	vector<double> stockMesh;

	double lowerMultiple = 0.5; // Start from S*lowerMultiple
	double upperMultiple = 1.5; // Start from S*lowerMultiple

	// Change OptionData here to get the Excel for different batches
	OptionData opData(65, 60, .25, 0.08, .30);

	// Divide the mesh into numPrices segments between upperMultiple and
	// lowerMultiple
	double h = (opData.S*upperMultiple - opData.S*lowerMultiple) / numPrices;

	// Create stock mesh
	stockMesh = CreateMesh(opData.S*lowerMultiple, opData.S*upperMultiple, h);

	// push_back option prices into the vectors
	for_each(stockMesh.cbegin(), stockMesh.cend(), [&opData, &callPrices](const double val) {
		callPrices.push_back(BlackScholesPrice(val, opData.K, opData.T,
			opData.sig, opData.r, opData.r, EUROPEANCALL)); });

	for_each(stockMesh.cbegin(), stockMesh.cend(), [&opData, &putPrices](const double val) {
		putPrices.push_back(BlackScholesPrice(val, opData.K, opData.T,
			opData.sig, opData.r, opData.r, EUROPEANPUT)); });


	Vector<double, long> calls(numPrices, 0.0);
	Vector<double, long> puts(numPrices, 0.0);
	Vector<double, long> stockP(numPrices, 0.0);

	// Since Dr.Duffy's code works in his Vector data structure
	// I will transfer all the prices and stock mesh into Vector class

	for (long j = stockP.MinIndex(); j <= stockP.MaxIndex(); ++j)
	{
		stockP[j] = stockMesh[j];
	}

	for (long j = calls.MinIndex(); j <= calls.MaxIndex(); ++j)
	{
		calls[j] = callPrices[j];
	}

	for (long j = puts.MinIndex(); j <= puts.MaxIndex(); ++j)
	{
		puts[j] = putPrices[j];
	}

	std::cout << "Data has been created\n";

	try
	{
		// Create Excel output
		printPairExcel(stockP, calls, puts,
			string("Option Prices"), string("Stock Prices"), string("Option Price"));
	}
	catch (DatasimException& e)
	{
		e.print();
	}

	return 0;
}
