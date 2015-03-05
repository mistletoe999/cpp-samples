// Ex 1.4.6: Counts the number of 1's, 2's, 3's, 4's and others in 
// a long integer

#include <stdio.h>

int main()
{
	// Get user input 
	int countZero = 0,
		countOne = 0,
		countTwo = 0,
		countThree = 0,
		countFour = 0,
		countOther = 0;
	int ch;

	printf("Please start typing numbers: \n");
	// Start counting the frequency of each of the four numbers and others
	while ((ch = getchar()) != EOF && ch != 26) {
		switch (ch)
		{
		case '0':
			countZero++;
			break;
		case '1':
			countOne++;
			break;
		case '2':
			countTwo++;
			break;
		case '3':
			countThree++;
			break;
		case '4':
			countFour++;
			break;
		default:
			countOther++;
			break;
		}
	}

	// Print output
	printf("Total number of zero's: %d\n", countZero);
	printf("Total number of one's: %d\n", countOne);
	printf("Total number of two's: %d\n", countTwo);
	printf("Total number of three's: %d\n", countThree);
	printf("Total number of four's: %d\n", countFour);
	printf("Total number of other character: %d\n", countOther);
	return 0;
}