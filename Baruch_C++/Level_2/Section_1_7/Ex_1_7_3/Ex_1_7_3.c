// Ex 1.7.3: Displays the nuances of pointer arithmetic and the 
// relation between arrays and pointers

/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialse array
int a[] = { 0, 1, 2, 3, 4 };
int main()
{
	int i;
	int* p;
	for (i = 0; i <= 4; i++) PRD(a[i]); // 1: Runs along the loop and prints all the integers in array a
	// No line breaks in between print commands
	// ****OUTPUT: 01234**** 
	NL; // **** OUTPUT: New line or \n ****

	for (p = &a[0]; p <= &a[4]; p++) PRD(*p); // 2: p gets the address of the first element of array a
	// p++ gives the pointer to the next element of array
	// Hence, all the values of the array are dereferenced using * operator and printed without line breaks
	// ****OUTPUT: 01234**** 

	NL; 
	NL; // **** OUTPUT: New lines or \n\n ****
	
	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]); // 3:  p gets the address of the first element of array a
	// p[i] is equivalent to *(p+i) which is equivalent to output 2 above
	// ****OUTPUT: 01234**** 
	NL; // **** OUTPUT: New line or \n ****
	
	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 4: we know that a[] is equivalent to &a[0]
	// p initially gets the address of the first element of array a
	// In first iteration - it prints *p = a[0] = 0
	// In next iteration - p increments to p + 1 - points to second element of a
	// i is incremented to i + 1 = 1 
	// prints *(p + 1) = a[2] = 2
	// Similarly, in next iteration we get the output = a[4]
	// After this iteration, p + 2 > a + 4 or &a[0] + 4 or it is beyond the range of array 
	// ****OUTPUT: 024**** 
	
	NL; 
	NL; // **** OUTPUT: New lines or \n\n ****
	
	for (p = a + 4; p >= a; p--) PRD(*p); // 5: p gets the address of the fourth element of array a
	// Pointer is decremented thereafter to point to previous elemenr of array
	// Pointer is dereferenced in each iteration to print the value
	// The loops ends as soon as the pointer points to the first element or a[0]
	// ****OUTPUT: 43210**** 

	NL; // **** OUTPUT: New line or \n ****
	
	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]); // 6: p gets the address of the fourth element of array a
	// index is incremented thereafter till it is less than the length of the array = 4
	// p[-i] is equivalent to *(p - i) = *(&a[4] - i) = a[4-i]
	// Hence, it prints the 4th, 3rd, ... elements of array
	// ****OUTPUT: 43210****

	NL; // **** OUTPUT: New line or \n ****
	
	for (p = a + 4; p >= a; p--) PRD(a[p - a]); // 7: p gets the address of the fourth element of array a
	// p is decremented in every iteration to point to previous element - 3rd, 2nd, etc..
	// condition scheck whether p has reached the start of the array
	// in every iteration we print a[p - a] = a[p - &a[0]] = a[&a[0] + 4 - i - &a[0]] = a[4-i]
	// ****OUTPUT: 43210**** 

	NL; // **** OUTPUT: New line or \n ****
	return 0;

	// Complete Output:

	//	01234
	//	01234

	//	01234
	//	024

	//	43210
	//	43210
	//	43210
}