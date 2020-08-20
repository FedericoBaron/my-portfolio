Notes: Trees

Trees consist of nodes (which contain values) connected by edges
The hierachical ordering of our diagram conveys parent-child relationships
A node can have many children, but only one parent

Trees cannot contain cycles (loops)
There can only be one path from each node to every other node on the tree

n nodes
n-1 edges

Definitions:
a collection of trees is called a forest
a node with no parent is called the root of the tree
a node with no parent is called a leaf
a binary tree is a tree in which every node has 0, 1, or 2 children

a binary tree is full if every node in the tree has 0 or 2 children

a binary tree is complete if all levels of the tree are completely filled up, except 
perhaps for the bottom level, which must be filled from the left side to the right with 
no gaps between nodes, but possibly some empty spaces on the right side of that bottom most level

a perfect binary tree is one in which all non leaf nodes have two children, and all
leaf nodes are on the same level within the tree

h = floor(log base2 (n))

Deletion:
- go to the left subtree and pick the biggest element

------------------------------------
Runtimes for BST 
------------------------------------
type        best     worse   avg 
insetion    O(1)     O(n)    O(logn)
search      O(1)     O(n)    O(logn)
deletion    O(1)     O(n)    O(logn)
