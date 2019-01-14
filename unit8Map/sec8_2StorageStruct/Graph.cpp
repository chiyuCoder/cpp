const int defaultVertices = 30;

template <class T, class E>
class Graph
{
  protected:
    int maxVertices;
    int numEdges;
    int numVertices;
    int getVertexPos(T vertex);

  public:
    Graph(int sz = defaultVertices);
    ~Graph();
    bool GraphEmpty() const
    {
        if (numEdges == 0)
        {
            return true;
        }
        return false;
    }
    bool GraphFull() const
    {
        if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
        {
            return true;
        }
        return false;
    }
    int NumberOfVertices()
    {
        return numVertices;
    }
    int NumberOfEdges()
    {
        return numEdges;
    }
    virtual T getValue(int i);
    virtual E getWeight(int vertex1, int vertex2);
    virtual int getFirstNeighbor(int vertex);
    virtual int getNextNeighbor(int vertex1, int vertex2);
    virtual bool insertEdge(int vertex1, int vertex2, E weight);
    virtual bool removeEdge(int vertex1, int vertex2);
    virtual bool insertVertex(const T vertex);
    virtual bool removeVertex(int vertex);
};