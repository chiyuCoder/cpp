#include <iostream>
#include "./BSTNode.cpp"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
template <class E, class K>
class BSTree
{
  private:
    BSTNode<E, K> *root;
    K refValue;
    BSTNode<E, K> *search(const K x, BSTNode<E, K> *ptr)
    {
        if (ptr == NULL)
        {
            return NULL;
        }
        if (x < ptr->data)
        {
            return search(x, ptr->left);
        }
        if (x > ptr->data)
        {
            return search(x, ptr->right);
        }
        return ptr;
    };
    void makeEmpty(BSTNode<E, K> *&ptr);
    void printTree(BSTNode<E, K> *ptr) const;
    BSTNode<E, K> *copy(const BSTNode<E, K> *ptr);
    BSTNode<E, K> *min(BSTNode<E, K> *ptr) const;
    BSTNode<E, K> *max(BSTNode<E, K> *ptr) const;
    bool Insert(const E &el, BSTNode<E, K> *&ptr)
    {
        if (ptr == NULL)
        {
            ptr = new BSTNode<E, K>(el);
            if (ptr == NULL)
            {
                cerr << "out of space" << endl;
                exit(1);
            }
            return true;
        }
        if (el < ptr->data)
        {
            return Insert(el, ptr->left);
        }
        if (el > ptr->data)
        {
            return Insert(el, ptr->right);
        }
        return false;
    };
    bool Remove(const K x, BSTNode<E, K> *&ptr)
    {
        BSTNode<E, K> *temp;
        if (ptr != NULL)
        {
            if (x < ptr->data)
            {
                Remove(x, ptr->left);
            }
            else if (x > ptr->data)
            {
                Remove(x, ptr->right);
            }
            else
            {
                if (ptr->left != NULL && ptr->right != NULL)
                {
                    temp = ptr->right;
                    while (temp->left != NULL)
                    {
                        temp = temp->left;
                    }
                    ptr->data = temp->data;
                    Remove(ptr->data, ptr->right);
                }
                else
                {
                    temp = ptr;
                    if (ptr->left == NULL)
                    {
                        ptr = ptr->right;
                    }
                    else
                    {
                        ptr = ptr->left;
                    }
                    delete temp;
                    return true;
                }
            }
            return false;
        }
    };

  public:
    BSTree() : root(NULL){};
    BSTree(K value)
    {
        E x;
        root = NULL;
        refValue = value;
        while (x.key != refValue)
        {
            Insert(x, root);
            cin >> x;
        }
    };
    ~BSTree(){};
    bool search(const K x) const
    {
        if (search(x, root) != NULL)
        {
            return true;
        }
        return false;
    }
    BSTree<E, K> &operator=(const BSTree<E, K> &R);
    void makeEmpty()
    {
        makeEmpty(root);
        root = NULL;
    }
    void printTree() const
    {
        printTree(root);
    }
    E min()
    {
        return min(root)->data;
    }
    E max()
    {
        return max(root)->data;
    }
    bool Insert(const E &el)
    {
        return Insert(el, root);
    }
    bool Remove(const K x)
    {
        return Remove(x, root);
    }
}