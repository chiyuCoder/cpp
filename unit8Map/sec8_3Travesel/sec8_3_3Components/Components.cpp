#include "../sec8_3_1DepthFirstSearch/DepthFirstSearch.cpp"

template <class T, class E>
void Components(Graph<T, E> &G)
{
    int i,
        n = G.NumberOfVertices();
    bool *visited = new bool[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            DepthFirstSearch(G, i, visited);
            OutputNewComponent();
        }
    }
    delete[] visited;
}