#include <iostream>
#include "./CircleList.cpp";
/**
 * 约瑟夫问题的提法是： 
 * 一个旅行社要从n 个旅客中选出一名旅客， 
 * 为他提供免费的环球旅行服务。
 * 旅行社安排这些旅客围成一个圆圈， 
 * 从帽子中取出一张纸条，
 * 用上面写的正整数m (< n ) 作为报数值。
 * 
 * 游戏进行时， 
 * 从第一个人开始按顺时针方向自1 开始顺序报数， 
 * 报到m 时停止报数， 
 * 报m 的入被淘汰出列， 
 * 然后从他顺时针方向上的下一个入开始重新报数， 
 * 如此下去，
 * 直到圆圈中只剩下一个人， 
 * 这个最后的幸存者就是游戏的胜利者，
 * 将得到免费旅行的奖励。
 * 
 * 例如， 
 * 若n = 8 , m = 3 , 
 * 则出列的顺序将为3 , 6 , 1 , 5 , 2 , 8 , 4 , 
 * 最初编号为7 的旅客将赢得环球旅游的机会
 * 
 * */
using std::cout;
using std::cin;
template <class T>
void Josephus(CircleList<T>& Js, int n, int m)
{
    CircleLinkNode<T> *p = Js.getHead(),
        *pre = NULL;
    int i, j;
    for (i = 0; i < n - 1; i ++) {
        for (j = 1; j < m; j ++) {
            pre = p;
            p = p->link;
        }
        cout << "出列的人是" << p->data << endl;
        pre->link = p->link;
        delete p;
        p = pre->link;
    }   

}
void main() {
    CircleList<int> clist;
    int i, n, m;
    cout << "输入游戏者人数和报数间隔:";
    cin >> n >> m;
    for (i = 1; i <= n; i ++) {
        clist.insert(i, i);
    }
    Josephus(clist, n, m);
}