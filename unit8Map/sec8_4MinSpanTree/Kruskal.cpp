#include "../../unit5Tree/sec5_8Heap/MinHeap.cpp"
#include "../../unit6Set/sec6_2/sec6_2_1/UFSets.cpp"
#include "../MSTEdgeNode.cpp"
template <class T, class E>
void Kruskal(Graph<T, E> &G, MinSpanTree<T, E> &MST)
{
    MSTEdgeNode<T, E> ed;
    int u, v, count;
    int n = G.NumberOfVertices();
    int m = G.NumberOfEdges();

    MinHeap<E, MSTEdgeNode<T, E>> H(m);
    UFSets F(n);
    for (u = 0; u < n; u++)
    {
        for (v = u + 1; v < n; v++)
        {
            if (G.getWeight(u, v) != maxValue)
            {
                ed.tail = u;
                ed.head = v;
                ed.key = G.getWeight(u, v);
                H.insert(ed);
            }
        }
    }
    count = 1;
    while (count < n)
    {
        H.RemoveMin(ed);
        u = F.Find(ed.tail);
        v = F.Find(ed.head);
        if (u != v)
        {
            F.Union(u, v);
            MST.Insert(ed);
            count++;
        }
    }
}