template <class T>
struct ThreadNode{
    int lTag, rTag;
    ThreadNode<T> *leftChild, *rightChild;
    T data;
    ThreadNode(const T item): data(item), leftChild(NULL), rightChild(NULL), lTag(0), rTag(0){}
}