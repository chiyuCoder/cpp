#include "../sec8_2StorageStruct/Graph.cpp"

template <class T, class E>
void CriticalPath(Graph<T, E> &graph)
{
    int i;
    int j;
    int k;
    E Ae,
        Al,
        w;
    int verticesNum = graph.NumberOfVertices();
    E *Ve = new E[verticesNum];
    E *Vl = new E[verticesNum];
    for (i = 0; i < verticesNum; i++)
    {
        Ve[i] = 0;
    }
    for (i = 0; i < verticesNum; i++)
    {
        j = graph.getFirstNeighbor(i);
        while (j != -1)
        {
            w = graph.getWeight(i, j);
            if (Ve[i] + w > Ve[j])
            {
                Ve[j] = Ve[i] + w;
            }
            j = graph.getNextNeighbor(i, j);
        }
    }
    Vl[verticesNum - 1] = Ve[verticesNum - 1];
    for (j = verticesNum - 2; j > 0; j--)
    {
        k = graph.getFirstNeighbor(j);
        while (k != -1)
        {
            w = graph.getWeight(j, k);
            if (Vl[k] - w < Vl[j])
            {
                Vl[j] = Wl[k] - w;
            }
            k = graph.getWeight(j, k);
        }
    }
    for (i = 0; i < verticesNum; i++)
    {
        j = graph.getFirstNeighbor(i);
        while (j != -1)
        {
            Ae = Ve[i];
            Al = Vl[k] - graph.getWeight(i, j);
            if (Al == Ae)
            {
                cout << "<" << graph.getValue(i) << ", " << graph.getValue(j) << ">"
                     << "是关键活动"
                     << endl;
            }
            j = graph.getNextNeighbor(i, j);
        }
    }
    delete[] Ve;
    delete[] Vl;
}