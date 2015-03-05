// Ex 1.7.1: Displays the use of pointers to swap two numbers

#include <stdio.h>
#include <stdlib.h>

// Functions

// Swap function: Swap the values pointed to by pa and pb
void swap(float * pa, float * pb) {
	// function takes two float pointers as arguments and 
	// swaps the values pointed to by them 
	float temp; // To store the temp value of one variable

	temp = *pa; 
	*pa = *pb; // Value of *pb copied to *pa
	*pb = temp;
}

int main() {
	float i, j; // Variables to store the two values

	//Print intro text and get the values of i and j from user
	printf("Please enter the value of i: ");
	scanf("%f", &i);

	printf("\nPlease enter the value of j: ");
	scanf("%f", &j);

	// Print out the user entered values
	printf("Values entered: i = %f, j = %f", i, j);

	// Swap the values of i and j: &i and &j grab the 
	// address of i and j respectively
	swap(&i, &j);

	// Print out the swapped values
	printf("\nSwapped Values of i and j: i = %f, j = %f", i , j);
	return 0;
}