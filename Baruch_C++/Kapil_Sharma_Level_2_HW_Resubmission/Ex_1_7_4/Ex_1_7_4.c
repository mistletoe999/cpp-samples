// Ex 1.7.4: Implements a function that displays the 
// string representation of a day of the week

#include <stdio.h>
#include <string.h>

// Functions

// DayName: Returns the name of the day-number of the week
// Example: 1 returns "Sunday" and 7 returns "Saturday"
// Return type is pointer to the corresponding string
char * DayName(int n) {
	const char * dayName[] = {
		"Illegal Day",
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};

	// dayName[n] is a char pointer to nth day's string
	return ((n < 1 || n > 7 ?  dayName[0] : dayName[n]));
}

int main() 
{
	// Get user input
	int dayNumber;
	printf("Please enter the day-number: ");
	scanf("%d", &dayNumber);

	// Print output
	printf("Day %d is %s", dayNumber, DayName(dayNumber));
	return 0;
}