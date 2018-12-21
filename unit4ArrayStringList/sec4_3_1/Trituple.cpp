template <class T>
struct Trituple{
    public:
        int row,col;
        T value;
        Trituple<T> *operator=(Trituple<T> &x) {
            row = x.row;
            col = x.col;
            value = x.value;
        };
};