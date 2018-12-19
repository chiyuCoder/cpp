#include "./CircleLinkNode.cpp";

template <class T>
class CircleList : public LinearList<T>
{
  public:
    CircleList();
    CircleList(const T &x);
    CircleList(CircleList<T> L);
    ~CircleList();
    int Length() const;
    bool IsEmpty()
    {
        if (first->link == first)
        {
            return true;
        }
        return false;
    }
    CircleLinkNode<T> *getHead() const;
    void setHead(CircleLinkNode<T> *p);
    CircleLinkNode<T> *Search(T x);
    CircleLinkNode<T> *Locate(int i);
    T *getData(int i);
    void setData(int i, T &x);
    bool insert(int i, T &x);
    bool Remove(int i, T &x);

  private:
    CircleLinkNode<T> *first, *last;
}