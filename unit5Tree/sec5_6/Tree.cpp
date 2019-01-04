#include "./TreeNode.cpp"

template <class T>
class Tree
{
  private:
    TreeNode<T> *root, *current;
    bool Find(TreeNode<T> *p, T value){
        bool result = false;
        if (p->data == value) {
            result = true;
            current = p;
        } else {
            TreeNode<T> *q = p->firstChild;
            while(q != NULL && !result) {
                result = Find(q, value);
                q = q->nextSibling;
            }
        }
        return result;
    };
    void RemoveSubTree(TreeNode<T> *p);
    bool FindParent(TreeNode<T> *t, TreeNode<T> *p)
    {
        TreeNode<T> *q = t->firstChild;
        bool success;
        while (q != NULL && q != p)
        {
            success = FindParent(q, p);
            if (success)
            {
                return true;
            }
            q = q->nextSibling;
        }
        if (q != NULL && q == p)
        {
            current = t;
            return true;
        }
        current = NULL;
        return false;
    };

  public:
    Tree()
    {
        root = current = NULL;
    }
    bool Root()
    { //让树的根结点为树的当前结点
        if (root == NULL)
        {
            current = NULL;
            return false;
        }
        current = root;
        return true;
    };
    bool IsEmpty()
    {
        return root == NULL;
    }
    bool FirstChild()
    {
        if (current != NULL && current->firstChild != NULL)
        {
            current = current->firstChild;
            return true;
        }
        current = NULL;
        return false;
    };
    bool NextSibling()
    {
        if (current != NULL && current->nextSibling != NULL)
        {
            current = current->nextSibling;
            return true;
        }
        current = NULL;
        return false;
    };
    bool Parent()
    {
        TreeNode<T> *p = current;
        if (current == NULL || current == root)
        {
            current = NULL;
            return false;
        }
        return FindParent(root, p);
    };
    bool Find(T target) {
        if (IsEmpty()) {
            return false;
        }
        return Find(root, value);
    };
    //...
};