#include <assert.h>
#include <iostream>
#include <stdlib.h>

const int DefaultPQSize = 50;
template <class T>
class PQueue
{
  public:
    PQueue(int sz = DefaultPQSize): maxSize(sz), count(0) {
        pqelements = new T[maxSize];
        assert(pqelements != NULL);
    };
    ~PQueue()
    {
        delete[] pqelements;
    }
    bool Insert(const T &x) {
        if (count == maxSize) {
            return false;
        }
        pqelements[count ++] = x;
        adjust();
    };
    bool RemoveMin(T &x) {
        if (count == 0) {
            return false;
        }
        x = pqelements[0];
        for (int i = 1; i < count; i ++) {
            pqelements[i - 1] = pqelements[i];
        }
        count --;
        return true;
    };
    T* getFront(T &x) const {
        if (count == 0) {
            return NULL;
        } 
        return &pqelements[0];
    };
    void makeEmpty()
    {
        count = 0;
    }
    bool IsEmpty() const
    {
        if (count == 0)
        {
            return true;
        }
        return false;
    }
    bool IsFull() const
    {
        if (count == maxSize)
        {
            return true;
        }
        return false;
    }
    int getSize() const
    {
        return count;
    }

  protected:
    T *pqelements;
    int count;
    int maxSize;
    void adjust() {
        //将队尾元素按其优先权大小调整到适当位置,保持所有元素按优先权从小到大有序.
        T item = pqelements[count - 1];
        for (int j = count - 2; j >= 0; j --) {
            if (pqelements[j] <= item) {
                break;
            } else {
                pqelements[j + 1] = pqelements[j];
                 pqelements[j] = item;
                //比 item 大的元素 pqelements[j]后移
            }
        }
    };
}