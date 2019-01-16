#include "./Mtree.h"
const int maxValue = 99999999999;
template <class T>
Triple<T> MTree<T>::search(const T &x)
{
    Triple result;
    GetNode(root);
    MTreeNode<T> *p = root, //p是扫描指针
        *q = NULL;          //q是p的父结点指针
    while (p != NULL)
    {
        int i = 0;
        p->key[(p->n) + 1] = maxValue;
        while (p->key[i + 1] < x)
        {
            i++;
        }
        if (p->key[i + 1] == x)
        {

            result.r = p;
            result.i = i + 1;
            result.tag = 0;
            return result;
        }
        q = p;
        p = p->ptr[i]; //本结点没有x,q记下当前结点,p下降到相应子树
        GetNode(p);    //从磁盘上读取结点p
    }
    result.r = q;
    result.i = i;
    result.tag = 1;
    return result;
}