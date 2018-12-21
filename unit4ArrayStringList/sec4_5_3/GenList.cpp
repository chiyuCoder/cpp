template <class T>
class GenList
{
  public:
    GenList();
    ~GenList();
    bool Head(items &x);
    bool Tail(GenList<T> &x);
    GenListNode<T> *First();
    GenListNode<T> *Next(GenListNode<T> *elem);
    void Copy(const GenList<T> *R);
    int Length();
    int Depth();
    friend istream &operator<<(istram &s, GenList<T> &L);

  private:
    GenListNode<T> *first;
    GenListNode<T> *Copy(GenListNode<T> *ls); // 复制一个ls 指示的无共享非递归表
    int Length(GenListNode<T> *ls);           //求由ls 指示的广义表的长度
    int depth(GenListNode<T> *ls);            //
    bool equal(GenListNode<T> *s, GenListNode<T> *t);
    void Remove(GenListNode<T> *ls);
    void CreateList(istream &in, GenListNode<T> *&ls);//从输入流对象输入广义表的字符串描述， 建立一个带附加头结点的广义表结构
};