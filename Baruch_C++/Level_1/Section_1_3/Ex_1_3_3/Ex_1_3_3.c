// Ex 1.3.3: Displays use of arithmetic operators and their precedence

#include <stdio.h>

int main()
{
	int x;
	x = -3 + 4 * 5 - 6; //This line will assign x = -3 + 20 - 6 = 11. Since
	// it is an integer, it will display 11
	// x = 11
	printf("x=%d\n", x); // prints x=11
	x = 3 + 4 % 5 - 6; // 4 % 5 gives the remainder when 4 is divided by 5 = 4
	// Hence assigns x = 3 + 4 - 6 = 1, which is an integer. Hence, it should display
	// x = 1
	printf("x=%d\n", x); //prints x=1
	x = -3 * 4 % -6 / 5; // This simplifies to -12 % -6 / 5 = 0 / 5 = 0
	// x = 0
	printf("x=%d\n", x); // prints x=0
	x = (7 + 6) % 5 / 2; // This simplifies to 13 % 5 / 2 = 3 / 2 = 1.5
	// This is not an integer. Hence, %d will only print the '1' part of 1.5 
	printf("x=%d\n", x); // prints x=1
	return 0;
}