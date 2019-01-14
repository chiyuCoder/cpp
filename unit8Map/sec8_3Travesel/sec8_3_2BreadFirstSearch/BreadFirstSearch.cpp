#include "../../sec8_2StorageStruct/Graph.cpp"
#include "../../../unit3StackAndQueue/sec3_3Queue/sec_3_3_1/Queue.cpp"
template <class T, class E>
void BreadFirstSearch(Graph<T, E> &G, const T &v)
{
    int i,
        w,
        n = G.NumberOfVertices();
    bool *visited = new bool[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int loc = G.getVertexPos(v);
    visited[loc] = true;
    Queue<int> Q;
    Q.EnQueue(loc);
    while (!Q.IsEmpty())
    {
        Q.DeQueue(loc);
        w = G.getFirstNeighbor(loc);
        while (w != -1)
        {
            if (visited[w] == false)
            {
                cout << G.getValue(w) << ' ';
                visited[w] = true;
                Q.EnQueue(w);
            }
            w = G.getNextNeighbor(loc, w);
        }
    }
    delete[] visited;
}