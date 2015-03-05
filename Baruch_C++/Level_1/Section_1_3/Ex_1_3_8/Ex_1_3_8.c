// Ex 1.3.8: Displays the use of different C operators

#include <stdio.h>

int main()
{
	int x = 2;
	int y;
	int z;
	x *= 3 + 2; // equivalent to x = x*(3+2) = 2*5 = 10
	printf("x=%d\n", x); //outputs x=10
	x *= y = z = 4; //Now x = 10; assigns 4 to y and z and 
	// assigns x*4 to x which equals 10*4 =  40
	printf("x=%d\n", x); //outputs x=40
	x = y == z; //y==z is a logical statement and we get TRUE equivalent to 1
	// x is assigned TRUE
	printf("x=%d\n", x); //since we print x as integer, it prints x=1
	return 0;
}