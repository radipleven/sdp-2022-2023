# Binary Tree 

This repository provides the functionality of creating, manipulating and checking binary trees. It includes the following features:
* Creation of a weight-balanced binary ordered tree
* Check for balance of a binary tree
* Check for ordering of a binary tree
* Release memory of a binary tree
* Convert binary tree to a dynamic array
* Collect all elements of a given level in a binary tree

## Implementation Details
The binary tree is represented by a pointer to its root and the empty tree is represented by a pointer with value `nullptr`. 
The elements in the left subtree of a node are smaller than the node, and the elements in the right subtree are larger or equal to the node. 
The implementation uses template type `T` to allow the use of binary trees with elements of different data types.

The nodes in the binary tree are represented by objects of type `Node<T>` with the following properties:
* `data`: Data stored in the node
* `left`: Pointer to the left child of the node or `nullptr` if none
* `right`: Pointer to the right child of the node or `nullptr` if none

The functions are implemented as templates to allow usage with different data types. The memory for the nodes is allocated using new and freed using delete. If an error occurs during the tree construction, the function takes care of cleaning up the memory it has already allocated to prevent memory leaks. 
If the tree construction cannot complete successfully due to insufficient memory, 
the function throws an exception of type `std::bad_alloc`.

## Available Features
* `bool isBalanced(const Node<T>* rootptr)`: Checks if the binary tree with root rootptr is weight-balanced.
* `bool isBst(const Node<T>* rootptr)`: Checks whether the binary tree with root rootptr is a binary search tree.
* `void release(const Node<T>* rootptr)`: Releases the memory occupied by the binary tree with root rootptr.
* `Node<T>* toBalanced(std::vector<T> data)`: Constructs a weight-balanced binary ordered tree from the given data array and returns a pointer to its root.
* `std::vector<T> toVector(const Node<T>* rootptr)`: Converts the binary tree with root rootptr to a dynamic array in inorder traversal.
* `std::vector<T> level(const Node<T>* rootptr, int level)`: Returns all elements of the binary tree with root rootptr that are at level level in a dynamic array ordered from left to right.

## Building and Testing
To build the project:
```
mkdir build
cd build
cmake ..
cmake --build .
```
To run tests:
```
ctest
```
