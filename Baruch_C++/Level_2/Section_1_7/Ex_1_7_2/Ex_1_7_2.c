// Ex 1.7.2: Implement a length function to calculate the length of a string

/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30

// String lenght declaration
int Length(char str[]);

int main()
{
	char string[MAXLINE + 1]; // Line of maximum 30 chars + \0
	int c; // The input character
	int i = 0; // The counter
	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
	
	// Get the characters
	while ((c = getchar()) != EOF && i<MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0
	
	// Print the output: length of string
	printf("String length is %d\n", Length(string));
	return 0;
}

// Length function: Gets the length of a string 
int Length(char str[])
{
	int len; // Stores the length 
	// 1st way to implement
	// str[] is equivalent to *(&str[0]), 
	// str is a pointer to the first element of the array 
	// hence , to access the next char
	// in the string, we just need to increment the pointer
	// We check for the end of the string by checking for '\0'

	for (len = 0; *str != '\0'; str++) len++;
	
	// ************************************************************
	// 2nd way to implement
	// This method uses the array indeces to get the value of char
	// in each iteration of loop.
	// str[len] is equivalent to *(str + len)

	//And, here is the alternate
	//for (len = 0; str[len] != '\0'; len++);

	// ************************************************************
	return len;
}