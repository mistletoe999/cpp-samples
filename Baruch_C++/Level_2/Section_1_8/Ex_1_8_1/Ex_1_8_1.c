// Ex 1.8.1: Displays the use of structures:
// Implemented an Artcle structure

#include <stdio.h>
#include <string.h>

// Structure Article
struct Article
{
	unsigned int articleNumber; // Article Number
	unsigned int quantity; // Quantity
	char description[20]; // Description of the article
};

// Print function: To print the structure Article's values
Print(struct Article * article) { // Takes address to an Article structure as parameter
	printf("Article Number: %d\n", article->articleNumber);
	printf("Quantity: %d\n", article->quantity);
	printf("Description: %s\n", article->description);

}

int main() 
{
	struct Article newArticle; // Initiate a new article
	// Assign values
	newArticle.articleNumber = 1; 
	newArticle.quantity = 10 ;
	strcpy(newArticle.description, "My Article");

	// Print output
	Print(&newArticle);

	return 0;
}