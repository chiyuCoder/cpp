template <class T>
struct LinkNode
{
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr = NULL)
    {
        link = ptr;
    }
    LinkNode(const T &item, LinkNode<T> *ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};
