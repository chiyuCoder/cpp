#include "../../sec9_1/sec9_1_3/DataList.h"

template <class T>
void SelectSort(DataList<T> &L, const int left, const int right)
{
    for (int i = left; i < right; i++)
    {
        int k = i;
        for (int j = i + 1; j <= right; j++)
        {
            if (L[j] < L[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            Swap(L[i], L[k]);
        }
    }
}