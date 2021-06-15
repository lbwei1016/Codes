/*
    Kruskal's algorithm:
        Find the Minimum Spanning Tree(MST), 
        through the selections of the shortest paths connecting two 
        subtrees (MSS: Minimum Spanning Subtree) which do not share 
        the same root. (using Union-Find Tree)
    O(E * logV)
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_E 1000
#define MAX_V 1000
struct edge
{
    int u, v, cost;
};
bool operator<(const edge e1, const edge e2)
{
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int E, V;

//Union-Find Tree
int par[MAX_V], tree_rank[MAX_V];
void init();
int find_root(int);
bool same(int, int);
void unite(int, int);

int kruskal()
{
    //ascending
    sort(es, es+E);
    init();
    int res = 0;

    for(int i=0; i<E; i++)
    {
        edge e = es[i];
        if(!same(e.u, e.v))
        {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
int main()
{
    //input V, E, es[]
    int ans = kruskal();
    return 0;
}

void init()
{
    for(int i=0; i<V; i++)
    {
        par[i] = i;
        tree_rank[i] = 0;
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
    
    if(tree_rank[x] > tree_rank[y])
    {
        par[y] = x;
    }
    else
    {
        par[x] = y;
        if(tree_rank[x] == tree_rank[y])
            tree_rank[y]++;
    }
    
}