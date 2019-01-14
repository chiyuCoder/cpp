#include "./AVLNode.cpp"
#include "../../sec7_2BinarySearchTree/sec7_2_1/BSTree.cpp"
template <class E, class K>
class AVLTree : public BSTree<E, K>
{
  protected:
    AVLNode<E, K> *search(K x, AVLNode<E, K> &tree);
    bool Insert(AVLNode<E, K> *&ptr, E &el)
    {
        AVLNode<E, K> *pr = NULL,
                      *p = ptr,
                      *q;
        int d;
        Stack<AVLNode<E, K> *> st;
        //查找值为el的元素===>
        while (p != NULL)
        {
            if (el == p->data)
            {
                return false;
            }
            pr = p;
            st.Push(pr);
            if (el < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        //查找值为el的元素<===
        //插入值为el的新结点==>
        p = new AVLNode<E, K>(el);
        if (p == NULL)
        {
            cerr << "存储空间不足" << endl;
            exit(1);
        }
        if (pr == NULL)
        {
            ptr = p;
            return true;
        }
        if (el < pr->data)
        {
            pr->left = p;
        }
        else
        {
            pr->right = p;
        }
        //插入值为el的新结点<==

        // st.isEmpty() 为true, 则说明传入ptr的值为所要插入的值, 也就是说, 该树即为所求

        while (st.isEmpty() == false)
        {
            st.Pop(pr);
            if (p == pr->left)
            {
                pr->bf--;
            }
            else
            {
                pr->bf++;
            }
            if (pr->bf == 0)
            {
                break;
            }
            if (pr->bf == 1 || pr->bf == -1)
            {
                p = pr;
            }
            else
            {
                d = (pr->bf < 0) ? -1;
                1;
                if (p->bf == d)
                {
                    if (d == -1)
                    {
                        RotateR(pr);
                    }
                    else
                    {
                        RotateL(pr);
                    }
                }
                else
                {
                    if (d == -1)
                    {
                        RotateLR(pr);
                    }
                    else
                    {
                        RotateRL(pr);
                    }
                    break;
                }
            }
            if (st.isEmpty() == true)
            {
                ptr = pr;
            }
            else
            {
                st.getTop(q);
                if (q->data > pr->data)
                {
                    q->left = ptr;
                }
                else
                {
                    q->right = pr;
                }
            }
            return true;
        }
    };
    bool Remove(AVLNode<E, K> *&ptr, K x, E &el)
    {
        AVLNode<E, K> *pr = NULL,
                      *p = ptr,
                      *q,
                      *ppr;
        int d,
            dd = 0;
        Stack<AVLNode<E, K> *> st;
        while (p != NULL)
        {
            if (k == p->data.key)
            {
                break;
            }
            pr = p;
            st.Push(pr);
            if (k < p->data.key)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
        if (p == NULL)
        {
            return false;
        }
        if (p->left != NULL && p->right != NULL)
        {
            pr = p;
            st.Push(pr);
            q = p->left;
            while (p->right != NULL)
            {
                pr = q;
                st.Push(pr);
                q = q->right;
            }
            p->data = q->data;
            p = q;
        }
        if (p->left != NULL)
        {
            q = p->left;
        }
        else
        {
            q = p->right;
        }
        if (pr == NULL)
        {
            ptr = q;
        }
        else
        {
            if (pr->left == p)
            {
                pr->left = q;
            }
            else
            {
                pr->right = q;
            }
            while (st.isEmpty() == false)
            {
                st.Pop(pr);
                if (pr->right == q)
                {
                    pr->bf--;
                }
                else
                {
                    pr->bf++;
                }
                if (st.isEmpty() == false)
                {
                    st.getTop(ppr);
                    dd = (ppr->left == pr) ? -1 : 1;
                }
                else
                {
                    dd = 0;
                }
                if (pr->bf == 1 || pr->bf == -1)
                {
                    break;
                }
                if (pr->bf != 0)
                {
                    if (pr->bf < 0)
                    {
                        d = -1;
                        q = pr->left;
                    }
                    else
                    {
                        d = 1;
                        q = pr->right;
                    }
                    if (q->bf == 0)
                    {
                        if (d == -1)
                        {
                            RotateR(pr);
                            pr->bf = 1;
                            pr->left->bf = -1;
                        }
                        else
                        {
                            RotateL(pr);
                            pr->bf = -1;
                            pr->right->bf = 1;
                        }
                        break;
                    }
                    if (q->bf == d)
                    {
                        if (d == -1)
                        {
                            RotateR(pr);
                        }
                        else
                        {
                            RotateL(pr);
                        }
                    }
                    else
                    {
                        if (d == -1)
                        {
                            RotateLR(pr);
                        }
                        else
                        {
                            RotateRL(pr);
                        }
                    }
                    if (dd == -1)
                    {
                        ppr->left = pr;
                    }
                    else if (dd == 1)
                    {
                        ppr->right = pr;
                    }
                    q = pr;
                }
                if (s.isEmpty() == true)
                {
                    ptr = pr;
                }
            }
            delete p;
            return true;
        }
    };
    void RotateL(AVLNode<E, K> *&ptr)
    {
        AVLNode<E, K> *subL = ptr;
        ptr = subL->right;
        subL->right = ptr->left;
        ptr->left = subL;
        ptr->bf = subL->bf = 0;
    };
    void RotateR(AVLNode<E, K> *&ptr)
    {
        AVLNode<E, K> *subR = ptr;
        ptr = subR->left;
        subR->left = ptr->right;
        ptr->right = subR;
        ptr->bf = subR->bf = 0;
    };
    void RotateLR(AVLNode<E, K> *&ptr)
    {
        AVLNode<E, K> *subR = ptr,
                      *subL = subR->left;
        ptr = subL->right;
        subL->right = ptr->left;
        ptr->left = subL;
        if (ptr->bf <= 0)
        {
            subL->bf = 0;
        }
        else
        {
            subL->bf = -1;
        }
        subR->left = ptr->right;
        ptr->right = subR;
        if (ptr->bf == -1)
        {
            subR->bf = 1;
        }
        else
        {
            subR->bf = 0;
        }
        ptr->bf = 0;
    };
    void RotateRL(AVLNode<E, K> *&ptr)
    {
        AVLNode<E, K> *subL = ptr,
                      *subR = subL->right;
        ptr = subR->left;
        subR->left = ptr->right;
        if (ptr->bf >= 0)
        {
            subR->bf = 0;
        }
        else
        {
            subR->bf = 1;
        }
        subL->right = ptr->left;
        ptr->left = subL;
        if (ptr->bf == 1)
        {
            subL->bf = -1;
        }
        else
        {
            subL->bf = 0;
        }
        ptr->bf = 0;
    };
    int Height(AVLNode<E, K> *&ptr) const;

  public:
    AVLTree() : root(NULL) {}
    AVLTree(K ref) : refValue(ref), root(NULL) {}
    bool Insert(E &el)
    {
        return Insert(root, el);
    }
    friend istream &operator>>(istream &in, AVLTree<E, K> &Tree);
    friend ostream &operator>>(istream &out, AVLTree<E, K> &Tree);
    int Height() const;
}