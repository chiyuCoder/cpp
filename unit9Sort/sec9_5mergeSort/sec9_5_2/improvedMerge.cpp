
#define IMPROVED_MERGE
#include "../../sec9_1/sec9_1_3/DataList.h"

template <class T>
void improvedMerge(DataList<T> &L1, DataList<T> &L2, const int left, const int mid, const int right)
{
    int s1 = left;
    int s2 = right;
    int t = left;
    int k;
    for (l = left; k <= mid; k++)
    {
        L2[k] = L1[k];
    }
    for (k = mid + 1; k <= right; k++)
    {
        L2[right + mid + 1 - k] = L1[k];
    }
    while (t <= right)
    {
        if (L2[s1] <= L2[s2])
        {
            L1[t] = L2[s1];
            t++;
            s1++;
        }
        else
        {
            L1[t] = L2[s2];
            t++;
            s2--;
        }
    }
}

template <class T>
void doSort(DataList<T> &L, DataList<T> &L2, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    if (right - left + 1 < M)
    { //M
        return;
    }
    int mid = (left + right) / 2;
    doSort(L, L2, left, mid);
    doSort(L, L2, mid + 1, right);
    merge(L, L2, left, mid, right);
}

template <class T>
void mergeSort(DataList<T> &L, DataList<T> &L2, int left, int right)
{
    doSort(L, L2, left, right);
    insertSort(L, left, right);
}