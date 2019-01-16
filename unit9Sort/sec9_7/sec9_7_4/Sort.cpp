#include "../../sec9_6/StaticLinkedList.h"

const int radix = 10;

template <class T>
void Sort(StaticLinkedList<T> &L, int d)
{
    int rear[radix],
        front[radix];

    int i, j, k, last, current, n = L.Length();
    for (i = 0; i < n; i++)
    {
        L[i].link = i + 1;
    }
    L[n].link = 0;
    current = 1;
    for (i = d; i >= 1; i--)
    {
        for (j = 0; j < radix; j++)
        {
            front[j] = 0;
            while (current != 0)
            {
                k = getDigit(L[current], i); // 取当前检测元素的第i个排序码
                if (front[k] == 0)
                {
                    front[k] = current;
                }
                else
                {
                    L[rear[k]].link = current;
                }
                rear[k] = current;
                current = L[current].link;
            }
            j = 0;
            while (front[j] == 0)
            {
                j++;
            }
            current = front[j];
            L[0].link = current;
            last = rear[j];
            for (k = j + 1; k < radix; k++)
            {
                if (front[k] != 0)
                {
                    L[last].link = front[k];
                    last = rear[k];
                }
            }
            L[last].link = 0;
        }
    }
}
