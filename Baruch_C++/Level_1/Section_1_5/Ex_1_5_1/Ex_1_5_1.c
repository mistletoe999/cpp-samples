// Ex 1.5.1: Uses a function minus to calculate the difference between two
// numbers

#include <stdio.h>

double minus(float num1, float num2)
{
	return(num1 - num2);
}

int main()
{
	// Get user inputs
	float number1, number2, diff;

	printf("Enter number 1: ");
	scanf("%f", &number1);

	printf("Enter number 2: ");
	scanf("%f", &number2);

	// Output the result
	diff = minus(number1, number2);
	printf("The difference (number1 - number2) = %f", diff);
	return 0;
}