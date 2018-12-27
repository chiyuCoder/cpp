#include <iostream>
#include "./BinaryTreeNode.cpp"
#include "../../unit3StackAndQueue/sec_3_1/sec_3_1_1/Stack.cpp"
#include "../../unit3StackAndQueue/sec3_3Queue/sec_3_3_1/Queue.cpp"
using std::cout;
template <class T>
struct StackNodeForPostOrder{
    BinaryTreeNode<T> *ptr;
    enum tag
    {
        L,
        R
    };
    StackNodeForPostOrder(BinaryTreeNode<T> *n = NULL) : ptr(n), tag(L){};
};
template <class T>
class BinaryTree
{
  public:
    BinaryTree() : root(NULL){};
    BinaryTree(T value) : RefValue(value), root(NULL){};
    BinaryTree(BinaryTree<T> &s);
    ~BinaryTree()
    {
        destory(root);
    };
    bool IsEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        return false;
    };
    BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *current)
    {
        if (root == NULL || root == current)
        {
            return NULL;
        }
        return Parent(root, current);
    };
    BinaryTreeNode<T> *LeftChild(BinaryTreeNode<T> *current)
    {
        if (current == NULL)
        {
            return NULL;
        }
        return current->leftChild;
    }
    BinaryTreeNode<T> *RightChild(BinaryTreeNode<T> *current)
    {
        if (current == NULL)
        {
            return NULL;
        }
        return current->rightChild;
    }
    int Height()
    {
        return Height(root);
    }
    int Size()
    {
        return Size(root);
    }
    BinaryTreeNode<T> *getRoot() const
    {
        return root;
    }
    void preOrder(void (*visit)(BinaryTreeNode<T> *p))
    {
        preOrder(root, visit);
    }
    void preOrderUnRecursive(void (*visit)(BinaryTreeNode<T> *p))
    { //非递归
        Stack<BinaryTreeNode<T> *> S;
        BinaryTree<T> *p = root;
        S.Push(NULL);
        while (p != NULL)
        {
            visit(p);
            if (p->RightChild != NULL)
            {
                S.Push(RightChild);
            }
            if (p->LeftChild != NULL)
            {
                p = p->LeftChild;
            }
            else
            {
                S.Pop(p);
            }
        }
    };
    void inOrder(void (*visit)(BinaryTreeNode<T> *p))
    {
        inOrder(root, visit);
    }
    void inOrderUnRecursive(void (*visit)(BinaryTreeNode<T> *p))
    {
        Stack<BinaryTreeNode<T> *> S;
        BinaryTreeNode<T> *p = root;
        do {
            while(p != NULL) {
                S.Push(p);
                p = p->leftChild;
            }
            if (!S.isEmpty()) {
                S.Pop(p);
                p = p->rightChild;
            }
        } while (p != NULL || !S.isEmpty());
    }
    
    void postOrder(void (*visit)(BinaryTreeNode<T> *p))
    {
        postOrder(root, visit);
    }
    void postOrderUnRecursive(void (*visit)(BinaryTreeNode<T> *p))
    {
        Stack<StackNodeForPostOrder<T>> S;
        StackNodeForPostOrder<T> w;
        BinaryTree<T> *p = root;
        do {
            while(p != NULL) {
                w.ptr = p;
                w.tag = L;
                S.Push(w);
                p = p->LeftChild;
            }
            int continueLeft = 1;
            while (continueLeft && !S.isEmpty()) {
                S.Pop(w);
                p = w.ptr;
                switch(w.tag) {
                    case L:
                        w.tag = R;
                        S.Push(w);
                        continueLeft = 0;
                        p = p->RightChild;
                        break;
                    case R:
                        visit(p);
                        break;
                }
            }
        } while (!S.isEmpty());
    }
    
    void levelOrder(void (*visit)(BinaryTreeNode<T> *p))
    {
        levelOrder(root, visit);
    }
    void levelOrder2(void (*visit)(BinaryTreeNode<T> *p)){
        Queue<BinaryTreeNode<T> *> Q;
        BinaryTreeNode<T> *p = root;
        Q.EnQueue(p);
        while(!Q.IsEmpty()) {
            Q.DeQueue(p);
            visit(p);
            if (p->leftChild) {
                Q.EnQueue(p->leftChild);
            }
            if (p->rightChild) {
                Q.EnQueue(p->rightChild);
            }
        }
    };
    int Insert(const T item);
    BinaryTreeNode < T ? *Find(T item) const;

  protected:
    BinaryTreeNode<T> *root;
    T RefValue;
    /**
       * 
       * 形如: A(B(D, E(G,)), C(, F))#
       * 
       * */
    void CreateBinaryTree(istream &in, BinaryTreeNode<T> *&BT)
    {
        Stack<BinaryTreeNode<char> *> s;
        BT = NULL;
        BinaryTreeNode<char> *p, *t;
        int k;
        char ch;
        in >> ch;
        while (ch != RefValue) //RefValue = #
        {
            switch (ch)
            {
            case '(': //进入子树
                s.Push(p);
                k = 1;
                break;
            case ')': //退出子树
                s.Pop(t);
                break;
            case ',':
                k = 2;
                break;
            default:
                p = new BinaryTreeNode(ch);
                if (BT == NULL)
                {
                    BT = p;
                }
                else
                {
                    s.getTop(t);
                    if (k == 1)
                    {
                        t->leftChild = p;
                    }
                    else
                    {
                        t->leftChild = p;
                    }
                }
            }
            in >> ch;
        }
    };
    bool Insert(BinaryTreeNode<T> *&subTree, const T &x);
    void destory(BinaryTreeNode<T> *&subTree)
    {
        if (subTree == NULL)
        {
            destory(subTree->rightChild);
            destory(subTree->leftChild);
            delete subTree;
        }
    };
    bool Find(BinaryTreeNode<T> *subTree, const T &x);
    BinaryTreeNode<T> *Copy(BinaryTreeNode<T> *originNode)
    {
        if (originNode == NULL)
        {
            return NULL;
        }
        BinaryTreeNode<T> *temp = new BinaryTreeNode<T>;
        temp->data = originNode->data;
        temp->leftChild = Copy(originNode->leftChild);
        temp->rightChild = Copy(originNode->rightChild);
        return temp;
    };
    int Height(BinaryTreeNode<T> *subTree)
    {
        if (subTree == NULL)
        {
            return 0;
        }
        int i = Height(subTree->leftChild);
        int j = Height(subTree->rightChild);
        if (i < j)
        {
            return j + 1;
        }
        return i + 1;
    };
    int Size(BinaryTreeNode<T> *subTree) const
    {
        if (subTree == NULL)
        {
            return 0;
        }
        return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
    };
    BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *subTree, BinaryTreeNode<T> *current)
    {
        if (subTree == NULL)
        {
            return NULL;
        }
        if (subTree->leftChild == current || subTree->rightChild == current)
        {
            return subTree;
        }
        BinaryTreeNode<T> *p;
        p = Parent(subTree->leftChild, current);
        if (p != NULL)
        {
            return p;
        }
        return Parent(subTree->rightChild, current);
    };
      BinaryTreeNode<T> *Find((BinaryTreeNode<T> *subTree, const T & x)const;
      void Traverse(BinaryTreeNode<T> *subTree, ostream& out) {
        if (subTree == NULL)
        {
            return;
        }
        out << subTree->data << ' ';
        Traverse(subTree->leftChild, out);
        Traverse(subTree->rightChild, out);
      };
      void preOrder(BinaryTreeNode<T> &subTree, void (* visit)(BinaryTreeNode<T> *p)) {
        if (subTree != NULL)
        {
            visit(subTree);
            preOrder(subTree->leftChild, visit);
            preOrder(subTree->leftChild, visit);
        }
      };
      void postOrder(BinaryTreeNode<T> &subTree, void (* visit)(BinaryTreeNode<T> *p)) {
        postOrder(subTree->leftChild, visit);
        postOrder(subTree->rightChild, visit);
        visit(subTree);
      };
      void levelOrder(BinaryTreeNode<T> &subTree, void (* visit)(BinaryTreeNode<T> *p));
      void inOrder(BinaryTreeNode<T> &subTree, void (* visit)(BinaryTreeNode<T> *p)) {
        if (subTree != NULL)
        {
            inOrder(subTree->leftChild, visit);
            visit(subTree);
            inOrder(subTree->rightChild, visit);
        }
      };
      friend istream& operator>>(istream& in, BinaryTreeNode<T> & Tree) {
        CreateBinaryTree(in, Tree, root);
        return in;
      };
      friend istream& operator<<(ostream& out, BinaryTreeNode<T> & Tree) {
        Tree.Traverse(Tree.root, out);
        return out;
      };
}