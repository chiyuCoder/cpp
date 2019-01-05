template <class T>
struct SetNode{
    T data;
    SetNode<T> *link;
    SetNode() : link(NULL){};
    SetNode(const T &x, SetNode<T> *next = NULL) : data(x), link(next){};
}