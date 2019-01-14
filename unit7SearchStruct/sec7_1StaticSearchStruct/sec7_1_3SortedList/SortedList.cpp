#include "../sec7_1_1StaticSearchTable/SearchList.cpp"

template <class E, class K>
class SortedList : public SearchList<E, K>
{
  public:
    SortedList(int sz = 100) : SearchList<E, K>(sz){};
    ~SortedList();
    int SequentSearch(const K x) const;
    int BinarySearch(const K x) const;
    bool Insert(const E &el);
    int Begin()
    {
        return (currentSize == 0) ? 0 : 1;
    }
    int Next(int i)
    {
        if (i >= 1 && i <= currentSize)
        {
            return i + 1;
        }
        return 0;
    }
}