#include <iostream>
#include "../../../unit3StackAndQueue/sec_3_1/sec_3_1_1/Stack.cpp"

template <class E, class K>
struct AVLNode : public BSTNode<E, K>
{
    int bf;
    AVLNode() : left(NULL), right(NULL), bf(0) {}
    AVLNode(E d, AVLNode<E, K> *l = NULL, AVLNode<E, K> *r = NULL) : data(d), left(l), right(r), bf(0) {}
};