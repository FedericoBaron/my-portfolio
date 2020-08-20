// Sean Szumlanski
// COP 3502, Spring 2019

// bst.c
// =====
// Recursive BST functions. Includes insertion, deletion, traversal algorithms,
// and the forest_fire() functions.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
	int data;
	struct node *left, *right;
} node;

node *create_node(int data)
{
	// calloc() initializes the 'left' and 'right' pointers to NULL for us.
	node *n = calloc(1, sizeof(node));
	n->data = data;
	return n;
}

// Recursive BST insertion.
node *BST_insert(node *root, int data)
{
	if (root == NULL)
		return create_node(data);

	if (data < root->data)
	{
		// Left subtree insertion.
		root->left = BST_insert(root->left, data);
	}
	else if (data > root->data)
	{
		// Right subtree insertion.
		root->right = BST_insert(root->right, data);
	}
	else
	{
		// This empty statement is super cheeky. It's my way of pointing out
		// explicitly that I'm not inserting duplicate values into this BST.
		;
	}

	return root;
}

// Finds the max value in a BST. Assumes root is non-null. (Recursive version.)
int find_max_recursive(node *root)
{
	if (root->right == NULL)
		return root->data;
	else
		return find_max_recursive(root->right);
}

// Finds the max value in a BST. Assumes root is non-null. (Iterative version.)
int find_max(node *root)
{
	while (root->right != NULL)
		root = root->right;

	return root->data;
}

// Delete 'data' from a BST.
node *BST_delete(node *root, int data)
{
	node *temp;

	// Clearly, if the tree is empty, the deletion is a no-op.
	if (root == NULL)
	{
		return NULL;
	}
	else if (data < root->data)
	{
		root->left = BST_delete(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = BST_delete(root->right, data);
	}
	else
	{
		// Hooray, we've found the data to be deleted!

		if (root->left == NULL && root->right == NULL)
		{
			// If it has no children, just quietly get rid of it. ;)
			free(root);
			root = NULL;
		}
		else if (root->right == NULL)
		{
			// If we reach this case, there is exactly one child (the left child).
			// It moves up to take its parent's place.
			temp = root->left;
			free(root);
			root = temp;
		}
		else if (root->left == NULL)
		{
			// If we reach this case, there is exactly one child (the right child).
			// So, the right child moves up to take its parent's place.
			temp = root->right;
			free(root);
			root = temp;
		}
		else
		{
			// This is the case where the node to be deleted has two children. We
			// find the max value in the left subtree (as is our policy in this
			// class this semester) and move it up to this node. Then we delete
			// that value from the left subtree recursively.
			root->data = find_max(root->left);
			root->left = BST_delete(root->left, root->data);
		}
	}

	return root;
}

// Traversal Functions

void inorder_recursive(node *root)
{
	if (root == NULL)
		return;

	inorder_recursive(root->left);
	printf("%d ", root->data);
	inorder_recursive(root->right);
}

void preorder_recursive(node *root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	preorder_recursive(root->left);
	preorder_recursive(root->right);
}

void postorder_recursive(node *root)
{
	if (root == NULL)
		return;

	postorder_recursive(root->left);
	postorder_recursive(root->right);
	printf("%d ", root->data);
}

// Traversal function helpers. These ensure that we get a '\n' after the output
// of a traversal, and they also pretty up the output in other ways.

void inorder(node *root)
{
	printf("Inorder Traversal:\n");

	if (root == NULL)
	{
		printf("(empty tree)\n");
		return;
	}

	inorder_recursive(root);
	printf("\n");
}

void preorder(node *root)
{
	printf("Preorder Traversal:\n");

	if (root == NULL)
	{
		printf("(empty tree)\n");
		return;
	}

	preorder_recursive(root);
	printf("\n");
}

void postorder(node *root)
{
	printf("Postorder Traversal:\n");

	if (root == NULL)
	{
		printf("(empty tree)\n");
		return;
	}

	postorder_recursive(root);
	printf("\n");
}

// Free up all dynamically allocated memory associated with a binary tree.
node *forest_fire(node *root)
{
	if (root == NULL)
		return NULL;

	forest_fire(root->left);
	forest_fire(root->right);

	free(root);

	return NULL;
}

// NOTE: This is the bad version of forest_fire() that doesn't work. I
//       frequently see people trying to use a nested loop approach like this
//       when asked to write a function to traverse all the nodes in a binary
//       tree. It just doesn't work.
node *fake_forest_fire(node *root)
{
	node *top_of_branch = root;
	node *some_other_node, *so_many_nodes, *yet_another_node;

	while (top_of_branch != NULL)
	{
		some_other_node = top_of_branch;
		so_many_nodes = top_of_branch->right;

		while (some_other_node != NULL)
		{
			yet_another_node = some_other_node->left;
			free(some_other_node);
			some_other_node = yet_another_node;
		}

		top_of_branch = so_many_nodes;
	}
}

int main(void)
{
	//         40
	//        /  \
	//      18    89
	//           /  \
	//         82    101
	//          \     /
	//          84  100

	// We started out by constructing this BST manually, like so:

	/*
	node *root = create_node(40);
	root->left = create_node(18);
	root->right = create_node(89);
	root->right->left = create_node(82);
	root->right->right = create_node(101);
	root->right->left->right = create_node(84);
	root->right->right->left = create_node(100);
	*/

	int i, r, n = 5;
	node *root = NULL;

	srand(time(NULL));

	// Construct a BST with n randomly chosen values.
	for (i = 0; i < n; i++)
	{
		printf("Inserting %d...\n", r = rand() % 100 + 1);
		root = BST_insert(root, r);
	}

	// Examine tree structure. You should verify the accuracy of these traversals
	// by hand.
	printf("\n");
	inorder(root);
	preorder(root);
	postorder(root);

	printf("\nWhat value shall we delete? ");
	scanf("%d", &r);

	root = BST_delete(root, r);

	// Examine tree structure again.
	printf("\n");
	inorder(root);
	preorder(root);
	postorder(root);

	// Clean up after yourself.
	root = forest_fire(root);

	return 0;
}
