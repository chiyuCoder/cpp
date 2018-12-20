#include <assert.h>
#include <iostream>
#include "../sec_3_1_1/Stack.cpp"
//基于数组的存储表示实现的栈称为顺序栈，
const int stackIncrement = 20; //栈溢出时扩展空间的增量

template <class T>
class SeqStack : public Stack<T>
{
  public:
    SeqStack(int sz = 50) : top(-1), maxSize(sz)
    {
        elements = new T[maxSize];
        assert(elements != NULL);
    }
    ~SeqStack()
    {
        delete[] elements;
    }
    void Push(const T &x)
    {
        if (IsFull() == true)
        {
            overflowProcess();
        }
        elements[++top] = x;
    }
    /*
    //双栈的插入操作
    bool DualStackPush(DualStack &DS, T x, int d)
    {
        if (DS.t[0] + 1 == DS.t[1])
        {
            return false;
        }
        if (d == 0)
        {
            DS.t[0]++;
        }
        else
        {
            DS.t[1]--;
        }
        DS.Vector[DS.t[1]] = x;
        return true;
    }
    //双栈的删除操作
    bool DualStackPop(DualStack &DS, T &x, int d)
    {
        if (DS.t[1] == DS.b[1]) {
            return false;
        }
        x = DS.Vector[DS.t[1]];
        if (d == 0) {
            DS.t[0] --;
        } else {
            DS.t[1] ++;
        }
        return true;
    }
    */
    bool Pop(T &x)
    {
        if (IsEmpty() == true)
        {
            return false;
        }
        x = elements[top--];
        return true;
    }
    bool getTop(T &x)
    {
        if (IsEmpty() == true)
        {
            return false;
        }
        x = elements[top];
        return true;
    };
    bool IsEmpty() const
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool IsFull() const
    {
        if (top == maxSize - 1)
        {
            return true;
        }
        return false;
    }
    int getSize() const
    {
        return top + 1;
    }
    void MakeEmpty()
    {
        top = -1;
    }
    friend ostream &operator<<(ostream &os, SeqStack<T> &s)
    {
        os << "top=" << s.top << endl;
        for (int i = 0; i <= s.top; i++)
        {
            os << i << ":" << s.elements[i] << endl;
        }
        return os;
    }

  private:
    T *elements;
    int top; //最后加入元素的存储位置
    int maxSize;
    void overflowProcess()
    {
        T *newArray = new T[maxSize + stackIncrement];
        if (newArray == NULL)
        {
            cerr << "存储分配失败" << endl;
            exit(1);
        }
        for (int i = 0; i <= top; i++)
        {
            newArray[i] = elements[i];
        }
        maxSize = maxSize + stackIncrement;
        delete[] elements;
        elements = newArray;
    };
};