#include <assert.h>
const int defaultSize = 100;


template <class E, class K>
struct ChainNode{
    E data;
    ChainNode<E, K> *link;
};

template <class E, class K>
class HashTable{
    public:
      HashTable(int d, int sz = defaultSize){
          divisor = d;
          TableSize = sz;
          ht = new ChainNode<E, K> *[sz];
          assert(ht != NULL);
      };
      ~HashTable() {
          delete[] ht;
      };
      bool Search(const K k1, E& e1);
      bool Insert(E& e1);
      bool Remove(const K k1, E& e1);
    private:
      int divisor;
      int TableSize;
      ChainNode<E, K> **ht;
      ChainNode<E, K> *FindPos(const K k1) {
          int i = k1 % divisor;
          ChainNode<E, K> *p = ht[j];
          while(p != NULL && p->data != k1) {
              p = p->link;
          }
          return p;
      }
};