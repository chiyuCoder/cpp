template <class T>
class BinaryTree{
    public:
      BinaryTree();
      BinaryTree(BinaryTreeNode<T> *lch, BinaryTreeNode<T> *rch, T item);
      ~BinaryTree();
      int Height();
      int Size();//返回结点个数
      bool IsEmpty();
      BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *current);
      BinaryTreeNode<T> *LeftChild(BinaryTreeNode<T> *current);
      BinaryTreeNode<T> *RightChild(BinaryTreeNode<T> *current);
      bool Insert(T item);//按指定规则在树中插入新元素
      bool Remove(T item);//在树中删除元素
      bool Find(const T &item) const;
      bool getData(const T &item) const;
      BinaryTreeNode<T> *getRoot() const;
      //前序遍历
      void preOrder(void (* visit)(BinaryTreeNode<T> *p));
      //中序遍历
      void inOrder(void (* visit)(BinaryTreeNode<T> *p));
      //后序遍历
      void postOrder(void (* visit)(BinaryTreeNode<T> *p));
      //层次序遍历
      void levelOrder(void (* visit)(BinaryTreeNode<T> *p));
}