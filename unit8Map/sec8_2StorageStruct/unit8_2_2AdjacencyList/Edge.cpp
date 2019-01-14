template <class T, class E>
struct Edge
{
    int dest;
    E cost;
    Edge<T, E> *link;
    Edge(){};
    Edge(int num, E weight) : dest(num), cost(weight), link(NULL) {}
    bool operator!=(Edge<T, E> &R) const
    {
        if (dest != R.dest)
        {
            return true;
        }
        return false;
    }
}