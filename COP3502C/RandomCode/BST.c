#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_MIN -1000000;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_node(int data)
{
    node *n = calloc(1, sizeof(node));
    n->data = data;
    return n;
}

// 55 17 23 88 60 57 89
void preorder(node *root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// 23 17 57 60 89 88 55
void postorder(node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

//17 23 55 57 60 88 55
void inorder(node *root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

node *forest_fire(node* root)
{
   if(root == NULL)
        return NULL;

    forest_fire(root->left);
    forest_fire(root->right);
    free(root);
}

node *bst_insert(node *root, int data)
{
    if(root == NULL)
        return create_node(data);

    if(data < root->data)
        root->left = bst_insert(root->left, data);
    else if(data > root->data)
        root->right = bst_insert(root->right, data);
    else
        ; // stops insertion of duplicates

    return root;
}

// assumes root is not NULL
int find_max(node *root)
{
    node *temp = root;

    while(temp->right != NULL)
        temp = temp->right;
    
    return temp->data;
}

// recursive version of find_max
int find_max_rec(node *root)
{
    if(root->right == NULL)
        return root->data;

    return find_max_rec(root->right);
}

node *bst_delete(node *root, int data)
{
    node *temp;

    if(root == NULL)
        return NULL;

    if(root->data == data)
    {
        root->left = bst_delete(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = bst_delete(root->right, data);
    }
    else
    {
        // the node has no children
        if(root->left == NULL && root->right ==  NULL)
        {
            free(root);
            return NULL;
        }
        // the node has one left child
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp->left;
        }
        // the node has one right
        else if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp->right;
        }
        // the node has two chilren
        else
        {
            root->data = find_max(root->left);
            root->left = bst_delete(root->left, root->data);
        }
    }

    return root;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// find max value in a binary tree
int find_max_tree(node *root)
{
    if(root == NULL)
        return INT_MIN;

    return max(root->data, max(find_max_tree(root->left), find_max_tree(root->right)));
}

int count_nodes(node *root)
{
    if(root == NULL)
        return 0;

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int count_even_nodes(node *root)
{
    if(root == NULL)
        return 0;

    if(root->data % 2 == 0)
        return 1 + count_nodes(root->left) + count_nodes(root->right);
    else
        return count_nodes(root->left) + count_nodes(root->right);
}

int height(node *root)
{
    int heightL, heightR;

    if(root == NULL)
        return -1;

    heightL = height(root->left);
    heightR = height(root->right);

    return (1 + max(heightR, heightL));
}

/*
            55
         /      \
        17      88
         \      / \
          23   60  89
         /     /
      19      57

*/

int main(void)
{
    int i, n = 7, r;
    srand(time(NULL));
    node *root = NULL;

    // root = create_node(55);
    // root->left = create_node(17);
    // root->left->right = create_node(23);
    // root->right = create_node(88);
    // root->right->left = create_node(60);
    // root->right->right = create_node(89);
    // root->right->left->left = create_node(57);

    root = bst_insert(root, 55);
    root = bst_insert(root, 17);
    root = bst_insert(root, 23);
    root = bst_insert(root, 88);
    root = bst_insert(root, 60);
    root = bst_insert(root, 89);
    root = bst_insert(root, 57);

    printf("%d\n", height(root));

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");

    return 0;
}