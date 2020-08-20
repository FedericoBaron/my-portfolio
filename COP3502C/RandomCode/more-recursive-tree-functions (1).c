// Sean Szumlanski
// COP 3502, Spring 2019

// more-recursive-tree-functions.c
// ===============================
// A variety of solutions to the binary tree coding exercises we covered in class.


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// basic binary tree node
typedef struct node
{
	int data;
	struct node *left, *right;
} node;


// Helper function. Returns max of two integers. Used by various functions in this
// source file.
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Returns the number of nodes in a (possibly empty) binary tree.
int count_nodes(node *root)
{
	if (root == NULL)
		return 0;

	return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Another approach to count_nodes. This is a gross one-liner. Please don't
// write stuff like this. Write code that is easier to read. I'm including this
// just so you're exposed to the fact that this function can be written this
// way.
int count_nodes_condensed(node *root)
{
	return (root == NULL) ? 0 : 1 + count_nodes_condensed(root->left) + count_nodes_condensed(root->right);
}

// Recursive function to count all the even values in a binary tree.
int count_even_values(node *root)
{
	if (root == NULL)
		return 0;

	return (root->data % 2 == 0) + count_even_values(root->left) + count_even_values(root->right);
}

// Returns the height of a (possibly empty) binary tree.
int height(node *root)
{
	if (root == NULL)
		return -1;

	return 1 + max(height(root->left), height(root->right));
}

// A recursive function that returns the largest value in a binary tree. Note
// that the tree is not necessarily a BST. Note also that the tree may contain
// negative integers.
int find_max(node *root)
{
	int m;

	// If empty, return some sort of flag / dummy variable.
	if (root == NULL)
		return INT_MIN;

	// Otherwise, capture the max value from the left subtree and the max value
	// from the right subtree.
	m = max(find_max(root->left), find_max(root->right));

	// Return whichever is bigger: root->data or the max value from its subtrees.
	return max(root->data, m);
}

// A slightly more compact version of find_max(). Returns max value in a binary
// tree.
int find_max_alternative(node *root)
{
	// If empty, return some sort of flag / dummy variable.
	if (root == NULL)
		return INT_MIN;

	// Otherwise, return whichever is the greatest of the three:
	return max(root->data, max(find_max_alternative(root->left),
	                           find_max_alternative(root->right)));
}

// A recursive function to find the largest value in a BST.
int bst_find_max(node *root)
{
	if (root == NULL)
		return INT_MIN;

	// If this node does not have a right child, then none of its subtrees can
	// contain a larger value than root->data.
	if (root->right == NULL)
		return root->data;

	// Otherwise, if this node has a right child, then there's necessarily a
	// greater value in the BST. We search for it recursively.
	return bst_find_max(root->right);
}

// An iterative function to find the largest value in a BST.
int bst_find_max_iterative(node *root)
{
	node *temp = root;

	if (root == NULL)
		return INT_MIN;

	while (temp->right != NULL)
		temp = temp->right;

	return temp->data;
}
