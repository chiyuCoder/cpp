template <class T>
class Stack
{
  public:
    Stack(){};
    virtual void Push(const T &x);
    virtual bool Pop(T &x);
    virtual bool getTop(T &x);
    virtual bool isEmpty() const;
    virtual int getSize() const;
};

struct Node
{
    long n;
    int tag;
};
//Fibnacci: 0 1 1 2 3 5 8 ...
/**
 * when n==0 || n == 1,
 *      f(n) = n;
 * when n >= 2,
 *      f(n) = f(n - 1) + f(n - 2);
 * 
 * */
long Fibnacci(long n)
{
    Stack<Node> S;
    Node *w;
    long sum = 0;
    do
    {
        while (n > 1)
        {
            w->n = n;
            w->tag = 1;
            S.Push(*w);
            n --;
        }
        sum = sum + n;
        while (S.isEmpty() == false) 
        {
            S.Pop(*w);
            if (w->tag == 1) {
                w->tag = 2;
                S.Push(*w);
                n = w->n-2;
                break;
            }
        }
    } while(S.isEmpty() == false);
};