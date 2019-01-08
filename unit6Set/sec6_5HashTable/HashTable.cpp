enum KindOfStatus
{
    Active,
    Empty,
    Deleted
};
template <class E, class K>
class HashTable
{
  private:
    int divitor;        //散列函数的除数
    int CurrentSize,    //当前桶数
        TableSize;      //最大桶数
    E *ht;              //散列表存储数组
    KindOfStatus *info; //状态数组
    int FindPos(const K k1) const
    {
        //计算初始桶号
        int i = k1 % divitor;
        int j = i;
        do
        {
            if (
                info[j] == Empty ||
                (info[j] == Active && ht[j] == k1))
            {
                return j;
            }
            j = (j + 1) % TableSize;
        } while (j != i);
        return j;
    };
    int FindPos2(const K k1){
        //二次探查法下的FindPos
        int i = k1 % divitor;
        int k = 0,
            odd = 0,
            save;
        while (info[i] == Active && ht[i] != k1) {
            if (odd == 0) {
                k++;
                save = i;
                i = (i + 2 * k - 1) % TableSize;
                odd = 1;
            } else {
                i = (save - 2 * k + 1) % TableSize;
                odd = 0;
                if (i < 0) {
                    i = i + TableSize;
                }
            }

        }
        return i;
    }
    int operator==(E &e1)
    {
        return *this == el;
    }
  public
    operator!=(E &e1)
    {
        return *this != e1;
    }

  public:
    HashTable(const int d, int sz = DefaultSize)
    {
        divitor = d;
        TableSize = sz;
        CurrentSize - 0;
        ht = new E[TableSize];
        info = new KindOfStatus[TableSize];
        for (int i = 0; i < TableSize; i++)
        {
            info[i] = Empty;
        }
    };
    ~HashTable()
    {
        delete[] ht;
        delete[] info;
    }
    HashTable<E, K> &operator=(const HashTable<E, K> &ht2) {
        if (this != &ht2) {
            delete[] ht;
            delete[] info;
            TableSize = ht2.TableSize;
            ht = new E[TableSize];
            info = new KindOfStatus[TableSize];
            for (int i = 0; i < TableSize; i ++) {
                ht[i] = ht2.ht[i];
                info[i] = ht2.info[i];
            }
            CurrentSize = ht2.CurrentSize;
        }
        return *this;
    };
    bool Search(const K k1, E &e1) {
        int i = FindPos(k1);
        if (info[i] != Active || ht[i] != k1) {
            return false;
        }
        e1 = ht[i];
        return true;
    }
    bool Insert(const E &e1) {
        K k1 = e1;
        int i = FindPos(k1);
        if (info[i] != Active) {
            ht[i] = e1;
            info[i] = Active;
            CurrentSize++;
            return true;
        }
        if (info[i] == Active && ht[i] == e1) {
            return false;//已插入
        }
        return false; //表已满
    };
    bool Insert2(const E& e1) {
        //二次探查法下的Insert
        K k1 = e1;
        int i = FindPos(k1),
            j,
            k;
        if (info[i] == Active) {
            return false;
        }
        ht[i] = e1;
        info[i] = Active;
        if ( ++ CurrentSize < TableSize / 2) {
            return true;
        }
        E *oldHt = ht;
        KindOfStatus *oldInfo = info;
        int oldTableSize = TableSize;
        CurrentSize = 0;
        TableSize = NextPrime(2 * oldTableSize);
        divitor = TableSize;
        ht = new E[TableSize];
        if (ht == NULL) {
            cerr << "存储分配失败" << endl;
            return false;
        }
        info = new KindOfStatus[TableSize];
        if (info == NULL) {
            cerr << "存储分配失败" << endl;
            return false;
        }
        for (j = 0; j < TableSize; j ++) {
            info[j] = Empty;
        }
        for (i = 0; i < TableSize; i ++) {
            if (oldInfo[i] == Active) {
                Insert(oldHt[i]);
            }
        }
        delete[] oldHt;
        delete[] oldInfo;
        return true;
    }
    int NextPrime(int n) {
        if ( n % 2 == 0) {
            n++;
        }
        for (; !IsPrime(n); n == 2)
        {
        }
        return n;
    }
    int IsPrime(int n) {//是否是质数
        for (int i = 3; i * i <= n; i += 2) {
            if(n % i == 0) {
                return 0;
            }
            
        }
        return 1;
    }
    bool Remove(const K k1, E &e1) {
        int i = FindPos(k1);
        if (info[i] == Active) {
            info[i] = Deleted;
            CurrentSize--;
            return true;
        }
        return false;
    };
    void makeEmpty() {
        for (int i = 0; i < TableSize; i ++)
        {
            info[i] = Empty;
        }
        CurrentSize = 0;
    };

}