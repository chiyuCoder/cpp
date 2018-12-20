#include <iostream>
#include "./LinkedList.h"
#include "../sec_3_1_1/stack.cpp"

template <class T>
class LinkedStack : public Stack<T>
{
  public:
    LinkedStack() : top(NULL){};
    ~LinkedStack()
    {
        makeEmpty();
    };
    void Push(const T &x)
    {
        top = new LinkNode<T>(x, top);
        asset(top != NULL);
    };
    bool Pop(T &x)
    {
        if (IsEmpty() == true)
        {
            return false;
        }
        LinkNode<T> *p = top;
        top = top->link;
        x = p->data;
        delete p;
    };
    bool getTop(T &x) const
    {
        if (IsEmpty() == true)
        {
            return false;
        }
        x = top->data;
        return true;
    };
    bool IsEmpty() const
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    };
    void makeEmpty();
    int getSize() const
    {
        LinkNode<T> *p = top;
        int k = 0;
        while (top != NULL)
        {
            top = top->link;
            k++;
        }
        return k;
    };
    void makeEmpty()
    {
        LinkNode<T> *p;
        while (top != NULL)
        {
            p = top;
            top = top->link;
            delete p;
        }
    };
    friend ostream &operator<<(ostream &os, SeqStack<T> &s)
    {
        os << "栈中元素个数=" << s.getSize() << endl;
        LinkNode<T> *p = S.top;
        int i = 0;
        while(p != NULL) 
        {
            os << ++i << ":" << p->data << endl;
        }
        return os;
    };

  private:
    LinkNode<T> *top;
}