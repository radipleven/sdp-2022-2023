#include "catch2/catch_all.hpp"
#include "Solution.h"

//TODO Add your own unit tests here (if you need any)

/* Attempt at testing release function
TEST_CASE("release() frees the memory of a binary tree") {

    Node<int>* root = new Node<int>(5);
    root->left = new Node<int>(3);
    root->right = new Node<int>(7);
    root->left->left = new Node<int>(1);
    root->left->right = new Node<int>(4);
    root->right->left = new Node<int>(6);
    root->right->right = new Node<int>(8);

    release(root);

    // Check that all memory has been freed
   
    REQUIRE(root == nullptr);
}
*/
TEST_CASE("countWeight() returns the correct number of nodes in a tree") {
    Node<int> a = Node<int>(1);
    Node<int> b = Node<int>(2, &a, nullptr);
    Node<int> c = Node<int>(3, &b, nullptr);
    Node<int>* rootptr = &c;
    
    REQUIRE(countWeight(rootptr) == 3);
}

TEST_CASE("getHeight() returns the correct height of a binary tree") {
    
    Node<int> d = Node<int>(4);
    Node<int> e = Node<int>(5);
    Node<int> b = Node<int>(2, &d, &e);
    Node<int> c = Node<int>(3);
    Node<int> a = Node<int>(1, &b, &c);
    Node<int>* rootptr = &a;
    
    REQUIRE(getHeight(rootptr) == 3);
}
