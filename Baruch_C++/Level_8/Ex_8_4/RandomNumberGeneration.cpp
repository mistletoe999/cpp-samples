// Ex 8.4: Random Number Generation
// Implement simulation of dice throwing

// Standard headers
#include <iostream>
#include <ctime>
#include <map>


// Boost Libraries
#include <boost/random.hpp>

// Global Constants
const int MAXOUTCOME = 6;

// namespaces
using namespace std;

int main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome; // Current outcome

	// Assign 0 to all to all 6 outcomes in the map
	for (int i = 0; i < MAXOUTCOME; i++)
	{
		statistics[i + 1] = i;
	}

	// Get user input for the number of trials

	int numTrials;

	cout << "Please enter the number of trials: ";
	cin >> numTrials;

	for (int i = 0; i < numTrials; i++)
	{
		outcome = six(myRng);
		switch (outcome)
		{
		case 1:
			statistics[1] += 1;
			break;
		case 2:
			statistics[2] += 1;
			break;
		case 3:
			statistics[3] += 1;
			break;
		case 4:
			statistics[4] += 1;
			break;
		case 5:
			statistics[5] += 1;
			break;
		case 6:
			statistics[6] += 1;
			break;
		default:
			break;
		}
	}

	// Print outcomes
	for (int i = 0; i < MAXOUTCOME; i++)
	{
		cout << "Trial " << i + 1 << " has " << setprecision(6) << (static_cast<double>(statistics[i+1])*100.00/static_cast<double>(numTrials)) << "% outcomes" << endl;
	}


	//  ANSWER: Output with 1000000 trials:
	//  Please enter the number of trials : 1000000
	//	Trial 1 has 16.6527% outcomes
	//	Trial 2 has 16.6808% outcomes
	//	Trial 3 has 16.6762% outcomes
	//	Trial 4 has 16.6756% outcomes
	//	Trial 5 has 16.6861% outcomes
	//	Trial 6 has 16.6301% outcomes
}