#include <iostream>
template <class T>
struct BinaryTreeNode{
    T data;
    BinaryTreeNode<T> *leftChild, *rightChild;
    BinaryTreeNode() : leftChild(NULL), rightChild(NULL){};
    BinaryTreeNode(T x, BinaryTreeNode<T> *l = NULL, BinaryTreeNode<T> *r = NULL) : data(x), leftChild(l), rightChild(r){};
    
}