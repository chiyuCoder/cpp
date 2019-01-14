#include "./DataNode.cpp"

const int deaultSize = 100;

template <class E, class K>
class DataList
{
  protected:
    DataNode<E, K> *element;
    int arraySize, currentSize;

  public:
    DataList(int sz = defaultSize) : arraySize(sz), currentSize(0)
    {
        element = new DataNode<E, K>[sz];
        assert(element != NULL);
    };
    DataList(DataList<E, K> &R);
    virtual ~DataList() { delete[] element; };
    virtual int Length()
    {
        return currentSize;
    }
    virtual K getKey(int i) const
    {
        assert(i > 0 || i <= currentSize);
        return element[i - 1].getKey();
    }
    virtual int SeqSearch(const K x) const;
    virtual bool Insert(E &el)
    {
        if (currentSize == arraySize)
        {
            return false;
        }
        element[currentSize] = el;
        currentSize++;
        return true;
    };
    virtual bool Remove(const K x, E &el)
    {
        if (currentSize == 0)
        {
            return false;
        }
        int i = 0;
        for (; i < currentSize && element[i].getKey() != x; i++)
            ;
        if (i == currentSize)
        {
            return false;
        }
        el = element[i];
        element[i] = element[currentSize - 1];
        currentSize--;
        return true;
    };
    friend ostream &operator<<(ostream &out, const DataList<E, K> &outList);
    friend istream &operator>>(istream &in, DataList<E, K> &inList);
};