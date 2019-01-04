template <class T>
struct TreeNode{
    T data;
    TreeNode<T> *firstChild, *nextSibling;
    TreeNode(T value = 0; TreeNode<T> *fc = NULL, TreeNode<T> *ns = NULL) : data(value), firstChild(fc), nextSibling(ns){

    }
};