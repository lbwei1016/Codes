/*
***Maximum Spanning Tree(same as Min ST)***
*/
#include <iostream>
#include <algorithm>
#include <cstdio> //poj is too old to use ios_base::sync.....

using namespace std;

#define MAX_R 50001
#define MAX_N 10001

struct edge
{
    int x, y, d;
}es[MAX_R];

int N, M, R;
int par[2 * MAX_N], height[2 * MAX_N];

int kruskal();
void init();
int find_root(int);
bool same(int, int);
void unite(int, int);

bool operator<(const edge &e1, const edge &e2)
{
    return e1.d < e2.d;
}
int main()
{
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        scanf("%d%d%d", &N, &M, &R);
        for(int i=0; i<R; i++)
        {
            int x, y, d;
            scanf("%d%d%d", &x, &y, &d);
            
            /*
                Note:
                    1. girls and boys are numbered sequentially:
                       girls: 0 ~ N-1; boys: N ~ M-1
                    2. We are searching for "Maximum" Spanning Tree, so 
                       d is tramsformed into "-d"
            */
            es[i] = (edge){x, N + y, -d}; 
        }
        int ans = 10000 * (N+M) + kruskal();
        printf("%d\n", ans);
    }
    return 0;
}
int kruskal()
{
    //"sort" for ascending sequence
    sort(es, es+R);
    init();
    int res = 0;

    for(int i=0; i<R; i++)
    {
        edge e = es[i];
        if(!same(e.x, e.y))
        {
            unite(e.x, e.y);
            res += e.d;
        }
    }
    return res; //res < 0
}
void init()
{
    int V = N + M;
    for(int i=0; i<V; i++)
    {
        par[i] = i;
        height[i] = 0;
    }
}
int find_root(int x)
{
    return x == par[x] ? x : find_root(par[x]);
}
bool same(int x, int y)
{
    return find_root(x) == find_root(y);
}
void unite(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    if(x == y)
        return;
    if(height[x] < height[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if(height[x] == height[y])
            height[x]++;
    }
}