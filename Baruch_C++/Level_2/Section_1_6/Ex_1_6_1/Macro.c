// Ex 1.6.1: Displays the use of macros in C
// Calls the Defs.h for the definitions of the macros

#include <stdio.h>
#include "Defs.h"

int main()
{
	// Get User Inputs
	float a, b;
	printf("Please enter the value of variable a: ");
	scanf("%f", &a);
	printf("Please enter the value of variable b: ");
	scanf("%f", &b);


	// Use Macros to print out values
	printf("OUTPUT OF MACRO PRINT1\n");
	PRINT1(a);
	printf("\nOUTPUT OF MACRO PRINT2\n");
	PRINT2(a, b);

	return 0;
}