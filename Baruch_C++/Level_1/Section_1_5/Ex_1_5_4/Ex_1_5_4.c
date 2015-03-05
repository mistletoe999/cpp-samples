// Ex 1.5.4: Uses putchar to print an integer

#include <stdio.h>
#include <stdbool.h>

void printnumber(int number) {
	bool isNeg = false;
	int lastDigit;
	if (number < 0) {
		isNeg = true;
		lastDigit = -(number % 10); // In case of negative numbers, 
		// it is important to save the lastDigit, since if we have 
		// -2147483648, multiplying it by -1 will make the int value overflow
		// hence, lastDigit is saved to print at the end, in case the number 
		// negative
		number = -(number / 10); //Number divided by 10 and multiplied by -1
		// For the range [-2147483648 , 2147483647], it wont overflow
	}

	if (number / 10 != 0) {
		if (isNeg) 	putchar('-'); //If the number is negative, put a '-' sign
		printnumber(number / 10);
	}

	// 
	putchar((number % 10) + '0');
	if (isNeg) putchar(lastDigit + '0');
}

int main() {
	// Get the user inputs
	int userInput, check;
	printf("Enter a number to be printed: ");
	scanf("%d", &userInput);
	
	// Print the number using the function
	printnumber(userInput);
	return 0;
}