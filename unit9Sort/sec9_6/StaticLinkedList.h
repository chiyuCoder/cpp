#ifndef STATIC_LINKED_LIST
#define STATIC_LINKED_LIST
#include "../sec9_1/sec9_1_3/DataList.h"
const int defaultSize = 10;
template <class T>
struct Element
{
    T key;
    int link;
    Element() : link(0) {}
    Element(T x, int next = 0) : key(x), link(next) {}
};

template <class T>
class StaticLinkedList : public DataList<T>
{
  private:
    Element<T> *vector;
    int maxSize, n;

  public:
    StaticLinkedList(int sz = defaultSize) : maxSize(sz), n(0)
    {
        vector = new Element<T>[sz];
    }
    Element<T> &operator[](int i)
    {
        return vector[i];
    }
};
#endif