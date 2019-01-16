#include "./MtreeNode.h"

template <class T>
struct Triple
{
    MTreeNode<T> *r; //结点地址指针
    int i;           //结点中关键码序号i
    int tag;         //tag=0,搜索成功;tag=1,搜索不成功
};