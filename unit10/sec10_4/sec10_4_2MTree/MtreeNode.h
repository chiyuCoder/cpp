template <class T>
struct MTreeNode
{
    int n; //关键码个数
    MTreeNode<T> *parent;
    T key[m + 1];             //key[m]为监视哨兼工作单元, key[0]未用
    MTreeNode<T> *ptr[m + 1]; //子树结点指针数组,ptr[m]在插入溢出时用
    int *refPtr[m + 1];       //每个索引项指向数据区相应记录起始地址的指针
};