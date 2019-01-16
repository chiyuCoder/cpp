#include "../../sec9_1/sec9_1_3/DataList.h"

template <class T>
void InsertSort(DataList<T> &L, const int left, const int right)
{ //L.vector[left]到L.vector[i]有序
    Element<T> temp;
    int i, j;
    for (i = left + 1; i <= right; i++)
    {
        if (L[i] < L[i - 1])
        {
            temp = L[i];
            j = i - 1;
            do
            {
                L[j + 1] = L[j];
                j--;
            } while (j >= left && temp < L[j]);
            L[j + 1] = temp;
        }
    }
}