#define DefaultSize 10;

template <class T, class E>
class MinHeap : public MinPriorityQueue<T, E>
{
  private:
    E *heap;
    int currentSize;
    int maxHeapSize;
    void shiftDown(int start, int m) {
        int i = start, j = 2 * i + 1;//从0开始计数
        E temp = heap[i];
        while (j <= m) {
            if (j < m && heap[j] > heap[j+1]) {
                j++;
            }
            if (temp <= heap[j]) {
                break;
            }
            heap[i] = heap[j];
            i = j;
            j = 2 * j + 1;
        }
        heap[i] = temp;
    };
    void shiftUp(int start) {
        int j = start, i = (j - 1) / 2;
        E temp = heap[j];
        while(j > 0) {
            if (heap[j] <= temp) {
                break;
            }
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;
        }
        heap[j] = temp;
    };

  public:
    MinHeap(int sz = DefaultSize)
    {
        maxHeapSize = (sz > DefaultSize) ? DefaultSize : sz;
        heap = new E[maxHeapSize];
        if (heap == NULL)
        {
            cerr << "" << endl;
            exit(1);
        }
        currentSize = 0;
    };
    MinHeap(E arr[], int n) {
        maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
        heap = new E[maxHeapSize];
        if (heap == NULL)
        {
            cerr << "" << endl;
            exit(1);
        }
        for (int i = 0; i < n; i ++)
        {
            heap[i] = arr[i];

        }
        currentSize = n;
        int currentPos = (currentSize - 2) / 2;//从0开始计数
        while (currentPos >= 0) {
            shiftDown(currentPos, currentSize - 1);
            currentPos--;
        }
    };
    ~MinHeap()
    {
        delete[] heap;
    }
    bool Insert(const E &x) {
        if (currentSize == maxHeapSize) {
            cerr << "Heap Full" << endl;
            return false;
        }
        heap[currentSize] = x;
        shiftUp(currentSize);
        currentSize++;
        return true;
    };
    bool RemoveMin(E &x) {
        if(!currentSize) {
            cout << "Heap Empty" << endl;
            return false;
        }
        x = heap[0];
        heap[0] = heap[currentSize - 1];
        currentSize--;
        shiftDown(0, currentSize - 1);
        return true;
    };
    bool IsEmpty() const
    {
        return (currentSize == 0);
    }
    bool IsFull() const
    {
        return currentSize == maxHeapSize;
    }
    void MakeEmpty()
    {
        currentSize = 0;
    }

  
};