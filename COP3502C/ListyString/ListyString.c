#include "ListyString.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char **argv);
int processInputFile(char *filename);
ListyString *createListyString(char *str);
ListyString *destroyListyString(ListyString *listy);
ListyString *cloneListyString(ListyString *listy);
void replaceChar(ListyString *listy, char key, char *str);
void reverseListyString(ListyString *listy);
ListyString *listyCat(ListyString *listy, char *str);
int listyCmp(ListyString *listy1, ListyString *listy2);
int listyLength(ListyString *listy);
void printListyString(ListyString *listy);
double difficultyRating(void);
double hoursSpent(void);

int main(int argc, char **argv)
{	
	// captures name of input file and calls processInputFile()
	processInputFile(argv[1]);

	//return 0
	return 0;
}

int processInputFile(char *filename)
{
	// opens file
	FILE *ifp = fopen(filename, "r");

	// checks if filename is wrong 
	if (ifp == NULL)
	{
		return 1;
	}

	// declares variables
	char buffer[1024];
	char *word;
	char command[2];
	char *key;
	char *str;
	char *dcommand;
	ListyString *s;

	// checks if buffer is not empty
	if (fscanf(ifp, "%s", buffer) != EOF)
	{
		// allocates space for the string
		word = malloc(sizeof(char) * (strlen(buffer) + 1));

		// Copy the buffer's contents into the newly allocated space.
		strcpy(word, buffer);

		// creates ListyString
		s = createListyString(word);

		// frees word
		free(word);
		word = NULL;
	}

	// goes through commands
	while (fscanf(ifp, "%s", command) != EOF)
	{
		// checks if command is @
		if (strcmp("@", command) == 0)
		{
			// dynamically allocates key 
			key = malloc(sizeof(char) + 1);

			// scans key into buffer
			fscanf(ifp, "%s", buffer);

			strcpy(key, buffer);

			// dynamically allocates str 
			str = malloc(sizeof(char) * (strlen(buffer) + 1));

			// scans str into buffer
			fscanf(ifp, "%s", buffer);

			strcpy(str, buffer);

			// calls function that belongs to command @
			replaceChar(s, *key, str);

			// frees key and str 
			free(key);
			key = NULL;
			free(str);
			str = NULL;

		}
		else if (strcmp("+", command) == 0)
		{
			fscanf(ifp, "%s", buffer);

			// dynamically allocates str 
			str = malloc(sizeof(char) * (strlen(buffer) + 1));
			strcpy(str, buffer);

			// calls function that belongs to command +
			listyCat(s, str);

			//str free
			free(str);
			str = NULL;
		}
		else if (strcmp("-", command) == 0)
		{
			// dynamically allocates key 
			key = malloc(sizeof(char) + 1);

			// scans key into key
			fscanf(ifp, "%s", buffer);
			strcpy(key, buffer);

			// calls function that belongs to command -
			replaceChar(s, key[0], "");

			// frees key
			free(key);
			key = NULL; 

		}
		else if (strcmp("?", command) == 0)
		{
			printf("%d\n", listyLength(s));
		}
		else if (strcmp("!", command) == 0)
		{
			printListyString(s);
		}
		else if (strcmp("~", command) == 0)
			reverseListyString(s);
	}

	//closes file 
	fclose(ifp);

	return 0;
}

ListyString *createListyString(char *str)
{
	// declares i
	int i;

	// creates struct 
	ListyString *s = malloc(sizeof(ListyString));

	if (str == NULL || strcmp("\0", str) == 0)
	{	
		s -> head = NULL;
		s -> length = 0;
		return s;
	}

	// sets length of ListyString in the struct
	s -> length = strlen(str);

	// mallocs tail for first one
	ListyNode *tail = malloc(sizeof(ListyNode));

	// links s to tail 
	s -> head = tail;

	// sets next to NULL
	tail -> next = NULL;
	//tail -> data = malloc(sizeof(char));
	tail -> data = str[0];

	// goes through and assigns each node
	for (i = 1; i < s -> length; i++)
	{
		// mallocs the next node 
		tail -> next = malloc(sizeof(ListyNode));

		// sets tail to be next
		tail = tail -> next;

		// sets the character to be str[i]
		tail -> data = str[i];

		// sets the next pointer to NULL
		tail -> next = NULL;
	}

	return s;
}

ListyString *destroyListyString(ListyString *listy)
{
	// first check if listy is NULL
	if (listy == NULL)
		return NULL;

	ListyNode *current = listy -> head;
	ListyNode *temp;

	if (listy -> head == NULL)
	{
		free(listy);
		listy = NULL;
		return NULL;
	}

	while (current != NULL)
	{
		temp = current;
		current = current -> next;
		free(temp);
	}

	listy -> length = 0;
	free(listy);
	listy = NULL;

	return NULL;
}

ListyString *cloneListyString(ListyString *listy)
{
	// declares i
	int i;

	if (listy == NULL)
		return NULL;

		// creates struct 
	ListyString *s = malloc(sizeof(ListyString));

	// sets length of ListyString in the struct
	s -> length = listy -> length;

	// mallocs tail for first one
	ListyNode *tail = malloc(sizeof(ListyNode));

	//mallocs tail for listy
	ListyNode *tail2 = malloc(sizeof(ListyNode));

	// links s to tail 
	s -> head = tail;

	// sets next to NULL
	tail -> next = NULL;

	tail2 = listy -> head;

	//tail -> data = malloc(sizeof(char));
	tail -> data = tail2 -> data;

	// goes through and assigns each node
	for (i = 1; i < s -> length; i++)
	{
		//sets tail2 to next
		tail2 = tail2 -> next;

		// mallocs the next node 
		tail -> next = malloc(sizeof(ListyNode));

		// sets tail to be next
		tail = tail -> next;

		// sets the character to be str[i]
		tail -> data = tail2 -> data;

		// sets the next pointer to NULL
		tail -> next = NULL;
	}

	return s;
}

void replaceChar(ListyString *listy, char key, char *str)
{
	int i, j, length2 = strlen(str);
	ListyNode *current = listy -> head;
	ListyNode *temp;
	ListyNode *previous = NULL;


	// checks for NULL
	if (listy == NULL || listy -> head == NULL)
	{
		return;
	}

	// checks if string is empty to implement remove
	if (str == NULL || strcmp(str, "") == 0)
	{
		// while loop through string 
		while (current != NULL)
		{	
			// checks if key is found
			if (current -> data == key)
			{
				// checks if the size is 1
				if (listy -> length == 1)
				{
					// deletes char
					free(listy -> head);
					listy -> head = NULL;
					listy -> length--;
					return;
				}

				// checks if at beginning 
				if (previous == NULL)
				{
					temp = current;
					listy -> head = current -> next;
					current = listy -> head;
					free(temp);
					listy -> length--;
				}
				// otherwise you do normal remove
				else
				{
					temp = current;
					previous -> next = current -> next;
					current = current -> next;
					free(temp);
					listy -> length--;
				}
			}
			// if key is not found continue
			else
			{
			previous = current;
			current = current -> next;
			}
		}
	}
	

	// goes through the listy string 
	while (current != NULL)
	{
		// checks if the current data is the key
		if (current -> data == key)
		{
			// if condition is true the length of the passed string is added
			listy -> length += length2 - 1;

			//skips the key
			current -> data = str[0];

			// strlen(str) iterations 
			for (j = 1; j < length2; j++)
			{
				temp = current -> next;
				current -> next = malloc(sizeof(ListyNode));
				current = current -> next;
				current -> data = str[j];
				current -> next = temp;
			}
		}

		// sets current to be the next one in the list
		current = current -> next;
	}
}

void reverseListyString(ListyString *listy)
{

	// checks for NULL
	if (listy == NULL || listy -> head == NULL)
		return;

	// checks if length is 1 which means you do nothing 
	if (listy -> length == 1)
		return;

	// sets variables
	ListyNode *current = listy -> head;
	ListyNode *next = NULL;
	ListyNode *previous = NULL;

	// reverses pointers
	while (current != NULL)
	{
		next = current -> next;
		current -> next = previous;
		previous = current;
		current = next;
	}
	listy -> head = previous;
}

ListyString *listyCat(ListyString *listy, char *str)
{
	// checks if both are NULL
	if (listy == NULL && str == NULL)
		return NULL;

	// checks if str is NULL or empty
	if (str == NULL || strcmp(str, "") == 0)
	{
		return listy;
	}

	//if listy is NULL and string is non-empty
	if (listy == NULL && strcmp(str, "") == 0)
	{
		return createListyString(str);
	}


	int i, length2 = strlen(str); 
	ListyNode *current = listy -> head;
	ListyNode *temp = listy -> head;

	if (current == NULL)
	{
		listy -> head = malloc(sizeof(ListyNode));
		listy -> head -> data = str[0];
		listy -> head -> next = NULL;
		current = listy -> head;

		for (i = 1; i < length2; i++)
		{
		current -> next = malloc(sizeof(ListyNode));
		current = current -> next;
		current -> data = str[i];
		current -> next = NULL;
		}
	}
	else
	{
		while (current -> next != NULL)
		{
			current = current -> next;
		}

		for (i = 0; i < length2; i++)
		{
			temp = current -> next;
			current -> next = malloc(sizeof(ListyNode));
			current = current -> next;
			current -> data = str[i];
			current -> next = temp;
		}
	}
	
	listy -> length += length2;
	return listy;


}

int listyCmp(ListyString *listy1, ListyString *listy2)
{
	// declares i 
	int i; 

	// checks if both are NULL
	if (listy1 == NULL && listy2 == NULL)
		return 0;

	// chekcs if one is null and one isn't 
	if ((listy1 == NULL && listy2 != NULL) || (listy1 != NULL && listy2 == NULL))
		return 1;

	// checks if their lengths are equal 
	if (listy1  -> length != listy2 -> length)
		return 1;

	ListyNode *current1 = listy1 -> head;
	ListyNode *current2 = listy2 -> head;

	while (current1 != NULL)
	{
		// checks if they're the same
		if (current1 -> data != current2 -> data)
		{
			return 1;
		}

		// sets current1 and current2 to next
		current1 = current1 -> next;
		current2 = current2 -> next;
	}

	return 0;
}

int listyLength(ListyString *listy)
{
	// check if listy is NULL
	if (listy == NULL)
		return -1;
	// check if head is NULL
	if (listy -> head == NULL)
		return 0;
	return listy -> length;
}

void printListyString(ListyString *listy)
{
	// declares i 
	int i;

	if(listy == NULL || listy -> length == 0)
	{
		printf("(empty string)\n");
		return;
	}

	ListyNode *temp = listy -> head;

	for (i = 0; i < listy -> length; i++)
	{
		printf("%c", temp -> data);
		temp = temp -> next;
	}

	printf("\n");
}

double difficultyRating(void)
{
	return 2.5;
}

double hoursSpent(void)
{
	return 9.0;
}