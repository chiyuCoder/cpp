#include "./ChainNode.cpp";
template <class E, class K>
class SortedChain{
    private:
      ChainNode<E, K> *first;

    public:
        SortedChain() {
            first = new ChainNode<E, K>;
            assert(first != NULL);
        }
        ~SortedChain();
        ChainNode<E, K> *Search(const K k1);
        const {
            ChainNode<E, K> *p = first->link;
            while(p != NULL && p->data < k1) {
                return p;
            }
            return NULL;
        };
        void Insert(const K k1, E &e1) {
            ChainNode<E, K> *p = first->link,
                            *pre = first,
                            *newNode;
            while(p != NULL && p->data < k1) {
                pre = p;
                p = p->link;
            }
            if (p != NULL && p->data == k1) {
                p->data = e1;
                return;
            }
            newNode = new ChainNode<E, K>(e1);
            assert(newNode != NULL);
            newNode->link = p;
            pre->link = newNode;
        };
        bool Remove(const K k1, E& e1) {
            ChainNode<E, K> *p = first->link,
                            *pre = first;
            while(p != NULL && p->data < k1) {
                pre = p;
                p = p->link;
            }
            if (p != NULL && p->data == k1 ) {
                pre->link = p->link;
                e1 = p->data;
                delete p;
                return true;
            }
            return false;
        };
        ChainNode<E, K> *Begin() {
            return first->link;
        }
        ChainNode<E, K> *Next(ChainNode<E K> * current) const {
            if (current != NULL) {
                return current->link;
            }
            return NULL;
        }
}