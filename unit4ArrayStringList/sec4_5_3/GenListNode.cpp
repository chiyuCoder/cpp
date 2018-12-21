template <class T>
class GenListNode
{
  public:
    GenListNode() : utype(0), info.ref(0){}, tlink(NULL);
    GenListNode(GenListNode<T> &RL)
    {
        utype = RL.utype;
        tlink = RL.tlink;
        info = RL.info;
    }

  private:
    int utype;
    GenListNode<T> *tlink;
    union {
        int ref;
        T value;
        GenListNode<T> *hlink;
    } info;
};