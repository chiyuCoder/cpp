#include "../../sec9_1/sec9_1_3/DataList.h"

template <class T>
int DataList<T>::Partition(const int low, const int high)
{
    int pivotPos = low;
    Element<T> pivot = vector[low];
    for (int i = low + 1; i <= high; i++)
    {
        if (vector[i] < pivot)
        {
            pivotPos++;
            if (pivotPos != i)
            {
                Swap(vector[pivotPos], vector[i]);
            }
        }
    }
    vector[low] = vector[pivotPos];
    vector[pivotPos] = pivot;
    return pivotPos;
}

template <class T>
void QuickSort(DataList<T> &L, const int left, const int right)
{
    if (left < right)
    {
        int pivotPos = L.Partition(left, right);
        QuickSort(L, left, pivotPos - 1);
        QuickSort(L, pivotPos + 1, right);
    }
}