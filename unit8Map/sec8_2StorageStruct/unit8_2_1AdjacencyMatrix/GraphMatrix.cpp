#include "../Graph.cpp"
#include <iostream>
const int maxWeight = 9999; //
template <class T, class E>
class GraphMatrix : public Graph<T, E>
{
    friend istream &operator>>(istream &in, GraphMatrix<T, E> &G);
    friend ostream &operator<<(ostream &out, GraphMatrix<T, E> &G);

  private:
    T *verticesList;
    E **edge;
    int getVertexPos(T vertex)
    {
        for (int i = 0; i < numVertices; i++)
        {
            if (verticesList[i] == vertex)
            {
                return i;
            }
        }
        return -1;
    }

  public:
    GraphMatrix(int sz = defaultVertices)
    {
        maxVertices = sz;
        numVertices = 0;
        numEdges = 0;
        int i,
            j;
        edge = (int **)new int *[maxVertices];
        for (i = 0; i < maxVertices; i++)
        {
            edge[i] = new int[maxVertices];
        }
        for (i = 0; i < maxVertices; i++)
        {
            for (j = 0; k < maxVertices; j++)
            {
                edge[i][j] = (i == j) ? 0 : maxWeight;
            }
        }
    };
    ~GraphMatrix()
    {
        delete[] verticesList;
        delete[] edge;
    }
    T getValue(int i)
    {
        if (i >= 0 && i <= numVertices)
        {
            return verticesList[i];
        }
        return NULL;
    }
    E getWeight(int vertex1, int vertex2)
    {
        if (vertex1 != -1 && vertex2 != -1)
        {
            return edge[vertex1][vertex2];
        }
        return 0;
    }
    virtual int getFirstNeighbor(int vertex)
    {
        if (vertex != -1)
        {
            for (int col = 0; col < numVertices; col++)
            {
                if (edge[vertex][col] > 0 && edge[vertex][col] < maxWeight)
                {
                    return col;
                }
            }
        }
        return -1;
    };
    virtual int getNextNeighbor(int vertex1, int vertex2)
    {
        if (vertex1 != -1 && vertex2 != -1)
        {
            for (int col = vertex2 + 1; col <= numVertices; col++)
            {
                if (edge[vertex1][col] > 0 && edge[vertex1][col] < maxWeight)
                {
                    return col;
                }
            }
        }
        return -1;
    };
    virtual bool insertVertex(const T &vertex)
    {
        if (numVertices == maxVertices)
        {
            return false;
        }
        verticesList[numVertices + 1] = vertex;
        return true;
    };
    virtual bool removeVertex(int vertex)
    {
        if (vertex < 0 || vertex >= numVertices)
        {
            return false;
        }
        if (numVertices == 1)
        {
            return false;
        }
        int i,
            j;
        verticesList[vertex] = verticesList[numVertices - 1];
        for (i = 0; i < numVertices; i++)
        {
            if (edge[i][vertex] > 0 && edge[i][vertex] < maxWeight)
            {
                numEdges--;
            }
        }
        for (i = 0; i < numVertices; i++)
        {
            edge[i][vertex] = edge[i][numEdges - 1];
        }
        numVertices--;
        for (j = 0; j < numVertices; j++)
        {
            edge[vertex][j] = edge[numVertices][j];
        }
        return true;
    };
    virtual bool insertEdge(int vertex1, int vertex2, E weight)
    {
        if (vertex1 > -1 && vertex1 < numVertices && vertex2 > -1 && vertex2 < numVertices && edge[vertex1][vertex2] == maxWeight)
        {
            edge[vertex1][vertex2] = edge[vertex2][vertex1] = weight;
            numEdges++;
            return true;
        }
        return false;
    };
    virtual bool removeEdge(int vertex1, int vertex2)
    {
        if (vertex1 > -1 && vertex1 < maxWeight && vertex2 > -1 && vertex2 < maxWeight && edge[vertex1][vertex2] > 0 && edge[vertex1][vertex2] < maxWeight)
        {
            edge[vertex1][vertex2] = edge[vertex2][vertex1] = maxWeight;
            numEdges--;
            return true;
        }
        return false;
    };
}