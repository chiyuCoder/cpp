const int maxSize = 50;

template <class T>
class Stack{
    public:
        Stack() {};
        virtual void Push(const T& x) = 0;
        virtual bool Pop(T& x) = 0;
        virtual bool getTop(T& x) const = 0;
        virtual bool isEmpty() const = 0;
        virtual int getSize() const = 0;
}