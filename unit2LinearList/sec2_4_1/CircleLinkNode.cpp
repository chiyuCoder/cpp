template <class T>
struct CircleLinkNode{
    T data;
    CircleLinkNode<T> *link;
    CircleLinkNode(CircleLinkNode<T> *next = NULL): link(next);
    CircleLinkNode(T d, CircleLinkNode<T> *next = NULL): data(d), link(text)
    {

    }
};