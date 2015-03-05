// Ex 1.5.2: Uses a recursive factorial function to calculate the 
// factorial of a function

#include <stdio.h>

int factorial(int num)
{
	int fact;
	// Base Conditions
	if (num == 1 || num == 0) {
		fact = 1;
	}
	// Recursion
	else {
		fact = num*factorial(num - 1);
	}
	return(fact);
}

int main()
{
	// Get user inputs
	int number;
	printf("Find factorial for: ");
	scanf("%d", &number);

	// Output the result
	printf("The factorial for %d is: %d", number, factorial(number));
	return 0;
}