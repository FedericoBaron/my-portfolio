// Sean Szumlanski
// COP 3502, Spring 2019

// stacks.c
// ========
// Array-based implementation of stacks with menu-driven interface to create
// stacks, push, pop, peek, etc.

// Stacks are LIFO structures (last in, first out), and they support the
// following operations:
//
// push() - push element onto the top of the stack
// pop() - removes the top item from the stack and returns its value
// isEmpty() - returns true of the stack is empty, false otherwise
// isFull() - returns true if the stack is full, false otherwise
// top(), peek() - returns the value at the top of the stack without popping it


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_STACK_ERR INT_MIN

typedef struct Stack
{
	// THESE ARE THE ELEMENTS!!
	int *array;

	// How many elements are in the stack?
	int size;

	// How big is the array?
	int capacity;
} Stack;


// Creates a stack with an internal array of length 'capacity'.
Stack *createStack(int capacity)
{
	Stack *s = malloc(sizeof(Stack));
	if(s == NULL)
		return NULL;
	if((s -> array = malloc(capacity * sizeof(int))) == NULL)
	{
		free(s);
		return NULL;
	}


	s -> size = 0;
	s -> capacity = capacity;

	return s;
}

// Destroy stack; coded defensively to avoid segfaults.
Stack *destroyStack(Stack *s)
{
	if(s == NULL)
		return NULL;
	free(s);
	free(s -> array);
	return NULL;
}

// Return 1 if the stack is empty, 0 otherwise.
int isEmpty(Stack *s)
{
	if(s != NULL && s -> size > 0)
		return 0;
	return 1;

}

// Return 1 if the stack is full, 0 otherwise.
int isFull(Stack *s)
{
	return(s == NULL || s -> capacity == s -> size);
}

// Push a new element onto the top of the stack.
void push(Stack *s, int data)
{
	if(isFull(s))
		return;
	s -> array[s -> size] = data;
	s -> size++;
}

// Remove the top element from the stack and return its value.
int pop(Stack *s)
{
	if(isEmpty(s))
		return INT_MIN;
	return(s -> array[--s -> size]);
}

// Peek at, but do not remove, the top element on the stack.
int peek(Stack *s)
{
	if(isEmpty(s))
		return INT_MIN;
	return(s -> array[s -> size-1]);
}

// Fancy function to print the stack. Can you figure out how it's working?
void printStack(Stack *s)
{
	int i; char str[32];

	printf("\n");

	if (s == NULL)
	{
		printf("   (no stack)\n");
		return;
	}

	if (s->size == 0)
	{
		printf("   (stack is empty)\n");
		return;
	}

	for (i = s->size - 1; i >= 0; i--)
	{
		printf("   |  %-4d  |%s\n", s->array[i],
		       (i == s->size - 1) ? " <-- top" : "");
		printf("   +--------+\n");
	}
}

// Print list of commands for menu-driven interface.
void printMenu(void)
{
	printf("\n");
	printf("Stack ops:\n");
	printf("\n");
	printf("  new <n>    -- create a new stack with capacity set to <n>\n");
	printf("  destroy    -- completely destroy the current stack\n");
	printf("  push <n>   -- push <n> onto the stack\n");
	printf("  pop        -- pops the top element off the stack\n");
	printf("  peek       -- prints the stack's top element without removing it\n");
	printf("  empty      -- indicates whether the stack is empty\n");
	printf("  full       -- indicates whether the stack is full\n");
}

int main(void)
{
	char buffer[128]; int n;
	Stack *myStack = NULL;

	printMenu();
	printf("\n");

	// This loop is poorly commented, but hopefully it's fairly easy to follow.
	while (1)
	{
		printf("Enter a command ('?' for help, or 'exit' to quit).\n");
		printf("%% ");

		scanf("%s", buffer);

		if (strcmp(buffer, "?") == 0)
		{
			printMenu();
		}
		
		else if (strcmp(buffer, "new") == 0)
		{
			if (myStack != NULL)
				destroyStack(myStack);

			scanf("%d", &n);
			myStack = createStack(n);
		}

		else if (strcmp(buffer, "destroy") == 0)
		{
			if (myStack != NULL)
				myStack = destroyStack(myStack);
		}

		else if (strcmp(buffer, "push") == 0)
		{
			scanf("%d", &n);
			push(myStack, n);
		}

		else if (strcmp(buffer, "pop") == 0)
		{
			n = pop(myStack);

			if (n != EMPTY_STACK_ERR)
				printf("\n   -> popped %d\n", n);
		}

		else if (strcmp(buffer, "peek") == 0 || strcmp(buffer, "top") == 0)
		{
			n = peek(myStack);

			if (n != EMPTY_STACK_ERR)
				printf("\n   -> peek: %d\n", n);
		}

		else if (strcmp(buffer, "empty") == 0)
		{
			if (isEmpty(myStack))
				printf("\n   -> stack is empty\n");
			else
				printf("\n   -> stack is not empty\n");
		}

		else if (strcmp(buffer, "full") == 0)
		{
			if (isFull(myStack))
				printf("\n   -> stack is full\n");
			else
				printf("\n   -> stack is not full\n");
		}

		else if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		// Print the stack after each command.
		printStack(myStack);
		printf("\n");
	}

	// Clean up after yourself.
	destroyStack(myStack);

	return 0;
}
