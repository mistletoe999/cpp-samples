// Ex 1.4.2: Counts the number of characters, words and new lines
// in a user inputed string (uses do...while loop)

#include <stdio.h>
#include <ctype.h>

int main() {
	int countChar = 0, countWords = 0, countLines = 0, ch, prevCh;
	
	prevCh = ' '; // Keeps track of the previous character typed
	// Helps in checking whether there has been a series of white spaces typed

	// Get user input
	printf("Please enter a sentence: ");

	do {
		ch = getchar();
		if (!(isspace(prevCh)) && (isspace(ch) || ch == 26 || ch == 4)) ++countWords;
		if (ch == '\n') ++countLines;
		if (ch != EOF && ch != 26 && ch != 4) {
			countChar++;
			prevCh = ch;
		}
	} while (ch != EOF && (ch != 26) && (ch != 4));

	// Output Results
	printf("\nNumber of characters: %d", countChar);
	printf("\nNumber of words: %d", countWords);
	printf("\nNumber of new lines: %d", countLines);

	return 0;
}