// Ex 1.3.4: Displays that any number apart from 0 is treated as true as boolean in C

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int isMarried = 0; // 0 indicates not married and any other integer indicates married
	char* marriedString; // stores a "not" or blank based on the isMarried's value
	marriedString = (isMarried == false) ? "not " : ""; // Calculate married string

	// Print output
	printf("Kapil is %smarried", marriedString);
	return 0;
}