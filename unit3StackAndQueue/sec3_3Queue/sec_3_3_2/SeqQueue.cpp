#include <assert.h>
#include <iostream>
#include "../sec_3_3_1/Queue.cpp"

template <class T>
class SeqQueue : public Queue
{
  public:
	SeqQueue(int sz = 10) : front(0), rear(0), maxSize(sz)
	{
		elements = new T[maxSize];
		assert(elements != NULL);
	};
	~SeqQueue()
	{
		delete[] elements;
	};
	bool EnQueue(const T &x)
	{
		if (IsFull() == true)
		{
			return false;
		}
		elements[rear] = x;
		rear = (rear + 1) % maxSize;
		return true;
	};
	bool DeQueue(T &x)
	{
		if (isEmpty() == true)
		{
			return false;
		}
		x = elements[front];
		front = (front + 1) % maxSize;
		return true;
	};
	bool getFront(T &x);
	void makeEmpty()
	{
		rear = 0;
		front = 0;
	}
	bool isEmpty() const
	{
		if (front == rear)
		{
			return true;
		}
		return false;
	}
	bool isFull() const
	{
		if ((rear + 1) % maxSize == front)
		{
			return true;
		}
		return false;
	};
	int getSize() const
	{ //if rear > front ==> (rear - front) % maxSize else  ((maxSize + rear) - front) % maxSize
		return (rear - front + maxSize) % maxSize;
	};
	friend ostream &operator<<(ostream &os, SeqQueue<T> &Q)
	{
		os << "front = " << Q.front << ", rear = " << Q.rear << endl;
		for (int i = front; i != rear; i = (i + 1) % maxSize)
		{
			os << i << ":" << Q.elements[i] << endl;
		}
		return os;
	};

  protected:
	int rear, front;
	T *elements;
	int maxSize;
}