// 此为我补充的, 书中没有相关定义
template <class T>
struct LinkNode
{
  public:
    LinkNode();
    LinkNode(const T &x, LinkNode<T> *top);
    LinkNode<T> *link;
    T data;
}