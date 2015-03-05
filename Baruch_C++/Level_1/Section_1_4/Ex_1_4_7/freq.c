// Ex 1.4.6: Counts the number of 3's in a large integer
// and displays the number of times as string

#include <stdio.h>

int main()
{
	// Get user inputs
	int countThree = 0, ch;

	printf("Please start typing numbers: \n");

	while ((ch = getchar()) != EOF && ch != 26) {
		switch (ch)
		{
		case '3':
			countThree++;
			break;
		}
	}

	// print output
	printf("Number Three appeared %s %s", (countThree == 0 ? "zero" :
		countThree == 1 ? "one" : countThree == 2 ? "two" : "more than two"),
		countThree <= 1 ? "time" : "times");
	return 0;
}