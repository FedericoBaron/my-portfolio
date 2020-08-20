// Stack - an abstract data type

/* 

operations
-----------
insert: push O(1)
delete: pop  O(1)
isFull
isEmpty
peek

arrays to implement stacks

+------+------+------+------+
|      |      |      |      |
+------+------+------+------+

capacity: 4
size: 0

push 44
+------+------+------+------+
|  44  |      |      |      |
+------+------+------+------+

capacity: 4
size: 1

push 22
+------+------+------+------+
|  44  |  22  |      |      |
+------+------+------+------+

capacity: 4
size: 2

push 71
+------+------+------+------+
|  44  |  22  |  71  |      |
+------+------+------+------+

capacity: 4
size: 3

pop (@ size - 1)
+------+------+------+------+
|  44  |  22  |      |      |
+------+------+------+------+

capacity: 4
size: 2

push 54
+------+------+------+------+
|  44  |  22  |  54  |      |
+------+------+------+------+

capacity: 4
size: 3

push 60
+------+------+------+------+
|  44  |  22  |  54  |  60  |
+------+------+------+------+

capacity: 4
size: 4

*/

#include <stdio.h>
#include <stdlib.h>
#include <sting.h>
#include <limits.h>

#define EMPTY_STACK_ERR INT_MIN

typde def struct Stack 
{
	int* array;
	int capacity;
	int size;

} Stack;

Stack *createStack(int capacity)
{
	Stack *s = malloc(sizeof(Stack));

	if(s == NULL)
		return NULL;

	s->array = malloc(sizeof(int) * capacity);

	if(s->array == NULL){
		free(s);
		return NULL;
	}

	s->capacity = capacity;
	s->size = 0;

	return s;
}

Stack *destroyStack(Stack *s)
{
	if(s == NULL)
		return NULL;

	free(s->array);
	free(s);

	return NULL;
}

int isFull(Stack *s)
{
	return (s == NULL || s->capacity <= s->size);

}

int isEmpty(Stack *s)
{
	return (s == NULL || s->size <= 0);
}

int *pop(Stack *s, int n)
{
	if(isEmpty(s))
	{
		printf("Error: Stack is empty in pop()\n");
		return EMPTY_STACK_ERR;
	}

	return s->array[--s->size];
}

void *push(Stack *s, int n)
{
	if(isFull(s))
	{
		printf("Error: Stack is full in push()\n");
		return;
	}

	s->array[s->size++] = data;
}

int peek(Stack *s)
{

}

int main(void)
{
	

	return 0;

}