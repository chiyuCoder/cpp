#include "./MtreeNode.h"
#include "./Triple.h"

template <class T>
class MTree
{
protected:
  MTreeNode<T> *root; //根指针
  int m;              //路数, ,即最大子树棵数,等于树的度
public:
  Triple<T> search(const T &x); //搜索
};