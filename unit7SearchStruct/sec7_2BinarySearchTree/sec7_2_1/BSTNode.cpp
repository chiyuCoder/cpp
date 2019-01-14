#include <iostream>
#include <stdlib.h>

template <class E, class K>
struct BSTNode
{
    E data;
    BSTNode<E, K> *left,
        *right;
    BSTNode() : left(NULL), right(NULL){};
    BSTNode(const E d, BSTNode<E, K> *l = NULL, BSTNode<E, K> *r = NULL) : data(d), left(l), right(r){};
    ~BSTNode() {}
    void setData(E d) { data = d; }
    E getData()
    {
        return data;
    }
    bool operator<(const E &x)
    {
        if (data.key < x.key)
        {
            return true;
        }
        return false;
    }
    bool operator>(const E &x)
    {
        if (data.key > x.key)
        {
            return true;
        }
        return false;
    }
    bool operator==(const E &x)
    {
        if (data.key == x.key)
        {
            return true;
        }
        return false;
    }
}