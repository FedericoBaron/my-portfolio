//linked lists

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *next;
	int data;
} node;

node create_node(int data)
{
	node *n = malloc(sizeof(node));

	n -> data = data;
	n -> next = NULL;
}

int main(void)
{
	node *head = NULL;

	head = create_node(40);
	head -> next = create_node(60);
	head -> next -> next = create_node(70);

	head = malloc(sizeof(node));
	head -> data = 58;
	head -> next = NULL;

	head -> next = malloc(sizeof(node));
	head -> next -> data = 54;
	head -> next -> next = NULL;

	head -> next -> next = malloc(sizeof(node));
	head -> next -> next -> data = 38;

	head -> next -> next -> next = NULL;

	return 0;

}
