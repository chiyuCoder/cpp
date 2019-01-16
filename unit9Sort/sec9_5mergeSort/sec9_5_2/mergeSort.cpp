#include "../../sec9_5mergeSort/sec9_5_1/mergeSort.cpp"

template <class T>
void mergeSort(DataList<T> &L, DataList<T> &L2, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(L, L2, left, mid);
    mergeSort(L, L2, mid + 1, right);
    merge(L, L2, left, mid, right);
}