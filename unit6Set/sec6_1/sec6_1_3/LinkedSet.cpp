#include "./setNode.cpp"

template <class T>
class LinkedSet
{
  private:
    SetNode<T> *first,
        *last;

  public:
    LinkedSet()
    {
        first = last = new SetNode<T>;
    }
    LinkedSet(LinkedSet<T> &R)
    {
        SetNode<T> *srcPtr = R.first->link;
        first = last = new SetNode<T>;
        while (srcPtr != NULL)
        {
            last->link = new SetNode<T>(srcPtr->data);
            last = last->link;
            srcPtr = srcPtr->link;
        }
        last->link = NULL;
    };
    ~LinkedSet()
    {
        makeEmpty();
        delete first;
    }
    void makeEmpty();
    bool addMember(const T &x)
    {
        SetNode<T> *p = first->link,
                   *pre = first;
        while (p != NULL && p->data < x)
        {
            pre = p;
            p = p->link;
        }
        if (p != NULL && p->data == x)
        {
            return false;
        }
        SetNode<T> *s = new SetNode(x);
        s->link = p;
        pre->link = s;
        if (p == NULL)
        {
            last = s;
        }
        return true;
    };
    bool delMember(const T &x)
    {
        SetNode<T> *p = first->link,
                   *pre = first;
        while (p != NULL && p->data < x)
        {
            pre = p;
            p = p->link;
        }
        if (p != NULL && p->data == x)
        {
            pre->link = p->link;
            delete p;
            return true;
        }
        return false;
    };
    LinkedSet<T> &operator=(LinkedSet<T> &R)
    {
        SetNode<T> *pb = R.first->link;
        SetNode<T> *pa = first = new SetNode<T>;
        while (pb != NULL)
        {
            pa->link = new SetNode<T>(pb->data);
            pa = pa->link;
            pb = pb->link;
        }
        pa->link = NULL;
        last = pa;
        return this;
    };
    LinkedSet<T> operator+(LinkedSet<T> &R)
    {
        SetNode<T> *pb = R.first->link;
        SetNode<T> *pa = first->link;
        LinkedSet<T> temp;
        SetNode<T> *p,
            *pc = temp.first;
        while(pa != NULL && pb !=NULL) {
            if(pa->data == pb->data) {
                pc->link = new SetNode<T>(pa->data);
                pa = pa->link;
                pb = pb->link;
            } else if (pa->data < pb->data) {
                pc->link = new SetNode<T>(pa->data);
                pa = pa->link;
            } else {
                pc->link = new SetNode<T>(pb->data);
                pb = pb->link;
            }
            pc = pc->link;
        }
        if (pa != NULL) {
            p = pa;
        } else {
            p = pb;
        }
        while(p != NULL) {
            pc->link = new SetNode<T>(p->data);
            pc = pc->link;
            p = p->link;
        }
        pc->link = NULL;
        temp.last = pc;
        return temp;
    };

    LinkedSet<T> operator*(LinkedSet<T> &R) {
        SetNode<T> *pb = R.first->link;
        SetNode<T> *pa = first->link;
        LinkedSet<T> temp;
        SetNode<T>  *pc = temp.first;
        while(pa != NULL && pb != NULL) {
            if (pa->data == pb->data) {
                pc->link = new SetNode<T>(pa->data);
                pc = pc->link;
                pa = pa->link;
                pb = pb->link;
            } else if (pa->data < pb->data) {
                pa = pa->link;
            } else {
                pb = pb->link;
            }
        }
        pc->link = NULL;
        temp.last = pc;
        return temp;
    };
    LinkedSet<T> operator-(LinkedSet<T> &R) {
        SetNode<T> *pb = R.first->link;
        SetNode<T> *pa = first->link;
        LinkedSet<T> temp;
        SetNode<T> *pc = temp.first;
        while (pa != NULL && pb != NULL)
        {
            if(pa->data  == pb->data) {
                pa = pa->link;
                pb = pb->link;
            } else {
                if (pa->data < pb->data) {
                    pc->link = new SetNode<T>(pa->data);
                    pa = pa->link;
                    pc = pc->link;
                } else {
                    pb = pb->link;//A-B时,只保留A中与B不同数据
                }
            }
        }
        while(pa != NULL) {
            pc->link = new SetNode<T>(pa->data);
            pc = pc->link;
            pa = pa->link;
        }
        pc->link = NULL;
        temp.last = pc;
        return temp;
    };
    bool Contains(const T x)
    {
        SetNode<T> *temp = first->link;
        while (temp != NULL && temp->data < x)
        {
            temp = temp->link;
        }
        if (temp != NULL && temp->data == x)
        {
            return true;
        }
        return false;
    };
    bool operator==(LinkedSet<T> &R) {
        SetNode<T> *pb = R.first->link;
        SetNode<T> *pa = first->link;
        while (pa != NULL && pb != NULL)
        {
            if (pa->data == pb->data)
            {
                pa = pa->link;
                pb = pb->link;
            }
            else
            {
                return false;
            }
        }
        if(pa != NULL || pb != NULL) {
            return false;
        }
        return true;
    };
    bool Min(T &x);
    bool Max(T &x);
    bool subSet(bitSet<T> &R);
}