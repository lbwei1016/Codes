#include <bits/stdc++.h>

using namespace std;

#define MAX_N 22

int N, M;
int par[MAX_N+2];
int root[MAX_N+2];
//int height[MAX_N+2];
int group[MAX_N+2];

void init()
{
    for(int i=0; i<N; i++)
    {
        par[i] = i;
        root[i] = i;
        //height[i] = 1;
        group[i] = 1;
    }
}
int find_root(int x)
{
    return x == par[x] ? x : find_root(par[x]);
}
// bool same(int x, int y)
// {
//     return find_root(x) == find_root(y);
// }
void unite(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    if(x == y)
    {
        group[x]++;
        group[y]++;
        return;
    }
    
    par[y] = x;
    // if(height[x] < height[y])
    // {
    //     par[x] = y;
    // }
    // else
    // {
    //     par[y] = x;
    //     if(height[x] == height[y])
    //         height[x]++;
    // }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    
    return 0;
}