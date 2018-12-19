#include "./LinkNode.cpp";

template <class T>
class List : public LinearList<T>
{
  public:
    List()
    {
        first = new LinkNode<T>;
    }
    List(const T &x)
    {
        first = new LinkNode<T>(x);
    }
    List(List<T> &L)
    {
        T value;
        LinkNode<T> *srcPtr = L.getHead();
        first = new LinkNode<T>;
        LinkNode<T> *destPtr = first;
        while (srcPtr->link != NULL)
        {
            value = srcPtr->link->data;
            destPtr->link = new LinkNode<T>(value);
            destPtr = destPtr->link;
            srcPtr = srcPtr->link;
        }
        destPtr->link = NULL;
    }
    ~List()
    {
        makeEmpty();
    }
    void makeEmpty()
    {
        LinkNode<T> *q;
        while (first->link != NULL)
        {
            q = first->link;
            first->link = q->link;
            delete q;
        }
    }
    int Length() const
    {
        LinkNode<T> *p = first->link;
        int count = 0;
        while (p != NULL)
        {
            p = p->link;
            count++;
        }
        return count;
    }
    LinkNode<T> *getHead() const
    {
        return first;
    }
    void setHead(LinkNode<T> *p)
    {
        first = p;
    }
    LinkNode<T> *Search(T x)
    {
        LinkNode<T> *current = first->link;
        while (current != NULL)
        {
            if (current->data != NULL)
            {
                break;
            }
            else
            {
                current = current->link;
            }
        }
        return current;
    }
    LinkNode<T> *Locate(int i)
    {
        if (i < 0)
        {
            return NULL;
        }
        LinkNode<T> *current = first;
        int k = 0;
        while (current != NULL && k < i)
        {
            current = current->link;
            k++;
        }
        return current;
    }
    T *getData(int i)
    {
        if (i <= 0)
        {
            return NULL;
        }
        LinkNode<T> *current = Locate(i);
        if (current == NULL)
        {
            return NULL;
        }
        return &current->data;
    }
    void setData(int i, T &x)
    {
        if (i <= 0)
        {
            return;
        }
        LinkNode<T> *current = Locate(i);
        if (current == NULL)
        {
            return;
        }
        current->data = x;
    }
    bool Insert(int i, T &x)
    {
        LinkNode<T> *current = Locate(i);
        if (current == NULL)
        {
            return false;
        }
        LinkNode<T> *newNode = new LinkNode<T>(x);
        if (newNode == NULL)
        {
            cerr << "存储分配错误!" << endl;
            exit(1);
        }
        newNode->link = current->link;
        current->link = newNode;
        return true;
    }
    bool Remove(int i, T &x)
    {
        LinkNode<T> *current = Locate(i - 1);
        if (current == NULL || current->link == NULL)
        {
            return false;
        }
        LinkNode<T> *del = current->link;
        current->link = del->link;
        x = del->data;
        delete del;
        return true;
    }
    bool IsEmpty() const
    {
        if (first->link == NULL)
        {
            return false;
        }
        return true;
    }
    bool isFull() const
    {
        return false;
    }
    void Sort();
    void inputFront(T endTag)
    { //前插法
        LinkNode<T> *newNode;
        T val;
        first = new LinkNode<T>;
        if (first == NULL)
        {
            cerr << "存储分配错误!" << endl;
            exit(1);
        }
        cin >> val;
        while (val != endTag)
        {
            newNode = new LinkNode<T>(val);
            newNode->link = first->link;
            first->link = newNode;
            cin >> val;
        }
    }
    void inputRear(T endTag)
    { //后插法
        LinkNode<T> *newNode;
        LinkNode<T> *last;
        T val;
        first = new LinkNode<T>;
        if (first == NULL)
        {
            cerr << "存储分配错误!" << endl;
            exit(1);
        }
        cin >> val;
        last = first;
        while (val != endTag)
        {
            newNode = new LinkNode<T>(val);
            if (newNode == NULL)
            {
                cerr << "存储分配错误!" << endl;
                exit(1);
            }
            last->link = newNode;
            last = newNode;
            cin >> val;
        }
        last->link = NULL;
    }
    void input()
    {
    }
    void output()
    {
        LinkNode<T> *current = first->link;
        while (current != NULL)
        {
            count << current->data << endl;
            current = current->link;
        }
    }
    List<T> &operator=(List<T> &L)
    {
        T value;
        LinkNode<T> *srcPtr = L.getHead();
        first = new LinkNode<T>;
        LinkNode<T> *destPtr = first;
        while (srcPtr->link != NULL)
        {
            value = srcPtr->link->data;
            destPtr->link = new LinkNode<T>(value);
            destPtr = destPtr->link;
            srcPtr = srcPtr->link;
        }
        destPtr->link = NULL;
        return *this;
    }

  protected:
    LinkNode<T> *first;
};
