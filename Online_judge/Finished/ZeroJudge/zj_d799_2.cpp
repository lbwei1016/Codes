//0-indexed
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 500000;

int N, Q;
int arr[MAX_N+1]; //儲存原數據

struct Node
{
    ll add = 0; //該節點的區間的所有元素皆加上的值
    ll sum = 0; //該節點的區間和，去除上述"add"的值
}node[(1 << 20)+1];

//一次修改給定區間的值
void add(int x, int y, int k, int v, int L, int R) //O(log n)
{
    if (x <= L && R <= y)
        node[v].add += k;
    else if (L < y && x < R) //有交集
    {
        node[v].sum += (min(y, R) - max(x, L)) * k; //只有交集之內的區間才加上要add的值

        int M = (L+R) / 2;
        add(x, y, k, 2*v+1, L, M);
        add(x, y, k, 2*v+2, M, R);
    }
}
//求區間和
ll sum(int x, int y, int v, int L, int R)
{
    if (y <= L || R <= x)
        return 0;
    else if (x <= L && R <= y)
        return node[v].add*(R-L) + node[v].sum; //整合
    else 
    {
        ll res = (min(y, R)-max(x, L)) * node[v].add; //讓子節點也加上add的值(只加交集的區間)

        int M = (L+R) / 2;
        res += sum(x, y, 2*v+1, L, M);
        res += sum(x, y, 2*v+2, M, R);
        return res;
    }
}
int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    int Q;
    scanf("%d", &Q);

    //樹的建構也可以用 add()
    for (int i=0; i<N; i++)
        add(i, i+1, arr[i], 0, 0, N);

    while (Q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1) //[x, y]所有值皆增加k
        {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            add(x-1, y, k, 0, 0, N);
        }
        else //query
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ll res = sum(x-1, y, 0, 0, N);
            printf("%lld\n", res);
        }
    }
    return 0;
}