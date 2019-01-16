#ifndef DATALIST_ELEMENT_H
#define DATALIST_ELEMENT_H
#include <iostream>

template <class T>
class Element
{
  public:
    T key;
    field otherData;
    Element<T> &operator=(Element<T> &x)
    {
        key = x.key;
        otherData = x.otherData;
        return this;
    };
    bool operator==(Element<T> &x)
    {
        return key == x.key;
    }
    bool operator<=(Element<T> &x)
    {
        return key <= x.key;
    }
    bool operator<(Element<T> &x)
    {
        return key < x.key;
    }
    bool operator>(Element<T> &x)
    {
        return key > x.key;
    }
};
#endif