// Ex 1.3.7: Multiplies a positive integer by a power of 2 using bit-shift

#include <stdio.h>

int main() {
	unsigned int userInput, multPower;
	
	// Get user inputs: an integer and multiplication power
	printf("Please enter an integer: ");
	scanf("%d", &userInput);
	printf("Please enter the multiplication power: ");
	scanf("%d", &multPower);

	// Print the multiplied result using left bit shift
	printf("The multiplied result is: %d", (userInput << multPower));
	return 0;
}