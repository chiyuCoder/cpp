#include "./DataList.cpp"

const int deaultSize = 100;

template <class E, class K>
class SearchList : public DataList<E, K>
{
  public:
    SearchList(int sz = defaultSize) : DataList<E, K>(sz){};
    virtual int SeqSearch(const K x) const
    {
        //使用监视哨的顺序搜索算法
        element[currentSize].key = x; //将x设为监视哨
        int i = 0;
        while (element[i].key != x)
        {
            x++;
        }
        return i + 1;
    };
}