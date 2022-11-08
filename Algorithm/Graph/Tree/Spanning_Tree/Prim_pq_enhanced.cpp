/*
    Prim's algorithm: (Greedy)
        Find the Minimum Spanning Tree(MST), 
        through the selections of the nearest vertex to the "current tree".
    O(E * logV)

    note: Prim's is similar to Dijkstra's, with some notable differences:
        1. Dijkstra's searches for the nearest vertex to the previous "vertex", while
           Prim's searches for the nearest vertex to the "current tree(MST)".
        2. Dijkstra's chooses "a particular" vertex as the beginning of "one" "shortest path tree", while
           Prim's chooses "any" vertex as the root of the only "MST(s)".(sometimes MST is not unique)
        3. Dijkstra's "cannot" handle graph with "negative edges", while
           Prim's "can".
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_V 100
#define INF 1e9

typedef pair<int, int> pii;
struct edge
{
    int to, cost;
};
vector<edge> edges[MAX_V]; //MAX_E = MaX_V - 1 (tree's trait)
int mincost[MAX_V]; //minicost[u]: the minimun cost from current tree to u
int V;

// 這版本看起來有點問題
int prim()
{
    //first: mincost[v]; second: v
    //sorted by mincost[i] (first), and take the minimum one
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int res = 0;

    fill(mincost, mincost+V, INF);
    //choose "0" as the root of MST
    mincost[0] = 0;
    pq.push(pii(0, 0));

    while(!pq.empty())
    {
        pii p = pq.top(); pq.pop();
        res += p.first;
        int v = p.second;

        //edges[v].size() represents how many edges are adjacent to v
        for(int i=0; i<edges[i].size(); i++)
        {
            //edge[v][i]: the i-th edge adjacent to v
            edge e = edges[v][i];
            if(mincost[e.to] > e.cost) //e.cost: the cost of e(v, i)
            {
                mincost[e.to] = e.cost;
                // res += e.cost;
                pq.push(pii(mincost[e.to], e.to));
            }
        }
    }
}

int main()
{
    //input edges[], V
    int ans = prim();
    return 0;
}
/* Another version
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int V = 10005;
struct E { int to, w; };
int n, m, d[V];
vector<E> G[V];
bitset<V> visit;

int Prim(int n) {
    int res = 0, cnt = 0;
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push({d[1] = 0, 1});
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if(visit[v]) continue;
        visit[v] = 1;
        res += p.first;
        if(++cnt == n) return res;

        for(auto e : G[v]) {
            int u = e.to, w = e.w;
            if(visit[u]) continue;
            if(d[u] > w) {
                d[u] = w;
                pq.push({d[u], u});
            }
        }
    }
    return -1;
}

int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        if(n == 0) break;
        for(int i=1; i<=n; i++) G[i].clear();
        fill(d+1, d+n+1, 1e9);
        visit.reset();
        for(int i=0; i<m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        printf("%d\n", Prim(n));
    }
    return 0;
}
*/