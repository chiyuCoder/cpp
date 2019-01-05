#include <assert.h>
#include <iostream>
const int DefaultSize = 50;
template <class T>
class bitSet{
    public:
      bitSet(int sz = DefaultSize): setSize(sz) {
          assert(setSize > 0);
          vectorSize = (setSize + 15) >> 4;
          bitVector = new int[vectorSize];
          assert(bitVector != NULL);
          for (int i = 0; i < vectorSize; i ++) {
              bitVector[i] = 0;
          }
      };
      bitSet(const bitSet<T> &R){
          setSize = R.setSize;
          vectorSize = R.vectorSize;
          bitVector = new int[vectorSize];
          assert(bitVector != NULL);
          for (int i = 0; i < vectorSize; i ++)
          {
              bitVector[i] = R.bitVector[i];
          }
      };
      ~bitSet() {
          delete[] bitVector;
      }
      void makeEmpty() {
          for (int i = 0; i < vectorSize; i ++) {
              bitVector[i] = 0;
          }
      }
      int getMember(const T x) {//读取集合元素x, x从0开始
          int ad = x / 16,
              id = x % 16;//计算数组元素下标
          unsigned short elm = bitVector[ad];//取x所在数组元素
          return int((elm >> (5 - id)) & 1);//取第id位的值
      };//读取集合元素x
      void putMember(const T x, int v) {
          int ad = x / 16,
              id = x % 16; //计算数组元素下标
          unsigned short elm = bitVector[ad];
          unsigned short temp = elm >> (15 - id);
          elm = elm << (id + 1);
          if(temp%2 == 0 && v == 1) {
              temp = temp + 1;
          } else if(temp % 2 == 1 && v==0) {
              temp = temp - 1;
          }
          bitVector[ad] = (temp << (15 - id) || (elm >> (id + 1)));
      };//将值v 送入集合元素x
      bool addMember(const T x) {
          assert(x >= 0 && x < setSize);
          if (getMember(x) == 0) {
              putMember(x, 1);
              return true;
          }
          return false;
      };//
      bool delMember(const T x) {
          assert(x >= 0 && x < setSize);
          if (getMember(x) == 1) {
              putMember(x, 0);
              return true;
          }
          return false;
      };
      bitSet<T> &operator=(const bitSet<T> &R);
      bitSet<T> operator+(const bitSet<T> &R) {
          assert(vectorSize == R.vectorSize);
          set temp(vectorSize);
          for (int i = 0; i < vectorSize; i ++) {
              temp.bitVector[i] = bitVector[i] | R.bitVector[i];
          }
          return temp;
      };//并集
      bitSet<T> operator-(const bitSet<T> &R) {
          assert(vectorSize == R.vectorSize);
          set temp(vectorSize);
          for (int i = 0; i < vectorSize; i++)
          {
              temp.bitVector[i] = bitVector[i] & !R.bitVector[i];
          }
          return temp;
      };//差集
      bitSet<T> operator*(const bitSet<T> &R){
          assert(vectorSize == R.vectorSize);
          set temp(vectorSize);
          for (int i = 0; i < vectorSize; i++)
          {
              temp.bitVector[i] = bitVector[i] & R.bitVector[i];
          }
          return temp;
      };//交集
      bool Contains(const T x) {
          assert(x >= 0 && x <= setSize);
          return (getMember(x) == 1) ? true : false;
      };
      bool operator==(bitSet<T> &R) {
          if (vectorSize != R.vectorSize){
              return false;
          }
          for (int i = 0; i < vectorSize; i++)
          {
              if (bitVector[i]!=R.bitVector[i])
              {
                  return false;
              }
          }
          return true;
      };
      friend istream& operator>>(istream& in, bitSet<T>& R);
      friend ostream& operator>>(ostream& out, bitSet<T>& R);
      bool subSet(bitSet<T> & R) {
          assert(setSize == R.setSize);
          for (int i = 0; i < vectorSize; i ++) {
              if (bitVector[i] & !R.bitVector[i]) {
                  return false;
              }
          }
          return true;
      }
    private:
      int setSize;
      int vectorSize;//位数组大小
      unsigned short *bitVector;//存储集合元素的位数组
};