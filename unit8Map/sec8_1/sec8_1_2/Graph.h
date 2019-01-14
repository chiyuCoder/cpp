template <class T>
class Graph
{
public:
  Graph();
  void insertVertex(const T &vertex);
  void insertEdge(int vertex1, int vertex2, int weight);
  void removeVertex(int vertex);
  void removeEdge(int vertex1, int vertex2);
  bool isEmpty();
  T getWeight(int vertex1, int vertex2);
  int getFirstNeighbor(int vertex);
  int getNextNeighbor(int vertex1, int vertex2);
};