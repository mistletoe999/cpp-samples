// Ex 1.3.9: Displays the use of ? : logical operator and ++ operator

#include <stdio.h>

int main()
{
	int x = 1;
	int y = 1;
	int z = 1;
	x += y += x; // assigns y = x + 1 = 2 and assigns x = y + 1 = 3

	printf("%d\n\n", (x<y) ? y : x); // Number 1: Since, x > y => *****prints 3*****
	// Also, due to '\n', a new blank line is also printed
	printf("%d\n", (x<y) ? x++ : y++); // Number 2: Should output y++, however, 
	// since '++' operator is after y, it print the value of y and then increments it
	// On the contrary, if it would have been ++y, the incremented value would have been 
	// displayed = > *****prints 2*****
	printf("%d\n", x); // Number 3: prints x which is equal to 3, hence the *****output is 3*****
	printf("%d\n", y); // Number 4: prints y which is equal to 3 now. Hence, *****output is 3*****
	return 0;

}