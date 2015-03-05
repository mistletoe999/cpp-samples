// Ex 1.4.1: Counts the number of characters, words and new lines
// in a user inputed string (uses while loop)

#include <stdio.h>
#include <ctype.h>

int main() {
	int countChar = 0, countWords = 0, countLines = 0, ch, prevCh;

	// Get user input
	printf("Please enter a sentence: ");
	prevCh = ' '; // Keeps track of the previous character typed
	// Helps in checking whether there has been a series of white spaces typed

	while ((ch = getchar()) != EOF && (ch != 26) && (ch != 4))
	{ 
		// New word everytime the previous character was a white space and new character is not
		if (isspace(prevCh) && !isspace(ch)) ++countWords;
		// Check new line and increment if true
		if (ch == '\n') ++countLines;
		// Increment number of characters
		++countChar;
		// Store previous characters
		prevCh = ch;

	}

	// Print output
	printf("\nNumber of characters: %d", countChar);
	printf("\nNumber of words: %d", countWords);
	printf("\nNumber of new lines: %d", countLines);
	return 0;
}