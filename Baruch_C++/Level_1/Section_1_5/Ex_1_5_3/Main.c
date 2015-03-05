// Ex 1.5.3: Uses a print function to print the user-input multiplied by 2
// Calls Print.h header in the local directory

#include "Print.h"
#include <stdio.h>

int main()
{
	// Get the user input
	float userInput, printOutput;
	printf("Please enter a number: ");
	scanf("%f", &userInput);

	// Print the output
	printOutput = print(userInput);
	printf("Number multiplied by 2 = %f", printOutput);
	getchar();
	return 0;
}
