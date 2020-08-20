Traversal Algorithms

- these allow us to visit each node in a binary tree in a certain order

in order traversal (LMR)
(1) traverse left subtree using inorder traversal
(2) visit the root node of the subtree for this partucular function call
(3) traverse the right subtree using in order traversal
2 4 13 17 22 27 29 50 80 82

pre order traversal (MLR)
(1) visit the root of this subtree
(2) traverse the left subtree using preorder traversal
(3) traverse the right subtree using the preorder traversal 
22 2 13 4 17 80 50 29 27 82

post order traversal (LRM)
(1) traverse the left subtree using post order traversal
(2) traverse the right subtree using post order traversal
(3) visit each root of the subtree
4 17 13 2 27 29 50 82 80 22

* BE CAREFUL OF BINARY TREE/BINARY SEARCH TREE * 
