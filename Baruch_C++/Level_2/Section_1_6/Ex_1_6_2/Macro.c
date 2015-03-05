// Ex 1.6.2: Displays the use of macros
// Calls Defs.h for the definitions macros

#include <stdio.h>
#include "Defs.h"

int main() {
	// Get user inputs for MAX2
	float x1, y1, x2, y2, z2;
	printf("OUTPUT OF MAX2\n");
	printf("Please enter number 1: ");
	scanf("%f", &x1);
	printf("Please enter number 2: ");
	scanf("%f", &y1);

	// Print output of MAX2
	printf("The maximum of the two numbers is: %f", MAX2(x1, y1));

	// Get user inputs for MAX3
	printf("\nOUTPUT OF MAX3\n");
	printf("Please enter number 1: ");
	scanf("%f", &x2);
	printf("Please enter number 2: ");
	scanf("%f", &y2);
	printf("Please enter number 3: ");
	scanf("%f", &z2);

	// Print output for MAX3
	printf("The maximum of the three numbers is: %f", MAX3(x2, y2, z2));
	return 0;
}