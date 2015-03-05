// Ex 1.9.2: Gets user input as a string and writes it on a text file

#include <stdio.h>

int main() {
	int ch;
	FILE * fp;
	char fileName[30];

	// Get the user input for file name
	printf("Please specify the file name (as <filename>.txt): ");
	scanf("%s", fileName);
	
	printf("Please start typing\n");

	// Open the file for writing
	fp = fopen(&fileName, "w");

	// Remove standard inputs such a enters saved in the buffer
	fflush(stdin);
	while ((ch = getchar()) != 1) {
		fputc(ch, fp);
	}

	fprintf(fp, "\nCTRL + A is a correct ending!");

	// File writing complete. Close the file
	fclose(fp);

	// Give a message to user
	printf("File has been generated");
}