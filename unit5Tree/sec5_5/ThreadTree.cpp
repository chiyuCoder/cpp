#include "./ThreadNode.cpp"

template <class T>
class ThreadTree
{
  protected:
    ThreadNode<T> *root;
    void createInThread(ThreadNode<T> *current, ThreadNode<T> *&pre)
    {
        if (current == NULL)
        {
            return;
        }
        createInThread(current->leftChild, pre);
        if (current->leftChild == NULL)
        {
            current->leftChild = pre;
            current->lTag = 1;
        }
        if (pre != NULL && pre->rightChild == NULL)
        {
            pre->rightChild = current;
            pre->rTag = 1;
        }
        pre = current;
        createInThread(current->rightChild, pre);
    };

  public:
    ThreadNode() : root(NULL){};
    void createInThread()
    {
        ThreadNode<T> *pre = NULL;
        if (root != NULL)
        {
            createInThread(root, pre);
            pre->rightChild = NULL;
            pre->rTag = 1;
        }
    };
    /**
     * 
     * 函数返回以*current为根的中序线索二叉树中中序序列下的第一个结点
     * 
     * 当前结点在中序序列下的前驱结点
     * while ltag == 0 && leftChild != NULL, then 前驱为当前结点左子树中序下的最后一个结点
     * while ltag == 1 && leftChild != NULL, then 前驱为左子女结点
     * while ltag == 1 && leftChild == NULL, then 无前驱
     */
    ThreadNode<T> *First(ThreadNode<T> *current)
    {
        ThreadNode<T> *p = current;
        while (p->tag == 0)
        {
            p = p->leftChild;
        }
        return p;
    };
    /**
     * 函数返回以*current 为根的中序线索二叉树中中序序列下的最后一个结点
     * */
    ThreadNode<T> *Last(ThreadNode<T> *current)
    {
        ThreadNode<T> *p = current;
        while (p->rTag == 0)
        {
            p = p->rightChild; //最右下结点(不一定是叶结点)
        }
        return p;
    };
    /**
     * 
     * 函数返回在中序线索二叉树中结点current在中序下的后继结点
     * while rTag == 0 && rightChild != NULL,then 后继为当前结点右子树的中序下的第一个结点
     * while rTag == 1 && leftChild != NULL, the 前驱为右子女结点
     * */
    ThreadNode<T> *Next(ThreadNode<T> *current)
    {
        ThreadNode<T> *p = current->rightChild;
        if (current->rTag == 0)
        {
            return First(p);
        }
        return p;
    };
    /**
     * @return 在中序线索二叉树中结点current在中序下的前驱结点
     * 
     * */
    ThreadNode<T> *Prior(ThreadNode<T> *current)
    {
        ThreadNode<T> *p = current->leftChild;
        if (current->lTag == 0)
        {
            return Last(p); //在左子树中找中序最后一个结点
        }
        return p;
    };
    void InOrder(void (*visit)(ThreadNode<T> *p))
    {
        ThreadNode<T> *p;
        for (p = First(root); p != NULL; p = Next(p))
        {
            visit(p);
        }
    };
    void PreOrder(void (*visit)(ThreadNode<T> *p))
    {
        ThreadNode<T> *p = root;
        while (p != NULL)
        {
            visit(p);
            if (p->lTag == 0)
            {
                p = p->leftChild;
            }
            else
            {
                if (p->rTag == 0)
                {
                    p = p->rightChild;
                }
                else
                {
                    while (p != NULL && p->rTag == 1)
                    {
                        p->rightChild;
                    }
                    if (p != NULL)
                    {
                        p = p->rightChild;
                    }
                }
            }
        }
    };
    void PostOrder(void (*visit)(ThreadNode<T> *p)) {
        ThreadNode<T> *t = root;
        while(t->lTag == 0 || t->rTag == 0) {
            if (t->lTag == 0) {
                r = t->leftChild;
            } else {
                if (r->rTag == 0) {
                    t = t->rightChild;
                }
            }
        }
        visit(p);
        ThreadNode<T> *p;
        while((p = parent(t)) != NULL) {
           if (p->rightChild == t || p->rTag == 1) {
               t = p;
           } else {
               t = p->rightChild;
               while(t->lTag == 0 || t->rTag == 0) {
                   if (t->lTag == 0)  {
                       t = t->leftChild;
                   } else if(t->rTag == 0) {
                       t = t->rightChild;
                   }
               }
           }
           visit(t);
        }
    };
    ThreadNode<T> *parent(ThreadNode<T> *t) {
        ThreadNode<T> *p;
        if (t == root) {
            return NULL;
        }
        for (p = t; p->lTag == 0; p = p->leftChild);
        if(p->leftChild != NULL) {
            for (p = p->leftChild; p != NULL && p->leftChild != t && p->rightChild != t; p=p->rightChild);

        }
        if (p == NULL || p->leftChild == NULL) {
            for (p = t; p->rTag == 0; p = p->rightChild);
            for (
                p = p->rightChild;
                p != NULL && p->leftChild != t && p->rightChild != t; 
                p= p->leftChild)
                ;
        }
        return p;
    }
    //.....
}