// Federico Baron COP3502C Spring 2019
// Trie prediction program 

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TriePrediction.h"

void printTrieHelper(TrieNode *root, char *buffer, int k);
void printTrie(TrieNode *root, int useSubtrieFormatting);
TrieNode *buildTrie(char *filename);
int processInputFile(TrieNode *root, char *filename);
TrieNode *destroyTrie(TrieNode *root);
TrieNode *getNode(TrieNode *root, char *str);
void getMostFrequentWord(TrieNode *root, char *str);
int containsWord(TrieNode *root, char *str);
int prefixCount(TrieNode *root, char *str);
double difficultyRating(void);
double hoursSpent(void);
int main(int argc, char **argv);
TrieNode *createTrieNode(void);
TrieNode *insertString(TrieNode *root, char *str);
void stripPunctuators(char *str);
TrieNode *getNodeP(TrieNode *root, char *str);

// Helper function called by printTrie(). (Credit: Dr. S.)
void printTrieHelper(TrieNode *root, char *buffer, int k)
{
	// initialize i
	int i;

	// base case 
	if (root == NULL)
		return;

	// print buffer if a word is found
	if (root->count > 0)
		printf("%s (%d)\n", buffer, root->count);

	// add null sentinel to string 
	buffer[k + 1] = '\0';

	// add letter to buffer
	for (i = 0; i < 26; i++)
	{
		buffer[k] = 'a' + i;

		// call recursively to keep building string 
		printTrieHelper(root->children[i], buffer, k + 1);
	}

	// add null sentinel 
	buffer[k] = '\0';
}

// If printing a subtrie, the second parameter should be 1; otherwise, if
// printing the main trie, the second parameter should be 0. (Credit: Dr. S.)
void printTrie(TrieNode *root, int useSubtrieFormatting)
{
	char buffer[1024];

	// to print subtrie
	if (useSubtrieFormatting)
	{
		strcpy(buffer, "- ");
		printTrieHelper(root, buffer, 2);
	}

	// to print trie
	else
	{
		strcpy(buffer, "");
		printTrieHelper(root, buffer, 0);
	}
}

// creates a node within a trie 
TrieNode *createTrieNode(void)
{
	// declrares i 
	int i;

	// allocate memory for the struct TrieNode
	TrieNode *s = malloc(sizeof(TrieNode));

	// allocate memory for the subtrie
	s -> subtrie = malloc(sizeof(TrieNode));

	// allocate memory for its 26 children
	for (i = 0; i < 26; i++)
	{
		s -> children[i] = NULL;
		s -> subtrie -> children[i] = NULL;
	}

	return s;
}

//credit to Dr. ZOOM- inserts a string to a trie 
TrieNode *insertString(TrieNode *root, char *str)
{
	int i, index, len = strlen(str);
	TrieNode *wizard;

	if (root == NULL)
		root = createTrieNode();

	// As I mentioned in class, the wizard starts at the root node and spells
	// out the string being) inserted as he/she jumps from node to node. (The
	// wizard is acting as a temp pointer.)
	wizard = root;

	for (i = 0; i < len; i++)
	{

		index = tolower(str[i]) - 'a';

		// Before the wizard can move forward to the next node, (s)he needs to
		// make sure that node actually exists. If not, create it!
		if (wizard->children[index] == NULL)
			wizard->children[index] = createTrieNode();

		// Now the wizard is able to jump forward.
		wizard = wizard->children[index];
	}

	// When we break out of the for-loop, the wizard should be at the terminal
	// node that represents the string we're trying to insert.
	wizard->count++;

	return wizard;
}


// removes punctuation from a string 
void stripPunctuators(char *str)
{
	// declare and initialize variables used
	int i, j = 0, length = strlen(str);
	// go thorugh string and remove non Alpha characters by skipping them
	for (i = 0; i < length; i++)
	{
		// if it is an alpha character it is set to str[j++], and then j increases
		if (isalpha(str[i]))
		{
			str[j++] = str[i];
		}
	}

	// add null character at the end to denote end of string 
	str[j] = '\0';
}

// builds a trie 
TrieNode *buildTrie(char *filename)
{
	// opens file
	FILE *ifp = fopen(filename, "r");

	// if file does not exist then return null
	if ((ifp = fopen(filename, "r")) == NULL)
	{
		return NULL;
	}

	// buffer for file strings
	char buffer[1024];

	// creates original trie 
	TrieNode *s = createTrieNode();

	TrieNode *prev = NULL;
	TrieNode *current;
	TrieNode *root;

	// keep going until end of file
	while (fscanf(ifp, "%s", buffer) != EOF)
	{
		int length = strlen(buffer) - 1;

		// flag for seeing if it is the end of the sentence
		int flag = 0;

		// if end of sentence punctuation then set flag to true 
		if (buffer[length] == '!' || buffer[length] == '.' || buffer[length] == '?'){
			flag = 1;
		}

		// call stripPunctuators
		stripPunctuators(buffer);

		// set current to be the root of the string insterted
		current = insertString(s, buffer);

		// if prev is not null then add next string to the previous subtrie
		if (prev != NULL)
			insertString(prev->subtrie, buffer);

		// set prev to be current to continue with loop 
		prev = current;

		// if flag is true then set prev to null so nothing else is inserted
		if (flag)
		{
			prev = NULL;
		}
	}

	return s;
	
}

void toLowercase(char *str)
{
	// takes the length of the str passed and saves it 
	int length = strlen(str);

	// bring every single character to lowercase
	for(int j = 0; j < length; j++)
	{
		str[j] = tolower(str[j]);
	}
}

int processInputFile(TrieNode *root, char *filename)
{
	// declare variables
	char buffer[1024];
	char *str = malloc(sizeof(char)*1024);
	int n;
	int i;
	TrieNode *tempRoot;

	// opens file
	FILE *ifp = fopen(filename, "r");

	// checks if the file exists
	if (ifp == NULL)
	{
		return 1;
	}

	// goes through file 
	while (fscanf(ifp, "%s ", buffer) != EOF)
	{
		// if buffer contains @ then do trie prediction feature
		if (strcmp(buffer, "@") == 0)
		{
			// scans next string
			fscanf(ifp, "%s", str);

			// scans next integer
			fscanf(ifp, "%d", &n);

			// prints og string
			printf("%s", str);

			for (i = 0; i < n; i++)
			{
				// String to lowercase
				toLowercase(str);

				// tempRoot is the root of the end of str 
				tempRoot = getNode(root, str);

				// check if they're not NULL
				if(tempRoot != NULL && tempRoot -> subtrie != NULL)
				{
					// use getMostFrequentWord to save it in str
					getMostFrequentWord(tempRoot -> subtrie, str);

					// if str is not within the trie then break
					if(containsWord(root, str) == 0)
						break;

					// print the string
					printf(" %s", str);
				}
				// if one of them is NULL then break out
				else
					break;
			}
			printf("\n");
		}
		else if (strcmp(buffer, "!") == 0)
		{
			// jusdt print the trie 
			printTrie(root, 0);
		}
		else
		{
			// print contents of buffer
			printf("%s\n", buffer);

			// bring buffer to lowercase
			toLowercase(buffer);

			// temp root is the root of the end of str 
			tempRoot = getNode(root, buffer);

			if (tempRoot != NULL && tempRoot -> subtrie != NULL)
				if (prefixCount(tempRoot -> subtrie, "") != 0)
					printTrie(tempRoot -> subtrie, 1);
				else
					printf("(EMPTY)\n");
			// if tempRoot is NULL then the str is empty 
			else if (tempRoot != NULL)
				printf("(EMPTY)\n");
			else
				printf("(INVALID STRING)\n");
		}
	}	

	// frees dynamically allocated memory
	free(str);

	// closes file
	fclose(ifp);


	return 0;
}

TrieNode *destroyTrie(TrieNode *root)
{
	int i;

	// base case 
	if(root == NULL)
		return NULL;

	// go thru all 26 letters and check if their children
	for(i = 0; i < 26; i++)
	{
		if(root -> children[i] != NULL)
		{
			//destroy children and subtries recursively 
			destroyTrie(root -> children[i]);
			destroyTrie(root -> children[i] -> subtrie);
		}
	}

	// frees the root
	free(root);

	return NULL;
}

// gets the location of the end of the str 
TrieNode *getNode(TrieNode *root, char *str)
{
	// base case
	if (root == NULL)
		return NULL;

	// checks if the length of the str is 0
	if (strlen(str) == 0)
	{
		if (root -> count == 0)
		 	return NULL;
		return(root);
	}

	// call recursively 
	return(getNode(root -> children[str[0]-'a'], str + 1));
}

// gets the location of the end of the str 
TrieNode *getNodeP(TrieNode *root, char *str)
{
	// base case
	if (root == NULL)
		return NULL;

	// checks if the length of the str is 0
	if (strlen(str) == 0)
	{
		return(root);
	}
	
	// call recursively 	
	return(getNodeP(root -> children[str[0]-'a'], str + 1));
}

void getMostFrequentWordHelper(TrieNode *root, char *str, char *tempStr, int *max, int k)
{
	// declare i
	int i;

	// checks if NULL, if so str is set to empty and function is exited 
	if (root == NULL)
		return;

	// if the count is > than max it means it's the new most frequent str
	if (root -> count > *max)
	{
		strcpy(str, tempStr);
		*max = root -> count;
		strcpy(tempStr,"");
	}

	// add null sentinel to end of tempStr
	tempStr[k + 1] = '\0';

	// go thru alphabet adding a char to tempStr
	for (i = 0; i < 26; i++)
	{
		tempStr[k] = 'a' + i;

		// call recursively 
		getMostFrequentWordHelper(root->children[i], str, tempStr, max, k + 1);
	}

	// add null sentinel
	tempStr[k] = '\0';
}

void getMostFrequentWord(TrieNode *root, char *str)
{
	// declare variables
	int *max = malloc(sizeof(int));
	char tempStr[1024];
	strcpy(str,"");
	getMostFrequentWordHelper(root, str, tempStr, max, 0);

}

// checks if word is in the Trie 
int containsWord(TrieNode *root, char *str) 
{
	// base case
	if (root == NULL)
		return 0;

	if (strlen(str) == 0)
	{
		if (root -> count == 0)
			return 0;

		return 1;
	}

	// recursive call
	return(containsWord(root -> children[str[0]-'a'], str + 1));
}

// gets the amount of words in the trie 
int getCount(TrieNode *root, int *count2)
{
	int i;

	if(root == NULL)
		return *count2;

	if(root -> count > 0)
	{
		*count2 += root -> count;
	}

	for(i = 0; i < 26; i++)
	{
		if(root -> children[i] != NULL)
		{
			getCount(root -> children[i], count2);
		}
	}

	return *count2;
}

// gets a count of strings that contain the prefix at the beginning 
int prefixCount(TrieNode *root, char *str)
{
	// initialize count2
	int *count2 = malloc(sizeof(int));

	// call helper
	return(getCount(getNodeP(root, str), count2));

	free(count2);
}

double difficultyRating(void)
{
	return 2.0;
}

double hoursSpent(void)
{
	return 6.0;
}

int main(int argc, char **argv)
{
	// sets root to be what is returned from buildTrie() which is the root 
	TrieNode *root = buildTrie(argv[1]);

	// process input using the root of the trie and the filename captured
	processInputFile(root, argv[2]);

	// destroy the trie
	destroyTrie(root);


	return 0;
}
