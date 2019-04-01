// Federico Baron COP3502C Spring 2019 fe960661
// I'm making a lonely party array data structure which has the job of minimizing memory usage when compared to a regular array 

#include <stdio.h>
#include <stdlib.h>
#include "LonelyPartyArray.h"

LonelyPartyArray *createLonelyPartyArray(int num_fragments, int fragment_length);
LonelyPartyArray *destroyLonelyPartyArray(LonelyPartyArray *party);
int set(LonelyPartyArray *party, int index, int key);
int get(LonelyPartyArray *party, int index);
int delete(LonelyPartyArray *party, int index);
int containsKey(LonelyPartyArray *party, int key);
int isSet(LonelyPartyArray *party, int index);
int printIfValid(LonelyPartyArray *party, int index);
LonelyPartyArray *resetLonelyPartyArray(LonelyPartyArray *party);
int getSize(LonelyPartyArray *party);
int getCapacity(LonelyPartyArray *party);
int getAllocatedCellCount(LonelyPartyArray *party);
long long unsigned int getArraySizeInBytes(LonelyPartyArray *party);
long long unsigned int getCurrentSizeInBytes(LonelyPartyArray *party);
double difficultyRating(void);
double hoursSpent(void);
LonelyPartyArray *cloneLonelyPartyArray(LonelyPartyArray *party);

LonelyPartyArray *createLonelyPartyArray(int num_fragments, int fragment_length)
{
	// checks if parameters are less than 0. If so, return NULL
	if (num_fragments <= 0 || fragment_length <= 0)
		return NULL;

	// makes new dinamically allocated struct
	LonelyPartyArray *newArray = malloc(sizeof(LonelyPartyArray));

	// checks if malloc failed for previous assignment 
	if(newArray == NULL)
	{
		free(newArray);
		
		return NULL;
	}

	// assign num_active_fragments
	newArray ->  num_active_fragments = 0;

	// assign size
	newArray ->  size = 0;

	// sets struct fields to passed variables
	newArray ->  num_fragments = num_fragments;
	newArray -> fragment_length = fragment_length;
		
	// allocates memory for fragment 2D array
	newArray -> fragments = malloc(sizeof(int*) * num_fragments);

	if (newArray -> fragments == NULL)
	{
		free(newArray -> fragments);
		return NULL;
	}

	// allocates memory for fragment sizes array
	newArray -> fragment_sizes = malloc(num_fragments * sizeof(int));

	if (newArray -> fragment_sizes == NULL)
	{
		free(newArray -> fragment_sizes);
		return NULL;
	}

	// initialize fragments
	for (int i = 0; i < num_fragments; i++)
	{
		// initializes array of fragment arrays 
		newArray -> fragments[i] = NULL;
			
		newArray -> fragment_sizes[i] = 0;
	}

	printf("-> A new LonelyPartyArray has emerged from the void. (capacity: %d, fragments: %d)\n", num_fragments * fragment_length, num_fragments);

	return newArray;
}

LonelyPartyArray *destroyLonelyPartyArray(LonelyPartyArray *party)
{
	// checks if party is null
	if (party!= NULL)
	{
		// frees each location in fragments
		for (int i = 0; i < party -> num_fragments; i++)
			if (party -> fragments[i] != NULL)
			{
				free(party -> fragments[i]);
				party -> fragments[i] = NULL;
			}

		// frees fragment sizes
		if(party -> fragment_sizes != NULL)
		{
			free(party -> fragment_sizes);
			party -> fragment_sizes = NULL;
		}

		// frees fragments
		if(party -> fragments != NULL)
		{
			free(party -> fragments);
			party -> fragments = NULL;
		}

		//frees party
		free(party);
		party = NULL;

		// prints that the struct has been "destroyed"
		printf("-> The LonelyPartyArray has returned to the void.\n");
	}

	return NULL;
}

int set(LonelyPartyArray *party, int index, int key)
{	

	// checks if pary is a NULL pointer
	if (party == NULL)
	{
		// prints that a NULL pointer was detected
		printf("-> Bloop! NULL pointer detected in set().\n");

		return LPA_FAILURE;
	}
	else if (index < 0 || index >= party -> num_fragments * party -> fragment_length)
	{
		// prints that it was an invalid index
		printf("-> Bloop! Invalid access in set(). (index: %d, fragment: %d, offset: %d)\n", index, index/party -> fragment_length, index%party -> fragment_length);

		return LPA_FAILURE;
	}

	// checks if this fragment was initialized 
	if (party -> fragments[index/party -> fragment_length] == NULL)
	{	
		// increases num_active_fragments count
		party -> num_active_fragments++;

		// allocate space for fragment
		party -> fragments[index/party -> fragment_length] = malloc(sizeof(int)*party -> fragment_length);

		//prints that a new fragment was spawned
		printf("-> Spawned fragment %d. (capacity: %d, indices: %d..%d)\n", index/party -> fragment_length, party -> fragment_length, index - index%party -> fragment_length, index - index%party -> fragment_length + party -> fragment_length-1);

		if (party -> fragments[index/party -> fragment_length] == NULL)
			return 0;

		// sets each cell in this fragment to UNUSED
		for (int i = 0; i < party -> fragment_length; i++)
		{
			party -> fragments[index/party -> fragment_length][i] = UNUSED;
		}
	}

	// checks if the fragment was previously assigned 
	if (party -> fragments[index/party -> fragment_length][index%party -> fragment_length] == UNUSED)
	{
		party -> size++;
		party -> fragment_sizes[index/party -> fragment_length]++;
	}

	// sets value of index as key
	party -> fragments[index/party -> fragment_length][index%party -> fragment_length] = key;

	return LPA_SUCCESS;
}

int get(LonelyPartyArray *party, int index)
{
	// checks if party is NULL
	if (party == NULL)
	{
		// prints thsat a NULL pointer was detected
		printf("-> Bloop! NULL pointer detected in get().\n");

		return LPA_FAILURE;
	}

	// checks if index is in bounds
	if (index < 0 || index >= party -> num_fragments * party -> fragment_length)
	{
		// prints that it was an invalid index 
		printf("-> Bloop! Invalid access in get(). (index: %d, fragment: %d, offset: %d)\n", index, index/party -> fragment_length, index%party -> fragment_length);

		return LPA_FAILURE;
	}

	// checks if that location is not allocated 
	if (party -> fragments[index/party -> fragment_length] == NULL)
		return UNUSED;

	// returns whatever is in the given index
	return(party -> fragments[index/party -> fragment_length][index%party -> fragment_length]);
}

int delete(LonelyPartyArray *party, int index)
{
	// checks if NULL
	if (party == NULL)
	{
		//prints that pointer was NULL
		printf("-> Bloop! NULL pointer detected in delete().\n");

		return LPA_FAILURE;
	}

	// checks if index is in range
	if (index < 0 || index >= party -> num_fragments * party -> fragment_length)
	{
		// prints that it was an invalid index 
		printf("-> Bloop! Invalid access in delete(). (index: %d, fragment: %d, offset: %d)\n", index, index/party -> fragment_length, index%party -> fragment_length);

		return LPA_FAILURE;
	}

	// checks if index was already set to unused or if not allocated
	if (party -> fragments[index/party -> fragment_length] == NULL || party -> fragments[index/party -> fragment_length][index%party -> fragment_length] == UNUSED){
		return LPA_FAILURE;
	}

	// sets index to UNUSED
	party -> fragments[index/party -> fragment_length][index%party -> fragment_length] = UNUSED;

	

	//decreases fragment size count
	party -> fragment_sizes[index/party -> fragment_length]--;

	// decreases size count
	party -> size--;

	// checks if num_active_fragments should be decreased
	if (party -> fragment_sizes[index/party -> fragment_length] == 0)
	{
		//decreases num_active_fragments by one 
		party -> num_active_fragments--;

		// prints that the fragment was deallocated 
		printf("-> Deallocated fragment %d. (capacity: %d, indices: %d..%d)\n", index/party -> fragment_length, party -> fragment_length, index - index%party -> fragment_length, index - index%party -> fragment_length + party -> fragment_length-1);

		//deallocates memory assignet to that fragment 
		free(party -> fragments[index/party -> fragment_length]);
		party -> fragments[index/party -> fragment_length] = NULL;
	}

	return LPA_SUCCESS;

}

int containsKey(LonelyPartyArray *party, int key)
{
	// checks if NULL, if so return 0 
	if (party == NULL)
		return 0;

	// looks for key
	for (int i = 0; i < party -> num_fragments; i++)
	{
		for (int j = 0; j < party -> fragment_length; j++)
		{
			// fragments[i] is not NULL and the key is found return 1
			if (party -> fragments[i] != NULL && party -> fragments[i][j] == key)
				return 1;
		}
	}

	return 0;
}

int isSet(LonelyPartyArray *party, int index)
{
	// checks if party is NULL, if so returns 0
	if (party == NULL)
		return 0;

	// checks if fragment was allocated and it isn't UNUSED
	if (party -> fragments[index/party -> fragment_length] != NULL && party -> fragments[index/party -> fragment_length][index%party -> fragment_length] != UNUSED)
		return 1;

	return 0;
}

int printIfValid(LonelyPartyArray *party, int index)
{
	if (party == NULL || party -> fragments[index/party -> fragment_length] == NULL || index < 0 || index >= party -> num_fragments * party -> fragment_length || party -> fragments[index/party -> fragment_length][index%party -> fragment_length] == UNUSED)
		return LPA_FAILURE;

	printf("%d\n", party -> fragments[index/party -> fragment_length][index%party -> fragment_length]);

	return LPA_SUCCESS;
}

LonelyPartyArray *resetLonelyPartyArray(LonelyPartyArray *party)
{
	//checks if party is NULL
	if (party == NULL)
	{
		printf("-> Bloop! NULL pointer detected in resetLonelyPartyArray().\n");
		return party;
	}

	for (int i = 0; i < party -> num_fragments; i++)
	{
		// empties everything in fragments and checks for NULL
		if (party -> fragments[i] != NULL)
			for(int j = 0; j < party -> fragment_length; j++)
				party -> fragments[i][j] = UNUSED;

		// frees all the fragments that were used if not already NULL
		if (party -> fragments[i] != NULL)
		{
			free(party -> fragments[i]);
			party -> fragments[i] = NULL;
		}

		// sets all fragment_sizes to 0
		party -> fragment_sizes[i] = 0;
	}

	// sets everything back to 0
	party -> size = 0;
	party -> num_active_fragments = 0;

	// nascent
	printf("-> The LonelyPartyArray has returned to its nascent state. (capacity: %d, fragments: %d)\n", party -> num_fragments * party -> fragment_length, party -> num_fragments);

	return party;
}

int getSize(LonelyPartyArray *party)
{
	//checks if party is NULL 
	if (party == NULL)
		return -1;

	//returns the size of party 
	return party -> size;
}

int getCapacity(LonelyPartyArray *party)
{
	// checks for NULL
	if (party == NULL)
		return -1;

	// returns max capacity of party 
	return(party -> num_fragments * party -> fragment_length);

}

int getAllocatedCellCount(LonelyPartyArray *party)
{
	// checks if party is NULL
	if (party == NULL)
		return -1;

	// initializes count to 0
	int count = 0;

	// goes through fragments to see if they're NULL
	for (int i = 0; i < party -> num_fragments; i++)
	{
		if (party -> fragments[i] != NULL)
			count += party -> fragment_length;
	}

	return count;
}

long long unsigned int getArraySizeInBytes(LonelyPartyArray *party)
{
	// check for NULL
	if (party == NULL)
		return 0;

	// returns amount of bytes it would take in a regular array
	return (long long unsigned int)(party -> num_fragments * party -> fragment_length) * (sizeof(int));
}

long long unsigned int getCurrentSizeInBytes(LonelyPartyArray *party)
{
	// checks for NULL
	if (party == NULL)
		return 0;

	long long unsigned int sizeCount = 0;

	sizeCount += (long long unsigned int)sizeof(NULL) * (party -> num_fragments - party -> num_active_fragments);
	sizeCount += (long long unsigned int)sizeof(int*) * (party -> num_active_fragments);
	sizeCount += (long long unsigned int)sizeof(int) * party -> num_fragments;
	sizeCount += (long long unsigned int)sizeof(int) * party -> fragment_length * party -> num_active_fragments;
	sizeCount += sizeof(LPA) + sizeof(LPA*);

	return sizeCount;
}

double difficultyRating(void)
{
	return 2.3;
}

double hoursSpent(void)
{
	return 11.0;
}

LonelyPartyArray *cloneLonelyPartyArray(LonelyPartyArray *party)
{
	//makes new dinamically allocated struct
	LonelyPartyArray *newArray = malloc(sizeof(LonelyPartyArray));

	//checks if malloc failed for previous assignment 
	if (newArray == NULL)
	{
		free(newArray);
		
		return NULL;
	}

	// assign num_active_fragments
	newArray ->  num_active_fragments = party -> num_active_fragments;

	// assign size
	newArray -> size = party -> size;

	// sets struct fields to party fields
	newArray ->  num_fragments = party -> num_fragments;
	newArray -> fragment_length = party -> fragment_length;
		
	// allocates memory for fragment 2D array
	newArray -> fragments = malloc(sizeof(int*) * newArray -> num_fragments);

	// allocates memory for fragment sizes array
	newArray -> fragment_sizes = malloc(newArray -> num_fragments * sizeof(int));

	if (newArray -> fragments == NULL || newArray -> fragment_sizes == NULL)
	{
		free(newArray -> fragments);
		free(newArray -> fragment_sizes);

		return NULL;
	}

	// initialize fragments
	for (int i = 0; i < newArray -> num_fragments; i++)
	{
		if (party -> fragments[i] != NULL)
		{
		// initializes array of fragment arrays 
		newArray -> fragments[i] =  malloc(sizeof(int)*newArray -> fragment_length);
		
		//copies each element in fragments[i] from the passed LonelyPartyArray
		for (int j = 0; j < newArray -> fragment_length; j++)
			newArray -> fragments[i][j] = party -> fragments[i][j];

		newArray -> fragment_sizes[i] = party -> fragment_sizes[i];
		}
	}

	printf("-> Successfully cloned the LonelyPartyArray. (capacity: %d, fragments: %d)\n", newArray -> num_fragments * newArray -> fragment_length, newArray -> num_fragments);

	return newArray;
}






