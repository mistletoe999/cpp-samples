// Ex 1.3.5: Displays the difference between c-- and --c

#include <stdio.h>

int main() {
	int ctr = 10;

	printf("Initially ctr is defined as 10\n");
	printf("Printing ctr till 1 checking condition ctr-- > 1\n");
	while (ctr-- > 1) {
		printf("%d", ctr);
	}
	// In the last iteration ctr is checked against 1 and then 
	// decremented. Hence, we get 987654321 as output above
	printf("\n");
	ctr = 10;

	printf("Printing ctr till 1 checking condition --ctr > 1\n");
	while (--ctr > 1) {
		printf("%d", ctr);
	}
	// In the last iteration ctr is decremented first and then 
	// checked against 1. Hence, the loop ends at ctr = 2.
	// Hence, we get 98765432 as output above
	getchar();
	return 0;
}