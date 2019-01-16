#include "../../sec9_1/sec9_1_3/DataList.h"

template <class T>
void ShellSort(DataList<T> &L, const int left, const int right)
{
    int i, j;
    int gap = right - left + 1;
    Element<T> temp;
    do
    {
        gap = gap / 3 + 1;
        for (i = left + gap; i <= right; i++)
        {
            if (L[i] < L[i - gap])
            {
                temp = L[i];
                j = i - gap;
                do
                {
                    L[j + gap] = L[j];
                    j = j - gap;
                } while (j > left && temp < L[j]);
                L[j + gap] = temp;
            }
        }
    } while (gap > 1);
}