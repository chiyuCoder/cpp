template <class T>
class Tree
{
  public:
    Tree();
    ~Tree();
    position Root();
    buildRoot(const T &value);
    position FirstChild(position p);
    position NextSibling(position p);
    position Parent(position p);
    T getData(position p);
    bool InsertChild(const position p, const T &value);
    void DeleteSubTree(position t);
    bool IsEmpty();
    //遍历, visit 是用户自编的访问结点p数据的函数
    void Traversal(void (*visit)(position p));
}