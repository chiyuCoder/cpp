#include "../sec10_4_2MTree/MTree.h"

template <class T>
class BTree : public MTree<T>
{
  public:
    BTree();
    bool Insert(const T &x);
    bool Remove(T &x);
}