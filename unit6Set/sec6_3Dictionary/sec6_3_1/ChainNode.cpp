#include <assert.h>
template <class E, class K>
struct ChainNode{
    E data;
    ChainNode<E, K> *link;
    ChainNode() : link(NULL){};
    ChainNode(E &el, ChainNode<E, K> *next = NULL) : data(el), link(text){};
}