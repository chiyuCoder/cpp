#include <iostream>
#include "../sec_3_3_1/Queue.cpp"

template <class T>

class LinkedQueue : public Queue<T>
{
  public:
    LinkedQueue() : rear(NULL), front(NULL){};
    ~LinkedQueue(){makeEmpty()};
    bool EnQueue(const T &x) 
    {
        if (front == NULL) {
            front = rear = new LinkNode<T>(x);
            if (front == NULL) {
                return false;
            }
        } else {
            rear->link = new LinkNode<T>(x);
            if (rear->link == NULL) {
                return false;
            }
            rear = rear->link;
        }
        return true;
    };
    bool DeQueue(T &x) {
        if (IsEmpty() == true) {
            return false;
        }
        LinkNode<T> *p = front;
        x = front->data;
        front = front->link;
        delete p;
        return true;
    };
    bool getFront(T &x) const 
    {
        if (IsEmpty() == true) {
            return false;
        }
        x = front->data;
        return true;
    };
    void makeEmpty() {
        LinkNode<T> *p;
        while(front != NULL) 
        {
            p = front;
            front = front->link;
            delete p;
        }
    };
    bool IsEmpty() const
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
    int getSize() const 
    {
        LinkNode<T> *p = front;
        int k = 0;
        while(p != NULL) {
            p = p->link;
            k ++;
        }
        return k;
    };
    friend ostream &operator<<(ostream &os, LinkedQueue<T> &Q) 
    {
        LinkNode<T> *p = Q.front; 
        int i = 0;
        while(p != NULL) 
        {
            os << ++i << ":" << p->data << endl;
            p = p->link;
        }
        return os;
    };

  protected:
    LinkNode<T> *front, *rear;
}