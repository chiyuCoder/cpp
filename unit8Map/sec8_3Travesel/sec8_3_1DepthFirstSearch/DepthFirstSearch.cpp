#include "../../sec8_2StorageStruct/Graph.cpp"

template <class T, class E>
void DepthFirstSearch(Graph<T, E> &G, const T &v)
{
    int i,
        loc,
        n = G.NumberOfVertices();
    bool *visited = new bool[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    loc = G.getVertexPos(v);
    DepthFirstSearch(G, loc, visited);
    delete[] visited;
}

template <class T, class E>
void DepthFirstSearch(Graph<T, E> &G, int v, bool visited[])
{
    cout << G.getValue(v);
    visited[v] = true;
    int w = G.getFirstNeighbor(v);
    while (w != -1)
    {
        if (visited[w] == false)
        {
            DepthFirstSearch(G, w, visited);
        }
        w = G.getNextNeighbor(v, w);
    }
};