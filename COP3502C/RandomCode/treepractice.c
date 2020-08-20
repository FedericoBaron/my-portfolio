//binary trees recursive solution on the exam

#include<stdio.h>

int main(void)
{

	return 0;
}


// write a function that takes the root of a 
//binary tree and returns the sum of all values in that tree.
int tree_sum(node *root)
{
	if(root == NULL)
		return 0;

	return root + tree_sum(root -> left) + tree_sum(root -> right);

}

int tree_itersum(node *root)
{
	int sum = 0;

	//stack
	Stack *s = createMagicalStack();

	node *current;

	push(s, root)
	while(!isEmpty(s))
	{
		current = pop(s);

		if(current != NULL)
		{
			sum += current -> data;
			push(s, current -> right);
			push(s, current -> left);
		}
	}

	poof(s);
	return sum;
}

int bst_search(node *root, int key)
{
	node *temp = root;

	while(temp != NULL)
	{
		if(key < temp -> data)
			temp = temp -> left;
		else if(key > temp -> data)
			temp = temp -> right;
		else 
			return 1;
	}
	return 0;
}

int recursive_bst_search(node *root, int key)
{
	if(root == NULL)
		return 0;
	if(root -> data == key)
		return 1;
	if(key < root -> data)
		return recursive_bst_search(root -> left, key);
	else if(key > root -> data)
		return recursive_bst_search(root -> right, key);
	else
		return 1;

	return 0;
}