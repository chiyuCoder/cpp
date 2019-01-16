#include "../../sec9_1/sec9_1_3/DataList.h"

template <class T>
void BinaryInsertSort(DataList<T> &L, const int left, const int right)
{
    Element<t> temp;
    int i, low, high, middle, k;
    for (i = left + 1; i <= right; i++)
    {
        temp = L[i];
        low = left;
        high = i - 1;
        while (low <= high)
        {
            middle = (low + high) / 2;
            if (temp < L[middle])
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        for (k = i - 1; k >= low; k--)
        {
            L[k + 1] = L[k];
        }
        L[low] = temp;
    }
}