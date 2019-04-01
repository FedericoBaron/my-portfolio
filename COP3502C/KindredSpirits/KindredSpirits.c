// Federico Baron COP3502 Spring 2019
// NID: fe960661

#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"

// linked list functions taken from Szumlanski's page

// This creates a node for LinkedList
typedef struct node2
{
	int data;
	struct node2 *next;
} node2;

// This struct creates a linked list with a tail pointer and a head pointer
typedef struct LinkedList
{
	// head pointer 
	node2 *head;

	// tail pointer
	node2 *tail;

} LinkedList;


// function skeletons for the entire program 
node *create_nodes(int data);
void preorder_recursive(node *root, LinkedList *list);
void postorder_recursive(node *root, LinkedList *list);
int count_nodes(node *root);
node2 *create_node2(int data);
LinkedList *create_list(void);
node2 *recursive_destroyer(node2 *head);
LinkedList *destroy_list(LinkedList *list);
void tail_insert(LinkedList *list, int data);

// function to create a node. It is passed data (an integer) and it 
// returns a pointer to the node
node2 *create_node2(int data)
{

	// allocates memory for a node to contain data
	node2 *n = malloc(sizeof(node));

	// sets n to contain data passed when the function was called 
	n->data = data;

	// sets next pointer to be NULL
	n->next = NULL;

	// returns a pointer to the node that was just created
	return n;
}

// creates a linked list 
LinkedList *create_list(void)
{
	// allocates memory for a linked list with a head and tail pointer 
	return calloc(1, sizeof(LinkedList));
}

node2 *recursive_destroyer(node2 *head)
{
	// checks if head is NULL which means there is nothing to destroy 
	if (head == NULL)
		return NULL;

	// calls recursively using head -> next
	recursive_destroyer(head->next);

	// frees the memory allocated for head
	free(head);

	return NULL;
}

// destroys the linked list 
LinkedList *destroy_list(LinkedList *list)
{
	// if the list is NULL there is nothing to destroy
	if (list == NULL)
		return NULL;

	// calls to free every node in list
	recursive_destroyer(list->head);

	// free memory allocated to the list itself
	free(list);

	// returns NULL
	return NULL;
}

// inserts a node at the tail of list
void tail_insert(LinkedList *list, int data)
{
	// if list is NULL then there is nothing that can be inserted
	if (list == NULL)
		return;
	
	// if the tail is NULL it means the head is the tail as well
	if (list->tail == NULL)
	{
		// assigns head and tail to be the new node 
		list->head = list->tail = create_node2(data);

		// return statement to break out of function
		return;
	}

	// if tail is not NULL and list is not NULL, then just insert to tail
	list->tail->next = create_node2(data);

	// sets tail to be tail -> next which is the node we just created
	list->tail = list->tail->next;
}

// chekcs if trees a and b are reflections of each other 
int isReflection(node *a, node *b)
{

	// if both are NULL then it might be a reflection 
	if (a == NULL && b == NULL)
		return 1;

	// if one is NULL and the other isn't then it definitely isn't a reflection
	if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
		return 0;

	// if the data ins't equal then it definitely isn't a refelction 
	if (a -> data != b -> data)
		return 0;

	// calls itself recursively 
	else
		// checks if 0 is ever returned and if so it returns 0 which means it is not a reflection
		return(isReflection(a -> right, b -> left) && isReflection(a -> left, b -> right));
}

// makes a tree that reflects the passed tree 
node *makeReflection(node *root)
{
	// if the root is NULL then the tree is empty or the recursion is finished
	if (root == NULL)
		return NULL;

	// creates a new node containing data, at a reflection point
	node *newRoot = create_nodes(root -> data);

	// goes to the left for the right node of the tree
	newRoot -> right = makeReflection(root -> left);

	// goes to the right for the left node of the tree
	newRoot -> left = makeReflection(root -> right);

	// returns a pointer to the new root 
	return newRoot;
}

node *create_nodes(int data)
{
	// dynamically allocates a node 
	node *n = malloc(sizeof(node));

	// sets data to be the integer that is passed 
	n->data = data;

	// sets the right and left nodes of the tree to be NULL
	n->left = n->right = NULL;

	// returns a pointer to the node that was created
	return n;
}

// checks if trees a and b are kindred spirits of eachother
// this means the preorder of one of them is the postorder of the other 
int kindredSpirits(node *a, node *b)
{

	// sets all the variables
	int n, n2, i, aE = 1, bE = 1;

	// if both are NULL they are kindred spirits!
	if (a == NULL && b == NULL)
		return 1;

	// n is the amount of nodes in tree a
	n = count_nodes(a);

	// n2 is the amount of nodes in tree b
	n2 = count_nodes(b);

	// if n is not equal to n2 then a and b are definitely not kindred spirits
	if (n != n2)
		return 0;

	// creates linked lists for postorder and preorder for trees a and b
	LinkedList *aPre = create_list();
	LinkedList *bPre = create_list();
	LinkedList *aPost = create_list();
	LinkedList *bPost = create_list();


	// calls preorder for both a and b and saves them in linked lists
	preorder_recursive(a, aPre);
	preorder_recursive(b, bPre);

	// calls postorder for both a and b and saves them in linked lists
	postorder_recursive(a, aPost);
	postorder_recursive(b, bPost);

	// goes through the lists to check if post and pre are equal
	for (i = 0; i < n; i++)
	{

		// if not equal aE is set to 0 meaning this doesn't work
		if (aPre -> head -> data != bPost -> head -> data)
			aE = 0;


		// if not equal bE is set to 0 meaning this doesn't work
		if (bPre -> head -> data != aPost -> head -> data)
			bE = 0;

		// sets all of them to the next node to compare the following node
		aPre -> head = aPre -> head -> next;
		bPre -> head = bPre -> head -> next;
		aPost -> head = aPost -> head -> next;
		bPost -> head = bPost -> head -> next;

	}

	// frees all the memory associated with all the linked lists
	destroy_list(aPre);
	destroy_list(bPre);
	destroy_list(aPost);
	destroy_list(bPost);

	// if either one of them is 1 it means a and b are kindred 
	// spirits so 1 is returned
	return(aE == 1 || bE == 1);
}

// counts the number of nodes in a tree recursively 
// code taken from Szumlanski's website 
int count_nodes(node *root)
{
	// checks if root is NULL which means we just return 0
	if (root == NULL)
		return 0;

	// adds 1 if the root is not NULL because it means that there is a node.
	// then proceeds to continue transversing the tree
	return 1 + count_nodes(root->left) + count_nodes(root->right);
}


// recursive function for preorder
// code taken from szumlanski's website
void preorder_recursive(node *root, LinkedList *list)
{
	// checks if root is NULL
	if (root == NULL)
		return;

	// if root is not NULL then tail insert 
	tail_insert(list, root -> data);

	// call recursively first left and then right to do preorder
	preorder_recursive(root->left, list);
	preorder_recursive(root->right, list);
}

void postorder_recursive(node *root, LinkedList *list)
{

	// check if root is NULL
	if (root == NULL)
		return;

	// if root is not NULL keep traversing the tree postorder
	// first left then right 
	postorder_recursive(root->left, list);
	postorder_recursive(root->right, list);

	// add to tail afterwards since it is post order
	tail_insert(list, root -> data);
}


// returns the difficulty of the assignment
double difficultyRating(void)
{
	return 2.0;
}

// returns how many hours were spent
double hoursSpent(void)
{
	return 3.0;
}