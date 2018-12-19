#include <iostream>

template <class T>
class DblList : public LinearList<T>
{
  public:
    DblList(T uniqueVal)
    {
        first = new DblNode<T>(uniqueVal);
        if (first == NULL)
        {
            cerr << "存储分配出错" << endl;
            exit(1);
        }
        first->rLink = first;
        first->lLink = first;
    }
    ~DblList();
    int Length() const
    {
        DblNode<T> *current = first->rLink;
        int count = 0;
        while (current != first)
        {
            current = current->rLink;
            count++;
        }
        return count;
    }
    bool IsEmpty()
    {
        return first->rLink == first;
    }
    DblNode<T> *getHead() const
    {
        return first;
    }
    void setHead(DblNode<T> *ptr)
    {
        first = *ptr;
    }
    DblNode<T> *Search(const T &x)
    { //带有附加头
        DblNode<T> *current = first->rlink;
        while (current != first && current->data != x)
        {
            current = current->rLink;
        }
        if (current != first)
        {
            return current;
        }
        return NULL;
    }
    DblNode<T> *Locate(int i, int d)
    { //d 用来判断方向
        if (first->rLink == first || i == 0)
        {
            return first;
        }
        DblNode<T> *current;
        if (d == 0)
        {
            current = first->lLink;
        }
        else
        {
            current = first->rLink;
        }
        for (int j = 1; j < i; j++)
        {
            if (current == first)
            {
                break;
            }
            else
            {
                if (d == 0)
                {
                    current = first->lLink;
                }
                else
                {
                    current = first->rLink;
                }
            }
        }
        if (current != first)
        {
            return current;
        }
        return NULL;
    }
    bool Insert(int i, const T &x, int d) 
    {
        DblNode<T> *current = Locate(i);
        if (current == NULL) {
            return false;
        }
        DblNode<T> *newNode = new DblNode<T>(x);
        if (newNode == NULL) {
            cerr << "存储分配失败" << endl;
            exit(1);
        }
        if (d == 0) {
            newNode->lLink = current->lLink;
            current->lLink = newNode;
            newNode->lLink->rLink = newNode;
            newNode->rLink = current;
        } else {
            newNode->rLink = current->rLink;
            current->rLink = newNode;
            current->rLink->lLink = newNode;
            newNode->lLink = current;
        }
        return true;
    }
    bool Remove(int i, T &x, int d) 
    {
        DblNode<T> *current = Locate(i, d);
        if (current == NULL) {
            return false;
        }
        current->rLink->lLink = current->lLink;
        current->lLink->rLink = current->rlink;
        x = current->data;
        delete current;
        return true;
    }

  private:
    DblNode<T> *first;
};