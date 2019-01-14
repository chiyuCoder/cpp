#include "./MSTEdgeNode.cpp"

template <class T, class E>
class MinSpanTree
{
  protected:
    MSTEdgeNode<T, E> *edgeValue;
    int maxSize,
        n;

  public:
    MinSpanTree(int sz = DefaultSize - 1) : maxSize(sz), n(0)
    {
        edgeValue = new MSTEdgeNode<T, E>[sz];
    }
    int Insert(MSTEdgeNode<T, E> &item);
}