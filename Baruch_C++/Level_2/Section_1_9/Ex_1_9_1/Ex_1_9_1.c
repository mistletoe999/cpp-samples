// Ex 1.9.1: Displays the use of getchar and putchar to get user input
// and display it on the console

#include <stdio.h>
#include <stdlib.h>

int main() {
	int ch;
	// Get user input
	printf("Please start typing\n");

	while ((ch = getchar()) != 1) {
		putchar(ch); // Buffer the output and print using putchar
	}

	// Print the required text
	printf("\nCTRL + A is a correct ending!");
}