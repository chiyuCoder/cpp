#include "./HuffmanNode.cpp"
#include "../sec5_8Heap/MinHeap.cpp"
template <class T, class E> 
class HuffmanTree{
    public:
      HuffmanTree(E w[], int n) {
          MinHeap<T, E> hp;
          HuffmanNode<T, E> *parent, &first, &second;
          HuffmanNode<T, E> *NodeList = new HuffmanNode<T, E>[n];
          for (int i = 0; i < n; i ++)
          {
              NodeList[i].data = w[i + 1];
              NodeList[i].leftChild = NULL;
              NodeList[i].rightChild = NULL;
              NodeList[i].parent = NULL;
              hp.Insert(NodeList[i]);
          }
          for (i = 0; i < n - 1; i ++)
          {
              hp.RemoveMin(first);
              hp.RemoveMin(second);
              merge(first, second, parent);
              hp.Insert(*parent);
              root = parent;
          }
      };
      ~ HuffmanTree() {
          deleteTree(root);
      }
    protected:
      HuffmanNode<T, E> *root;
      void deleteTree(HuffmanNode<T, E> *t);
      void mergeTree(HuffmanNode<T, E> &ht1, HuffmanNode<T, E> &ht2, HuffmanNode<T, E> * &parent) {
          parent = new E;
          parent->leftChild = &bt1;
          parent->rightChild = &bt2;
          parent->data.key = bt1.root->data + bt2.root->data.key;
          bt1.root->parent = parent;
          bt2.root->parent = parent;
      }
}