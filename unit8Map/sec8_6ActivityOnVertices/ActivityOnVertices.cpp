#include "../sec8_2StorageStruct/Graph.cpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <class T, class E>
void TopologicalSort(Graph<T, E> &graph)
{
    int i, j, w, vertex;
    int top = -1;
    int verticesNum = graph.NumberOfVertices();
    int *count = new int[verticesNum]; //入度数组兼入度为零的顶点栈
    for (i = 0; i < verticesNum; i++)
    {
        count[i] = 0;
    }
    cin >> i >> j;
    while (i > -1 && i < verticesNum && j > -1 && j < verticesNum)
    {
        graph.insertEdge(i, j);
        count[j]++;
        cin >> i >> j;
    }
    for (i = 0; i < n; i++)
    {
        if (count[i] == 0)
        {
            count[i] = top;
            top = i;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (top == -1)
        {
            return;
        }
        vertex = top;
        top = count[top];
        cout << graph.getValue(vertex) << endl;
        w = graph.getFirstNeighbor(vertex);
        while (w != -1)
        {
            count[w]--;
            if (count[w] == 0)
            {
                count[w] = top;
                top = w;
            }
            w = graph.getNextNeighbor(v, w);
        }
    }
}