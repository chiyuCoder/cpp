const int DefaultSize = 10;
class UFSets
{
  public:
    UFSets(int sz = DefaultSize)
    {
        size = sz;
        parent = new int[size];
        for (int i = 0; i < size; i++)
        {
            parent[i] = -1;
        }
    };
    ~UFSets()
    {
        delete[] parent;
    }
    UFSets &operator=(UFSets &R);
    void Union(int Root1, int Root2) {
        parent[Root1] += parent[Root2];
        parent[Root2] = Root1;
    };
    void WeightedUnion(int Root1, int Root2){
        int r1 = Find(Root1);
        int r2 = Find(Root2),
            temp;
        if (r1 != r2) {
            temp = parent[r1] + parent[r2];
        }
        if (parent[r2] < parent[r1]) {
            parent[r1] = r2;
            parent[r2] = temp;
        } else {
            parent[r2] = r1;
            parent[r1] = temp;
        }
    };
    int CollapsingFind(int i) {
        int parentIndex;
        for (parentIndex = i; parent[parentIndex] >= 0; parentIndex = parent[parentIndex])
        {
        };
        int rootIndex = parentIndex;
        while (i != rootIndex)
        {
            int temp = parent[i];
            parent[i] = rootIndex;
            i = temp;
        }
        return rootIndex;
    }
    int Find(int x)
    {
        while (parent[x] >= 0)
        {
            x = parent[x];
        }
        return x;
    }

  private:
    int *parent;
    int size;
}