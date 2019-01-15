#include "../sec8_2StorageStruct/Graph.cpp"
const int maxValue = 999999999999; //
template <class T, class E>
void ShortestPath(Graph<T, E> &graph, T startVertex, E dist[], int path[])
{
    //dist startVertex与各点直接连接的路径
    //path startVertext与各点的最短路径
    int verticesNum = graph.NumberOfVertices();
    bool *S = new bool[verticesNum];
    int i,
        j,
        k;
    E weight,
        min;
    for (i = 0; i < verticesNum; i++)
    {
        dist[i] = graph.getWeight(startVertex, i);
        S[i] = false;
        if (i != startVertex && dist[i] < maxValue)
        {
            path[i] = startVertex;
        }
        else
        {
            path[i] = -1;
        }
    }
    S[startVertex] = true;
    dist[startVertex] = 0;
    for (i = 0; i < verticesNum - 1; i++)
    {
        min = maxValue;
        int u = startVertex;
        for (j = 0; j < verticesNum; j++)
        {
            if (S[j] == false && dist[j] < min)
            {
                u = j;
                min = dist[j];
            }
        }
        S[u] = true;
        for (k = 0; k < verticesNum; k++)
        {
            weight = graph.getWeight(u, k);
            if (S[k] == false && weight < maxValue && dist[u] + weight < dist[k])
            {
                dist[k] = dist[u] + weight;
                path[k] = u;
            }
        }
    }
}