// Ex 1.4.3: Counts the number of characters, words and new lines
// in a user inputed string (uses while loop and switch-case statements)

#include <stdio.h>
#include <stdbool.h>

int main() {
	int countChar = 0, countWords = 0, countLines = 0, prevCh, ch;
	prevCh = ' ';

	printf("Please enter a sentence: ");

	while ((ch = getchar()) != EOF && (ch != 26) && (ch != 4))
	{
		++countChar; // Increment the number of characters
		switch (isspace(ch))
		{
		case false:
			// Check prev character to get new word
			switch (isspace(prevCh)) 
			{
			case false: // Do nothing if both are non-spaces
				break;
			default: // if prevCh is a space character and current character is not: increment number of words
				++countWords;
				break;
			}
		default:
			switch (ch)
			{
			case '\n': // Increment new lines if true
				++countLines;
			default: // as default, nothing needs to be done.
				break;
			}
			break;
		}
		prevCh = ch;
	}

	// Print the output

	printf("\nNumber of characters: %d", countChar);
	printf("\nNumber of words: %d", countWords);
	printf("\nNumber of new lines: %d", countLines);
	return 0;
}