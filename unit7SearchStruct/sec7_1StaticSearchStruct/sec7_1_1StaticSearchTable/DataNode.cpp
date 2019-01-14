#include <iostream>
#include <assert.h>

template <class E, class K>
class DataList;

template <class E, class K>
class DataNode
{
    friend class DataList<E, K>;

  public:
    DataNode(const K x) : key(x) {}
    K getKey()
    {
        return key;
    }
    void setKey(K k)
    {
        key = k;
    }

  private:
    K key;
    //...other
};