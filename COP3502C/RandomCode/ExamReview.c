// Exam Review

// Write a function that takes the root of a BT and returns  
// the sum of all values in that tree
int tree_sum(node *root)
{
    if (root == NULL)
        return 0;

    return root->data + tree_sum(root->left) + tree_sum(root->right);
}

int tree_sum(node *root)
{
    node *cur;

    int sum = 0;
    Stack *s = createMagicalStack();

    push(s, root);

    while (!s.isEmpty())
    { vcx
        cur = pop(s);

        if(cur != NULL)
        {
            sum += cur->data;

            push(s, cur->right);
            push(s, cur->left);
        }
    }

    poof(s);

    return sum;
}

// returns 1 if key is in BST
int bst_search(node *root, int key)
{   
    node *tmp = root;

    while (temp != NULL)
    {
        if(key < temp->data)
            temp = temp->left;
        else if(key > temp->data)
            temp = temp->right;
        else
            return 1;
    }

    return 0;
}

int rec_bst_search(node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return rec_bst_search(root->left, key);
    else if (key > root->data)
        return rec_bst_search(root->right. key);

    return 1;
}

// O(n)
int rec rec_binary_tree_search(node *root, int key)
{
    if (root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    return rec_binary_tree_search(root->left, key) || rec_binary_tree_search(root->right, key);
}







