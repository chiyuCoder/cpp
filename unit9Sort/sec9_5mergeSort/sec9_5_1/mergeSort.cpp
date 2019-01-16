#include "../../sec9_1/sec9_1_3/DataList.h"

template <class T>
void merge(DataList<T> &L1, DataList<T> &L2, const int left, const int mid, const int right)
{
    for (int k = left; k <= right; k++)
    {
        L2[k] = L1[k];
    }
    int s1 = left;
    int s2 = mid + 1;
    int t = left;
    while (s1 <= mid && s2 <= right)
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
            s2++;
        }
    }
    while (s1 <= mid)
    {
        L1[t] = L2[s1];
        t++;
        s1++;
    }
    while (s2 <= right)
    {
        L1[t] = L2[s2];
        t++;
        s2++;
    }
}