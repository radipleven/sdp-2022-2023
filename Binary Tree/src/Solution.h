#pragma once 

#include <vector>
#include <stack>

#include "Node.h"

template<typename T>
int getHeight(const Node<T>* rootptr) {
    // If the root is null, the height is 0
    if (!rootptr) return 0;

    int leftHeight = getHeight(rootptr->left);
    int rightHeight = getHeight(rootptr->right);

    // Return the maximum of the left and right subtree heights plus 1 for the current node
    return 1 + std::max(leftHeight, rightHeight);
}

template<typename T>
int countWeight(const Node<T>* rootptr) {
   
    // If the rootptr is null, it means we have reached the end of the tree, so we return 0 as the weight of the empty subtree
    if (rootptr == nullptr) return 0;

    // Count the number of nodes in the left and right subtrees and add 1 for the current node
    return 1 + countWeight(rootptr->left) + countWeight(rootptr->right);
}


template<typename T>
bool isBalanced(const Node<T>* rootptr) {
   
    // If the rootptr is null, it means the end is reached and the tree is considered to be balanced
    if (rootptr == nullptr) return true;

    // Get the weight of the left and right subtrees
    int leftWeight = countWeight(rootptr->left);
    int rightWeight = countWeight(rootptr->right);

    // If the absolute difference between the left and right subtrees is at most 1
    if (std::abs(leftWeight - rightWeight) <= 1)
    // Check the balance of the left and right subtrees
    return isBalanced(rootptr->left) && isBalanced(rootptr->right);

    // If the difference is greater than 1, the tree is not balanced
    return false;
}




template<typename T>
bool isBstHelper(const Node<T>* rootptr, T minValue, T maxValue) {
    // If the current Node is null, it means we have reached the end of the tree and all the nodes have been checked, so we return true
    if (!rootptr) return true;

    // If the current Node's data is not in (minValue;maxValue) then it is not a valid Node
    if (rootptr->data < minValue || rootptr->data > maxValue) return false;

    // If the current Node is  valid, check the left and right subtrees
    // The left subtree must have Nodes with values less than the current Node's value
    // The right subtree must have Nodes with values greater than the current Node's value
    return isBstHelper(rootptr->left, minValue, rootptr->data) && isBstHelper(rootptr->right, rootptr->data, maxValue);
}


template<typename T>
bool isBst(const Node<T>* rootptr) {
    return isBstHelper(rootptr, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

template<typename T>
void release(Node<T>* rootptr) {
    // Free memory allocated for each Node using 'delete'
    if (!rootptr) return;
    release(rootptr->left);
    release(rootptr->right);
    delete rootptr;
    
}


template<typename T>
Node<T>* toBalancedHelper(std::vector<T>& data, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node<T>* root = nullptr;
    try {
        root = new Node<T>(data[mid]);
        root->left = toBalancedHelper(data, start, mid - 1);
        root->right = toBalancedHelper(data, mid + 1, end);
    } catch (std::bad_alloc &e) {
        // freeing memory if new operator throws bad_alloc
        if (root != nullptr) {
            delete root;
        }
        // freeing memory of left sub tree
        release(root->left);
        root->left = nullptr;
        //  freeing memory of right sub tree
        release(root->right);
        root->right = nullptr;
        throw e;
    }
    return root;
}

template<typename T>
Node<T>* toBalanced(std::vector<T> data) {
    return toBalancedHelper(data, 0, data.size() - 1);
}

template<typename T>
void traverseHelper(const Node<T>* rootptr, std::vector<T> &result) {
    // If the current Node is null, return
    if (!rootptr) return;
    // Visit left subtree
    traverseHelper(rootptr->left, result);
    // Add current Node's data to the result vector
    result.push_back(rootptr->data);
    // Visit right subtree
    traverseHelper(rootptr->right, result);
}


template<typename T>
std::vector<T> toVector(const Node<T>* rootptr) {
    std::vector<T> result;
    traverseHelper(rootptr, result);
    return result;
}

template<typename T>
void levelHelper(const Node<T>* rootptr, int targetLevel, int currentLevel, std::vector<T> &result) {
    // If the current Node is null, it means we have reached the end of the tree
    if (!rootptr) return;
    // If the current level is equal to the target level, add the current Node's data to the result vector
    if (currentLevel == targetLevel) result.push_back(rootptr->data);
    // Otherwise, call the function for the left and right subtrees
    else {
        levelHelper(rootptr->left, targetLevel, currentLevel + 1, result);
        levelHelper(rootptr->right, targetLevel, currentLevel + 1, result);
    }
}



template<typename T>
std::vector<T> level(const Node<T>* rootptr, int level) {
    std::vector<T> result;
    levelHelper(rootptr, level, 0, result);
    return result;
}
