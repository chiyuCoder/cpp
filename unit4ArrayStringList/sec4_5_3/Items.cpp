template <class T>
struct Items{
    int utype;//utype = 0,1,2
    union {
        int ref;//utype=0, 附加头结点, 存储引用计数
        T data;//utype=1
        GenListNode<T> *hlink;//utype=2,
    } info;
    Items() : utype(0), info.ref(0) {};
    Items(Items<T> &RL){
        utype = RL.utype;
        info = RL.info;
    };
};