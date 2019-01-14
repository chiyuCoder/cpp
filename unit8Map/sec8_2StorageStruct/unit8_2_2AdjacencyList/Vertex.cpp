#include "./Edge.cpp"

template <class T, class E>
struct Vertex
{
    T data;
    Edge<T, E> *adj;
}