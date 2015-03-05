// Ex 1.3.2: Calculates the area of a right traingle from user inputs (base, height)

#include <stdio.h>

int main()
{
	float base, height, area;
	printf("RIGHT TRIANGLE AREA\n\n");

	// Ask user for the base and height
	printf("Please enter length of triangle's base: ");
	scanf("%f", &base);
	printf("Please enter length of triangle's height: ");
	scanf("%f", &height);

	// Calculate area
	area = 0.5*base*height;
	
	// Print area
	printf("\nThe area of the right triangle is: %f\n", area);
	return 0;
}