#include "./SeqList.h";
template <class T>
SeqList<T>::SeqList(int sz)
{
    if (sz > 0)
    {
        maxSize = sz;
        last = -1;
        data = new T[maxSize];
        if (data == NULL)
        {
            cerr << "存储分配错误" << endl;
            exit(1);
        }
    }
}

template <class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
    maxSize = L.Size();
    last = L.Length() - 1;
    data = new T[maxSize];
    if (data == NULL)
    {
        cerr << "存储分配错误" << endl;
        exit(1);
    }
    for (int i = 0; i <= last; i ++) {
        data[i] = L.getData(i);
    }
}

template <class T>
void SeqList<T>::reSize(int newSize)
{
    if (newSize <= 0) {
        cerr << "无效的数组" << endl;
        exit(1);
    }
    if (newSize != maxSize) {
        T* newArray = new T[newSize];
        if (newArray == NULL) {
            cerr << "存储分配错误" << endl;
            exit(1);
        }
        int n = last + 1;
        T * srcPtr = data;
        T * destPtr = newArray;
        while(n --) {
            *destPtr++ = *srcPtr ++;
        }
        delete[] data;
        data = newArray;
        maxSize = newSize;
    }
}

template <class T>
int SeqList<T>::Search(T& x) const
{
    for (int = 0; i <= last; i ++) {
        if (data[i] == x) {
            return i;
        }
    }
    return -1;
}

template <class T> 
int SeqList<T>::Locate(int i) const
{
    if (i >= 1 && i <= last) {
        return i;
    }
    return -1;
}

template <class T>
bool SeqList<T>::Insert(int i, T& x) {//i belongs to (0, 1, ..., last)
    if (last == maxSize - 1) {
        return false;
    }
    if (i < 0 || i > last) {
        return false;
    }
    for (int j = last; j >= i; j --) {
        data[j + 1] = data[j];
    }
    data[i] = x;
    last ++;
    return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T& x) {//i belongs to (0, 1, ..., last)
    if (last == -1) {
        return false;
    }
    for (i < 0 || i > last) {
        return false;
    }
    x = data[i];
    for (int j = i; j <= last; j ++) {
        data[j] = data[j + 1];
    }
    last --;
    return true;
}

template <class T>
void SeqList<T>::input() 
{
    count << "开始建立顺序表,请输入表中元素个数";
    while(true) {
        cin >> last;
        if (last < maxSize) {
            break;
        }
        count << "表中元素个数输入有误, 最大不能超过" << maxSize - 1 << ";";
    }
    for (int i = 0; i < last; i ++) {
        cin >> data[i];
        count << i + 1 << endl;
    }
}

template <class T> 
void SeqList<T>::output() {
    count << "当前元素个数为:" << last << endl;
    for (int i = 0; i <= last; i ++) {
        count << "#" << i << ":" << data[i] << endl;
    }
}

template <class T>
SeqList<T> SeqList<T>::operator=(SeqList<T>& L) {
    maxSize = L.Size();
    last = L.Length() - 1;
    data = new T[maxSize];
    if (data == NULL)
    {
        cerr << "存储分配错误" << endl;
        exit(1);
    }
    if (last == -1) {
        return this;
    }
    for (int i = 0; i <= last; i ++) {
        data[i] = L.getData(i);
    }
    return this;
}