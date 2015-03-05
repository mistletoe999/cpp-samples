// Ex 1.4.4: Displays conversion of Fahrenheit scale to Celsius scale of temperature

#include <stdio.h>

int main()
{
	float startTemp = 0.0, endTemp = 300.0, iter, stepSize = 20.0;
	char userDecision = 'N';

	// Get user input whether he/she wants to add user defined values or default values
	printf("Do you want to specify the step size and 'start' & 'end' temperatures for the scale (Y/N)?: ");
	scanf("%c", &userDecision);

	// If user says yes, get the user inputs
	if (userDecision == 'Y') {
		printf("Please enter the step size: ");
		scanf("%f", &stepSize);

		printf("Please enter values in multples of %f\n", stepSize);
		printf("Please enter the start temperature: ");
		scanf("%f", &startTemp);

		printf("Please enter the end temperature: ");
		scanf("%f", &endTemp);
	}

	// Start printing output
	printf("TEMPERATURE SCALE\nFahrenheit Value, Celsius Value\n");

	iter = startTemp;

	while (iter <= endTemp) {
		// In every iteratio, deg F value = iter and deg C value = (5.0 / 9.0)*(iter - 32.0)
		printf("%10.1f,%10.1f\n", iter, (5.0 / 9.0)*(iter - 32.0));
		iter += stepSize;
	}

	return 0;
}