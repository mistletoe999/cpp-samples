// Ex 1.4.4: Displays conversion of Celsius scale to Fahrenheit scale of temperature

#include <stdio.h>

int main()
{
	float startTemp = 1, endTemp = 19, iter = 0, stepSize = 1;
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
	printf("TEMPERATURE SCALE\nCelsius Value, Fahrenheit Value\n");
	for (iter = startTemp; iter <= endTemp; )
	{
		// In every iteration, deg C = iter and deg F = ((9.0 / 5.0) * iter) + 32)
		printf("%10.1f,%10.1f\n", iter, ((9.0 / 5.0) * iter) + 32);
		iter += stepSize;
	}
	return 0;
}