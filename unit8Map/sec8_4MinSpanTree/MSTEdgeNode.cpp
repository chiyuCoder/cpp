const float maxValue = 0.9999999999999999999999999; //FLOAT_MAX;

template <class T, class E>
struct MSTEdgeNode
{
    int tail,
        head;
    E key;
    MSTEdgeNode() : tail(-1), head(-1), key(0) {}
}
