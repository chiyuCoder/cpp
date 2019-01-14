#include "../sec8_"

template <class T, class E>
void ShortestPath(Graph<T, E> &G, T v, E dist[], int path[])
{
    int n = G.NumberOfVertices();
    bool *S = new bool[n];
    int i,
        j,
        k;
    E w,
        min;
    for (i = 0; i < n; i++)
    {
        dist[i] = G.get
    }
}