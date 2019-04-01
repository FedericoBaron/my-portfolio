// Federico Baron COP3502C Spring 2019 fe960661

#include "DupeyDupe.h"
#include <stdio.h>
#include <string.h>

double difficultyRating(void);
double hoursSpent(void);

int main(int argc, char **argv)
{	

	// initializes i, j and dupedupe
	int i, j, dupedupe;

	// checks if dupe is repeated 2 times in a row
	for (i = 1; i < argc - 2; i++)
		if (strcmp(argv[i],argv[i+1]) == 0 && strcmp(argv[i], "dupe") == 0)
			dupedupe = 1;

	// looks for last repeated words
	for (i = argc - 1; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			// checks if argv[i] and argv[j] are the same
			if (strcmp(argv[i], argv[j]) == 0)
			{

				// prints out the word that is the last repeated word
				printf("%s\n", argv[i]);

				// prints dupe dupe if dupedupe is 1
				if (dupedupe == 1)
					printf("dupe dupe!\n");

				return 0;
			}
		}
	}

	// prints no dupey dupe if there is no repeated word.
	printf("no dupey dupe :(\n");	

	return 0;
}

double difficultyRating(void)
{
	return 1.7;
}

double hoursSpent(void)
{
	return 3.5;
}
