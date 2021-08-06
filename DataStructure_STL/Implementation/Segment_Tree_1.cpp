/*
    線段樹： (1-indexed)
        來由詳見演算法筆記（http://web.ntnu.edu.tw/~algo/Sequence2.html#3）

        作為二元樹結構，線段樹的每一節點儲存不斷被二分的區間：
        根結點包含整個區間，而葉節點則僅包含一個數值；能夠以 
        O(log n) 的複雜度查詢: （註：初始化為 O(n)）
            1. 任意給定區間的最大（小）值，即 RMQ(Range Minimum Query) 機制
            2. 任意給定區間的和
            3. 修改任意區間的最大（小）值、和（單點更新）
            （多點更新詳見 Segment_Tree_2）
        在實作上，若將線段樹建置為完全二元樹，後續操作將較方便；儲存方式可以單
        純使用陣列或搭配指標連結。
*/
#include <iostream>

using namespace std;

const int MAX_N = 1 << 17;
const int INF = 1e9;
int N, n; //n = 2^k >= N
int dat[MAX_N]; //一個區間
int node[2*MAX_N+1]; //dat 區間的線段樹

//方便取用子節點
int LC(int v) {return 2 * v;}
int RC(int v) {return 2 * v + 1;}

void init() //O(n)
{
    n = 1; //n = 2^k >= N
    while (n < N)
        n *= 2;
    for (int i=1; i<=2*n-1; i++)
        node[i] = INF; //求最小值時，初始化為INF；若求最大值則是(-INF)
}
void build(int v, int L, int R) //建構線段樹 O(n)
{
    if (L == R) //[L, R]
    {
        node[v] = dat[L];
        return;
    }

    int M = (L+R) / 2;
    build(LC(v), L, M);
    build(RC(v), M+1, R);

    node[v] = min(node[LC(v)], node[RC(v)]);
}
void update(int v, int val) //更新 dat[v] 的值為 val (單點更新) O(log n)
{
    v += n - 1; //從葉開始更新
    dat[v] = val;

    while (v > 0)
    {
        v /= 2; //溯回父節點
        dat[v] = min(dat[LC(v)], dat[RC(v)]);
    }
}
int query(int l, int r, int v, int L, int R) //查詢[l, r]的最小值 O(log n)
{
    if (l > R || r < L) return INF;
    if (L <= l && r <= R) return dat[v];
    else 
    {
        int M = (L+R) / 2;
        if (r < L)
            return query(l, r, LC(v), L, M);
        else if (l > M)
            return query(l, r, RC(v), M+1, R);
        else
        {
            int s1 = query(l, r, LC(v), L, M);
            int s2 = query(l, r, RC(v), M+1, R);

            return min(s1, s2);
        }
    }
}
int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> dat[i];
    init();
    build(1, 1, N);
    update(3, 23);

    int l, r;
    cin >> l >> r;
    query(l, r, 1, 1, N);
    return 0;
}