#include <iostream>
#include <stdlib.h>
#include "../sec2_1_2/LinearList.h"
const int defaultSize = 100;
template <class T>
class SeqList : public LinearList<T>
{
  protected:
	T *data;
	int maxSize;
	int last;
	void reSize(int newSize);

  public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T> &L);
	~SeqList()
	{
		delete[] data;
	}
	int Size() const
	{
		return maxSize;
	}
	int Search(T &x) const;
	int Locate(int i) const;
	T *getData(int i) const
	{
		if (i > 0 && i < last + 1) {
			return &data[i - 1];
		}
		return NULL;
	}
	void setData(int i, T& x) {
		if (i > 0 && i < last + 1) {
			data[i + 1] = x;
		}
	}
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty() {
		if (last === -1) {
			return true;
		}
		return false;
	}
	bool IsFull() {
		if (last === maxSize - 1) {
			return true;
		}
		return false;
	}
	void input();
	void output();
	SeqList<T> operator=(SeqList<T>& L);
}