// Ex 1.3.6: Bit-shifts an integer to right and determines whether the
// shift was logical or arithmetic

#include <stdio.h>

int main() {
	int userInput, bitShiftedOutput, numShift = 2;
	
	// Get an integer input from user
	printf("Please enter an integer: ");
	scanf("%d", &userInput);

	// Shift the number by 2 bits on the right
	bitShiftedOutput = (userInput >> numShift);

	// Print the bit shifted output
	printf("The bit-shifted result is: %d\n", bitShiftedOutput);

	// Indicate whether a logical or an arithmetic shift
	if (userInput < 0 && bitShiftedOutput < 0) {
		printf("The sign was conserved. The shift is arithmetic");
	} else if (userInput < 0 && bitShiftedOutput > 0) {
		printf("The sign was not consereved. The shift is arithemetic");
	} else if (userInput > 0) {
		printf("The shift can be logical or arithmetic. Both conserve signs");
	}

	return 0;
}