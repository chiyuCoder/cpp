template <class T, class E>
struct HuffmanNode{
    E data;
    HuffmanNode<T, E> *leftChild, *rightChild, *parent;
    HuffmanNode(): leftChild(NULL), rightChild(NULL), parent(NULL) {

    }
    HuffmanNode(E elm, HuffmanNode<T, E> *left = NULL, HuffmanNode<T, E> *right = NULL, HuffmanNode<T, E> *pr = NULL) : leftChild(left), rightChild(right), parent(pr)
    {
    }
}