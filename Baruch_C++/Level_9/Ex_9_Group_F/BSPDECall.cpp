// Compilation Notes:
// Please include the Project Directory - <path to project>/Level_9/Ex_9_Group_F in
// properties -> VC++ directories

// BSPDECall.cpp
// Modified Dr. Duffy's code for getting Put prices 
// The Modified code contains the BC's of Call options
// Smax has been assumed to be 5*K

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"

namespace BS // Black Scholes
{
	// EDIT //
	// Batch Data
	// Putting diffrent values based on batches 
	// Batch 1: T = 0.25, K = 65, sig = 0.30, r = 0.08, S = 60 (then C = 2.13293, P = 5.84584).
	// Batch 2 : T = 1.0, K = 100, sig = 0.2, r = 0.0, S = 100 (then C = 7.96632, P = 7.96632).
	// Batch 3 : T = 1.0, K = 10, sig = 0.50, r = 0.12, S = 5 (C = 0.204121, P = 4.0733).
	// Batch 4 : T = 30.0, K = 100.0, sig = 0.30, r = 0.08, S = 100.0 (C = 92.1749, P = 1.24651).

	// Actual Prices from BS

	// Batch 1
	// CALL: 2.13337; PUT: 5.84628
	// Batch 2
	// CALL : 7.96557; PUT: 7.96557
	// Batch 3
	// CALL : 0.204058; PUT: 4.07326
	// Batch 4
	// CALL : 92.1757; PUT: 1.2475

	double sig = 0.30;
	double K = 100.0; 
	double T = 30.0;
	double r = 0.08;
	double D = 0.0; // aka q

	double mySigma(double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu(double x, double t)
	{

		return (r - D) * x;

	}

	double myB(double x, double t)
	{

		return  -r;
	}

	double myF(double x, double t)
	{
		return 0.0;
	}

	double myBCL(double t)
	{
		// EDIT : Left boundary condition for Call Prices
		// Call
		return 0.0;
	}

	double myBCR(double t)
	{
		// EDIT: Right boundary condition for Call Prices
		// Call
		// Smax = 5*K
		return 5 * K - K * exp(-r * t); // C
	}

	double myIC(double x)
	{ // Payoff 
		// Call Payoff
		return max(x - K, 0.0);
	}

}


int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	int J = 5 * BS::K; int N = 1000000 - 1; // k = O(h^2) !!!!!!!!!

	double Smax = 5 * BS::K;			// Magix

	cout << "start FDM\n";
	FDMDirector fdir(Smax, BS::T, J, N);

	fdir.doit();

	cout << "Finished\n";

	// Output to MS Excel
	printOneExcel(fdir.xarr, fdir.current(), string("Value"));

	return 0;
}
