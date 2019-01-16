
typedef int T;
void BubbleSort(T V[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (V[j - 1] > V[j])
            {
                T temp = V[j - 1];
                V[j - 1] = V[j];
                V[j] = temp;
            }
        }
    }
}

typedef int T;
void BubbleSortOptimize(T V[], int n)
{
    bool exchange;
    int i, j;
    for (int i = 1; i < n; i++)
    {
        exchange = false;
        for (int j = n - 1; j >= 1; j--)
        {
            if (V[j - 1] > V[j])
            {
                T temp = V[j - 1];
                V[j - 1] = V[j];
                V[j] = temp;
                exchange = true;
            }
        }
        if (exchange == false)
        {
            return;
        }
    }
}