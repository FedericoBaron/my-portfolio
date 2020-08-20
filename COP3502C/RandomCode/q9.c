#include <stdio.h>
#include <stdlib.h>
#include <time.h>

node *create_node(int data);

typedef struct node
{
	int data;
	struct node *next;

} node;

node *create_node(int data)
{
	node *a = malloc(sizeof(node));
	a -> data = data;
	a -> node = NULL;

	return a;

}

node *tail_insert(node *head, int data)
{
	node *tail;

	if(head == NULL)
		return create_node(data);

	tail = head;
	while(tail -> next != NULL)
		tail = tail -> next;
	tail -> next = create_node(data);
	return head;
}
int main()
{

}
