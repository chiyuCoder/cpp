#ifndef DATALIST_H
#define DATALIST_H

#include "./Element.h"
const int defaultSize = 100;

template <class T>
class DataList
{
  private:
    Element<T> *vector;
    int maxSize;
    int currentSize;

  public:
    DataList(int size = defaultSize) : maxSize(size), currentSize(0)
    {
        vector = new Element<T>[maxSize];
    }
    void Swap(Element<T> &x, Element<T> &y)
    {
        Element<T> temp = x;
        x = y;
        y = temp;
    }
    int Length()
    {
        return currentSize;
    }
    Element<T> &operator[](int i)
    {
        return vector[i];
    }
    int Partition(const int low, const int high); //快速排序划分
};
#endif
