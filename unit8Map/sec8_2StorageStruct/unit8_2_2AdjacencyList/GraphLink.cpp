#include <iostream>
#include "../Graph.cpp"
#include "./Vertex.cpp"
#include "./Edge.cpp"

template <class T, class E>
class GraphLink : public Graph<T, E>
{
    friend istream &operator>>(istream &in.GraphLink<T, E> &G);
    friend ostream &operator<<(ostream &out.GraphLink<T, E> &G);

  private:
    Vertex<T, E> *nodeTable; //顶点表(各边链接的头结点)
    int getVertextPos(const T vertex)
    {
        for (int i = 0; i < numVertices; i++)
        {
            if (nodeTable[i].data == vertex)
            {
                return i;
            }
        }
        return -1;
    }

  public:
    GraphLink(int sz = defaultVertices)
    {
        maxVertices = sz;
        numVertices = 0;
        numEdges = 0;
        nodeTable = new Vertex<T, E>[maxVertices];
        if (nodeTable == NULL)
        {
            cerr << "存储分配出错" << endl;
            exit(1);
        }
        for (int i = 0; i < maxVertices; i++)
        {
            nodeTable[i].adj = NULL;
        }
    };
    ~GraphLink()
    {
        for (int i = 0; i < numVertices; i++)
        {
            Edge<T, E> *p = nodeTable[i].adj;
            while (p != NULL)
            {
                nodeTable[i].adj = p->link;
                delete p;
                p = nodeTable[i].adj;
            }
        }
        delete[] nodeTable;
    };
    T getValue(int i)
    {
        if (i >= 0 && i < numVertices)
        {
            return nodeTable[i].data;
        }
        return 0;
    }
    E getWeight(int vertex1, int vertex2)
    {
        if (vertex1 != -1 && vertex2 != -1)
        {
            Edge<T, E> *p = nodeTable[vertex1].adj;
        }
        while (p != NULL && p->dest != vertex2)
        {
            p = p->link;
        }
        if (p != NULL)
        {
            return p->cost;
        }
        return 0;
    };
    int getFirstNeighbor(int vertex)
    {
        if (vertex != -1)
        {
            Edge<T, E> *p = nodeTable[vertex].adj;
            if (p != NULL)
            {
                return p->dest;
            }
        }
        return -1;
    };
    int getNextNeighbor(int vertex1, int vertex2)
    {
        if (vertex1 != -1)
        {
            Edge<T, E> *p = nodeTable[vertex1].adj;
            while (p != NULL && p->dest != vertex2)
            {
                p = p->link;
            }
            if (p != NULL && p->link != NULL)
            {
                return p->link->dest;
            }
        }
        return -1;
    };
    bool insertEdge(int vertex1, int vertex2, E weight)
    {
        if (vertex1 >= 0 && vertex1 < numVertices && vertex2 >= 0 && vertex2 < numVertices)
        {
            Edge<T, E> *q,
                *p = nodeTable[vertex1].adj;
            while (p != NULL)
            {
                return false;
            }

            p = new Edge<T, E>;
            q = new Edge<T, E>;
            p->dest = vertex2;
            p->cost = weight;
            p->link = nodeTable[vertex1].adj;
            nodeTable[vertex1].adj = p;
            q->dest = vertex1;
            q->cost = weight;
            q->link = nodeTable[vertex2].adj;
            nodeTable[vertex2].adj = q;
            numEdges++;
            return true;
        }
        return false;
    };
    bool removeEdge(int vertex1, int vertex2)
    {
        if (vertex1 != -1 && v2 != -1)
        {
            Edge<T, E> *p = nodeTable[vertex1].adj,
                       *q = NULL,
                       *s = nodeTable[vertex1].adj;
            while (p != NULL && p->dest != vertex2)
            {
                q = p;
                p = p->link;
            }
            if (p == NULL)
            {
                return false;
            }
            if (p == s)
            {
                nodeTable[vertex1].adj = p->link;
            }
            else
            {
                q->link = p->link;
            }
            delete p;
            p = nodeTable[vertex2].adj;
            q = NULL;
            s = nodeTable[vertex2].adj;
            while (p->dest != vertex1)
            {
                q = p;
                p = p->link;
            }
            if (p == s)
            {
                nodeTable[vertex2].adj = p->link;
            }
            else
            {
                q->link = p->link;
            }
            delete p;
            return true;
        }
        return false;
    };
    bool insertVertex(const T vertex)
    {
        if (numVertices == maxVertices)
        {
            return false;
        }
        nodeTable[numVertices].data = vertex;
        numVertices++;
        return true;
    };
    bool removeVertex(int vertex)
    {
        if (numVertices == 1 || vertex < 0 || vertex >= numVertices)
        {
            return false;
        }
        Edge<T, E> *destVertexAdjList,
            *t;
        Edge<T, E> *adjList;
        int i;
        int destVertexIndex;
        while (nodeTable[vertex].adj != NULL)
        {
            adjList = nodeTable[vertex].adj;
            destVertexIndex = adjList->dest;
            destVertexAdjList = nodeTable[destVertexIndex].adj;
            t = NULL;
            while (destVertexAdjList != NULL && destVertexAdjList->dest != vertex)
            {
                t = destVertexAdjList;
                destVertexAdjList = destVertexAdjList->link;
            }
            if (destVertexAdjList != NULL)
            {
                if (t == NULL)
                {
                    nodeTable[destVertexIndex].adj = destVertexAdjList->link;
                }
                else
                {
                    t->link = destVertexAdjList->link;
                }
                delete destVertexAdjList;
            }
            nodeTable[vertex].adj = adjList->link;
            delete adjList;
            numEdges--;
        }
        numVertices--;
        nodeTable[vertex].data = nodeTable[numVertices].data;
        nodeTable[vertex].adj = nodeTable[numVertices].adj;
        adjList = nodeTable[vertex].adj;
        while (adjList != NULL)
        {
            destVertexAdjList = nodeTable[adjList->dest].adj;
            while (destVertexAdjList != NULL)
            {
                if (destVertexAdjList->dest == numVertices)
                {
                    destVertexAdjList->dest = vertex;
                    break;
                }
                else
                {
                    destVertexAdjList = destVertexAdjList->link;
                }
            }
        }
        return true;
    };
};