#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *next;
	int data;
} node;

node* create_node(int n)
{
	node *a = malloc(sizeof(node));
	a -> data = n;
	a -> next = NULL;

	return a;
}

node *insert_node(node *head, int n)
{
	node *temp = head;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = create_node(n);

	return head;
}

void print_list(node *head)
{
	if(head == NULL)
	{
		printf("destroyed\n");
		return;
	}
	while(head != NULL)
	{
		printf("%d\n", head -> data);
		head = head -> next;
	}
}

void print_list_rec(node *head)
{
	if(head == NULL)
	{	
		return;
	}
	else
	{
		printf("%d\n", head -> data);
		print_list_rec(head -> next);
	}
}

int recursiveCount(node *head)
{
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		if(head -> data % 2 == 1)
			return (head -> data + recursiveCount(head -> next));
		else
			return (recursiveCount(head -> next));

	}
}

int recursiveCount2(node *head)
{
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		return (head -> data + recursiveCount2(head -> next));
	}
}

node *tail_insert(node *head, int data)
{
	if(head == NULL)
	{
		return head = create_node(data);
	}
	else
	{
		head -> next = tail_insert(head -> next, data); 
	}

	return head;
}

void print_reverse(node *head)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		return print_reverse(head -> next);
		printf("%d\n", head -> data);
	}
}

node *reverselinkedlist(node *head)
{
	if(head == NULL)
		return NULL;
	else
		return head = reverselinkedlist(head -> next);

}

node *destroyList(node *head)
{
	while(head != NULL)
	{
		node *temp = head;
		head = head -> next; 
		free(temp);
	}
	free(head);
	return NULL;
}

node *destroyListR(node *head)
{
	if(head == NULL)
	{
		return NULL;
	}
	destroyListR(head -> next);
	free(head);
	return NULL;
}

node *deleteNth(node *head, int n)
{
	for(int i = 0; i < n-1; i++)
	{
		head = head -> next;
	}

	free(head -> next);
	head -> next = head -> next -> next;

	return head;
}

node *deleteNthR(node *head, int n)
{
	if(n == 1)
	{
		free(head -> next);
		head -> next = head -> next -> next; 
		return head;
	}

	deleteNthR(head -> next, n-1);
	return head;
}

int main(void)
{
	node *a = create_node(4);
	insert_node(a, 5);
	insert_node(a, 6);
	insert_node(a, 7);
	tail_insert(a, 8);
	//deleteNthR(a,1);
	print_list_rec(a);
	print_reverse(a);
	//destroyListR(a);
	printf("%d\n", recursiveCount(a));
	printf("%d\n", recursiveCount2(a));
}